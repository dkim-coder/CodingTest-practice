#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<bool> visited;
int ans;

inline int man_dist(const int &cr, const int &cc, const int &nr, const int &nc)
{
    int ans = 0;

    ans += (cr - nr) > 0 ? (cr - nr) : (nr - cr);
    ans += (cc - nc) > 0 ? (cc - nc) : (nc - cc);

    return ans;
}

void dfs(const int cnt, const int idx, const vector<vector<int>> &dist)
{
    if (cnt == k)
    {
        int max_dist = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i]) // 대피소 아닌곳
            {
                int tmp = INT32_MAX;
                for (int j = 0; j < n; j++)
                {
                    if (visited[j])    // 대피소 인곳
                    {
                        tmp = min(tmp, dist[i][j]);
                    }
                }
                max_dist = max(max_dist, tmp);
            }
        }
        
        ans = min(ans, max_dist);
        
        return;
    }

    for (int i = idx; i < n; i++)
    {
        visited[i] = true;
        dfs(cnt + 1, i + 1, dist);
        visited[i] = false;
    }

    return;
}

void solution()
{
    cin >> n >> k;

    vector<pair<int, int>> houses(n);
    vector<vector<int>> dist(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        cin >> houses[i].first >> houses[i].second;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = man_dist(houses[i].first, houses[i].second, houses[j].first, houses[j].second);

    visited.resize(n, false);
    ans = INT32_MAX;
    dfs(0, 0, dist);
    cout << ans << "\n";

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();

    return 0;
}