#include <iostream>
#include <vector>

namespace dynamicprogramming
{
    using namespace std;

    class Dijkstra
    {
    private:
        int n, m, x;
        vector<vector<int>> graph;
        vector<int> dist;
        vector<bool> visited;

    public:
        Dijkstra() = default;
        ~Dijkstra() = default;
        inline void input()
        {
            cin >> n >> m >> x;
            graph.resize(n + 1, vector<int>(n + 1));
            dist.resize(n + 1);
            visited.resize(n + 1);

            int start, target, weight;
            for (int i = 0; i < m; i++)
            {
                cin >> start >> target >> weight;
                graph[start][target] = weight;
            }

            return;
        }
        void solve(const int start)
        {
            fill(dist.begin(), dist.end(), INT32_MAX);
            fill(visited.begin(), visited.end(), false);
            visited[start] = true;
            for (int i = 1; i <= n; i++)
                if (!graph[start][i])
                    dist[i] = graph[start][i];

            while (true)
            {
                int cur_w = INT32_MAX;
                int cur = 0;
                // 방문되지 않은 것 중 최소 선택
                for (int i = 1; i <= n; i++)
                    if (!visited[i] && dist[i] > 0 && dist[i] < cur_w)
                        cur = i;

                if (cur == 0)
                    break;

                // 해당에서 시작 경로 업데이트 반복
                for (int i = 1; i <= n; i++)
                    if (graph[cur][i] != 0)
                        dist[i] = min(dist[i], dist[cur] + graph[cur][i]);
            }
        }
        vector<int> get_dist()
        {
            return this->dist;
        }
        int get_n()
        {
            return this->n;
        }
        int get_x()
        {
            return this->x;
        }
    };
}

using namespace dynamicprogramming;

int main()
{
    Dijkstra *s = new Dijkstra();
    s->input();
    int n = s->get_n();
    int x = s->get_x();
    vector<vector<int>> graph_min(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        s->solve(i);
        vector<int> tmp = s->get_dist();
        for (int j = 1; j <= n; j++)
            graph_min[i][j] = tmp[j];
    }

    int answer = INT32_MIN;
    for (int i = 1; i <= n; i++)
    {

        int tmp = 0;
        tmp = graph_min[i][x] + graph_min[x][i];
        answer = max(answer, tmp);
    }

    cout << answer << endl;

    delete s;

    return EXIT_SUCCESS;
}