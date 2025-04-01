#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
using PII = pair<int, int>;

int n, k;
int board[8][8];
bool visited[8][8];
int g_ans;
vector<PII> start;

constexpr int dr[] = {-1, 1, 0, 0};
constexpr int dc[] = {0, 0, -1, 1};

inline void input()
{
    cin >> n >> k;

    int max_height = INT32_MIN;
    start.clear();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] > max_height)
                max_height = board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == max_height)
                start.push_back({i, j});

    return;
}

void dfs(const int r, const int c, const int cnt)
{
    g_ans = max(g_ans, cnt);

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= n)
            continue;

        if (board[nr][nc] >= board[r][c])
            continue;
        
        if(visited[nr][nc])
            continue;

        visited[nr][nc] = true;
        dfs(nr, nc, cnt + 1);
        visited[nr][nc] = false;
    }

    return;
}

void solve()
{
    input();
    g_ans = INT32_MIN;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp = board[i][j];
            for (int m = 0; m < k; m++)
            {
                board[i][j]--;
                for (const auto &pi : start){
                    visited[pi.first][pi.second] = true;
                    dfs(pi.first, pi.second, 1);
                    visited[pi.first][pi.second] = false;
                }
            }
            board[i][j] = tmp;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int idx = 0;
    while(idx++ < t){
    solve();
    cout << "#" << idx << " " << g_ans << '\n';
    }

    return 0;
}