#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector<vector<char>> matrix; // 그래프
// unordered_set<char> us;      // 세트
vector<vector<bool>> check; // 방문 여부 체크
vector<bool> cc(30, false);
int res = 0;
int tmp_cnt = 1;

void dfs(int x, int y)
{
    // if (res < us.size())
    //     res = us.size();

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= matrix.size() || ny < 0 || ny >= matrix[0].size())
            continue;
        if (check[nx][ny])
            continue;
        // if (us.find(matrix[nx][ny]) != us.end())
        //     continue;
        if (cc[matrix[nx][ny] - 'A'])
            continue;
        cc[matrix[nx][ny] - 'A'] = true;
        // us.insert(matrix[nx][ny]);
        check[nx][ny] = true;
        tmp_cnt++;
        if (tmp_cnt > res)
            res = tmp_cnt;
        dfs(nx, ny);
        cc[matrix[nx][ny] - 'A'] = false;
        // us.erase(matrix[nx][ny]);
        check[nx][ny] = false;
        tmp_cnt--;
    }

    return;
}

int main()
{
    int r, c;
    cin >> r >> c; // row, column
    for (int i = 0; i < r; i++)
    {
        vector<char> tmp_v;
        for (int j = 0; j < c; j++)
        {
            char tmp;
            cin >> tmp;
            tmp_v.push_back(tmp);
        }
        matrix.push_back(tmp_v);
        check.push_back(vector<bool>(c, false));
    }

    // us.insert(matrix[0][0]);
    cc[matrix[0][0] - 'A'] = true;
    check[0][0] = true;

    if (r > 1 && c > 1)
    {
        if (matrix[0][0] == matrix[0][1] && matrix[0][0] == matrix[1][0])
        {
            cout << 1 << endl;
            return 0;
        }
    }
    else if (r > 1 && c == 1)
    {
        if (matrix[0][0] == matrix[1][0])
        {
            cout << 1 << endl;
            return 0;
        }
    }
    else if (r == 1 && c > 1)
    {
        if (matrix[0][0] == matrix[0][1])
        {
            cout << 1 << endl;
            return 0;
        }
    }
    else if (r == 1 && c == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    dfs(0, 0);

    cout << res << endl;

    return EXIT_SUCCESS;
}