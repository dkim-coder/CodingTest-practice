#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

int n, m, t;
bool graph[501][501];
bool visited[501];

inline void input()
{
    memset(graph, false, sizeof(graph));
    cin >> n;
    cin >> m;

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a][b] = true;
    }

    return;
}

int solve()
{
    int ans = 0;

    input();
    for (int i = 1; i <= n; i++)
    {
        memset(visited, false, sizeof(visited));
        stack<int> st;
        st.push(i);
        visited[i] = true;
        int cnt = 1;
        // 나가는 거
        while (!st.empty())
        {
            int cur = st.top();
            st.pop();

            for (int j = 1; j <= n; j++)
            {
                if (graph[cur][j] && !visited[j])
                {
                    visited[j] = true;
                    cnt++;
                    st.push(j);
                }
            }
        }
        // 들어오는 거
        st.push(i);
        while (!st.empty())
        {
            int cur = st.top();
            st.pop();

            for (int j = 1; j <= n; j++)
            {
                if (graph[j][cur] && !visited[j])
                {
                    visited[j] = true;
                    cnt++;
                    st.push(j);
                }
            }
        }

        if (cnt == n)
            ans++;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    int idx = 0;
    while (idx++ < t)
    {
        cout << "#" << idx << " " << solve() << '\n';
    }

    return 0;
}