#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

// 여러 방법 -> 전선 길이 최소
namespace my
{
#define LINE 2
#define PROCESSOR 1
#define EMPTY 0

    using namespace std;
    using PII = pair<int, int>;

    int n;
    int max_proc_num, max_line_num;
    vector<vector<int>> board;
    vector<PII> processor_pos;

    constexpr int dr[] = {0, 1, 0, -1};
    constexpr int dc[] = {1, 0, -1, 0};
    bool flag;

    inline void input()
    {
        cin >> n;
        board.resize(n, vector<int>(n));
        processor_pos.clear();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> board[i][j];
                if (board[i][j] == PROCESSOR)
                {
                    processor_pos.push_back({i, j});
                }
            }
        }

        return;
    }

    vector<PII> go(const int cr, const int cc, const int direct)
    {
        vector<PII> v;

        int nr = cr + dr[direct];
        int nc = cc + dc[direct];

        if (nr < 0 || nr >= n || nc < 0 || nc >= n)
        {
            flag = true;
            return v;
        }

        v.push_back({nr, nc});
        while (true)
        {
            nr += dr[direct];
            nc += dc[direct];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n)
            {
                flag = true;
                return v;
            }

            if (board[nr][nc] == PROCESSOR || board[nr][nc] == LINE)
            {
                v.clear();
                return v;
            }
            v.push_back({nr, nc});
        }
    }

    void permutation(const int cur_proc, const int cur_proc_num, const int cur_line_num)
    {
        if (cur_proc == processor_pos.size())
        {
            if (cur_proc_num > max_proc_num)
            {
                max_proc_num = cur_proc_num;
                max_line_num = cur_line_num;
            }
            else if (cur_proc_num == max_proc_num && cur_line_num < max_line_num)
            {
                max_line_num = cur_line_num;
            }

            return;
        }

        int cr = processor_pos[cur_proc].first;
        int cc = processor_pos[cur_proc].second;
        for (int i = 0; i < 4; i++)
        {
            flag = false;
            vector<PII> v = go(cr, cc, i);
            if (flag)
            {
                for (const auto ch : v)
                    board[ch.first][ch.second] = LINE;
                permutation(cur_proc + 1, cur_proc_num + 1, cur_line_num + v.size());
            }
            else
                permutation(cur_proc + 1, cur_proc_num, cur_line_num);

            for (const auto ch : v)
                board[ch.first][ch.second] = EMPTY;
        }

        return;
    }

    int solve()
    {
        int ans = 0;

        input();
        max_proc_num = -1;
        max_line_num = INT_MAX;
        permutation(0, 0, 0);
        ans = max_line_num;

        return ans;
    }
}

using namespace my;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve() << endl;

    return EXIT_SUCCESS;
}