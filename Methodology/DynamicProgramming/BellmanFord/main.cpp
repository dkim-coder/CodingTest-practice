#include <iostream>
#include <vector>
#include <algorithm>

#define INF 9999999999

namespace bellmanford
{
    using namespace std;

    int n, m;
    vector<long long> dist;
    vector<pair<pair<int, int>, int>> edges;

    inline void input()
    {
        cin >> n >> m;
        int start, dest, weight;
        for (int i = 0; i < m; i++)
        {
            cin >> start >> dest >> weight;
            edges.push_back(make_pair(make_pair(start, dest), weight));
        }

        return;
    }

    bool solve(int start)
    {
        dist.resize(n + 1, INF);
        dist[start] = 0;
        int node1, node2, weight;
        for (int i = 0; i < n; i++) // n - 1 번의 싸이클만 수행하면 모든 것이 파악 가능하지만, 마지막에 업데이트 되면 음의 값이 되는 사이클이 존재한다는 것이기 때문에 사용
        {
            for (int j = 0; j < edges.size(); j++)
            {
                node1 = edges[j].first.first;
                node2 = edges[j].first.second;
                weight = edges[j].second;
                if (dist[node1] != INF && dist[node2] > dist[node1] + weight)
                {
                    dist[node2] = dist[node1] + weight;
                    if (i == n - 1)
                        return false;
                }
            }
        }

        return true; // 정상 수행
    }
}

using namespace bellmanford;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    bool flag = solve(1);
    if (!flag)
        cout << -1 << "\n";
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (dist[i] == INF)
                cout << -1 << "\n";
            else
                cout << dist[i] << "\n";
        }
    }

    return EXIT_SUCCESS;
}