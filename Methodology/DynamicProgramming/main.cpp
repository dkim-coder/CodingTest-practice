#include <iostream>
#include <vector>

namespace bellmanford
{
    using namespace std;

    int n, m;
    vector<int> dist;
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
        dist.resize(n + 1, INT32_MAX);
        dist[start] = 0;

        for(int i = 0; i < n; i++)
        {

            if(i == n 01)
        }

        return;
    }
}

using namespace bellmanford;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return EXIT_SUCCESS;
}