#include <iostream>
#include <vector>
#include <cstring>

#define endl '\n'
#define PROCESSOR 1
#define EMPTY 0

using namespace std;
using PII = pair<int, int>;

int n;
int max_proc_num, min_line_num, edge_proc_num;
int board[12][12];
bool visited[12][12];
vector<PII> processor_pos;

constexpr int dr[] = {0, 1, 0, -1};
constexpr int dc[] = {1, 0, -1, 0};

/**
 * @brief memory allocation & init
 * @return void
 */
inline void input()
{
    cin >> n;
    memset(board, 0, sizeof(board));
    memset(visited, false, sizeof(visited));
    processor_pos.clear();


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == PROCESSOR)
            {
                if(i == 0 || i == n - 1 || j == 0 || j == n - 1)
                {
                    edge_proc_num++;
                    continue;
                }
                processor_pos.push_back({i, j});
            }
        }
    }

    return;
}

/**
 * @brief backtracking
 * @param cur_proc current processor index
 * @param cur_proc_num the number of processros which are included
 * @param cur_line_num the number of lines which are included
 * @return void
 */
void permutation(const int cur_proc, const int cur_proc_num, const int cur_line_num)
{
    if (cur_proc == processor_pos.size())
    {
        if (cur_proc_num > max_proc_num)
        {
            max_proc_num = cur_proc_num;
            min_line_num = cur_line_num;
        }
        else if (cur_proc_num == max_proc_num)
        {
            min_line_num = min_line_num < cur_line_num ? min_line_num : cur_line_num;
        }

        return;
    }

    int cr = processor_pos[cur_proc].first;
    int cc = processor_pos[cur_proc].second;
    for (int i = 0; i < 4; i++)
    {
        int nr = cr;
        int nc = cc;
        int cnt = 0;

        while (true)
        {
            nr += dr[i];
            nc += dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                break;
            else if (board[nr][nc] == PROCESSOR || visited[nr][nc])
            {
                cnt = -1;
                break;
            }
            cnt++;
        }

        if (cnt >= 0)
        {
            nr = cr;
            nc = cc;
            for (int j = 0; j < cnt; j++)
            {
                nr += dr[i];
                nc += dc[i];
                visited[nr][nc] = true;
            }
            permutation(cur_proc + 1, cur_proc_num + 1, cur_line_num + cnt);
            nr = cr;
            nc = cc;
            for (int j = 0; j < cnt; j++)
            {
                nr += dr[i];
                nc += dc[i];
                visited[nr][nc] = false;
            }
        }
    }
    permutation(cur_proc + 1, cur_proc_num, cur_line_num);

    return;
}

int solve()
{
    int ans = 0;

    max_proc_num = -1;
    min_line_num = INT32_MAX;
    edge_proc_num = 0;
    input();
    permutation(0, 0, 0);
    ans = min_line_num;

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt;
    cin >> cnt;
    int idx = 0;
    while (idx++ < cnt)
    {
        int answer = solve();
        cout << "#" << idx << " " << answer << endl;
    }

    return 0;
}