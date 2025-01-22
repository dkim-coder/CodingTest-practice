#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

// 8방향
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

bool valid(const vector<vector<char>>& board, int r, int c)
{
    for(int i = 0; i < 8; ++i)
    {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if(nr < 0 || nr >= board.size() || nc < 0 || nc >= board.size())
            continue;
        if(board[nr][nc] == 'G')
            return false;
    }

    return true;
}

int rNum(const vector<vector<char>> &board, int r, int c)
{
    int ans = 1;

    // 상
    for(int i = c - 1; i >= 0; --i)
    {
        if(board[r][i] == 'B')
            ans++;
        else
            break;
    }
    // 하
    for(int i = c + 1; i < board.size(); ++i)
    {
        if(board[r][i] == 'B')
            ans++;
        else
            break;
    }
    // 좌
    for(int i = r - 1; i >= 0; --i)
    {
        if(board[i][c] == 'B')
            ans++;
        else
            break;
    }
    // 우
    for(int i = r + 1; i < board.size(); ++i)
    {
        if(board[i][c] == 'B')
            ans++;
        else
            break;
    }

    return ans;
}

int main()
{
    int n;
    vector<int> ans;

    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int tmp = 2;
        int size;
        cin >> size;
        vector<vector<char>> board(size, vector<char>(size, 0));
        for(int j = 0; j < size; ++j)
            for(int k = 0; k < size; ++k)
                cin >> board[j][k];

        for(int j = 0; j < size; ++j)
        {
            for(int k = 0; k < size; ++k)
            {
                if(board[j][k] == 'B' && valid(board, j, k))
                {
                    tmp = tmp < rNum(board, j, k) ? rNum(board, j, k) : tmp;
                }
            }
        }
        ans.push_back(tmp);
    }

    for(int i = 0; i < ans.size(); ++i)
        cout << "#" << i + 1 << " " << ans[i] << endl;
    return 0;
}