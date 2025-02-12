#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int n, m, x;
vector<vector<pair<int, int>>> graph; // 인접 리스트로 방향 엣지와 가중치를 나타냄
vector<int> dist;                    // 출발 노드에서 도착 노드까지 최단 거리를 기록하는 벡터

void input()
{
    cin >> n >> m >> x;
    graph.resize(n + 1);
    dist.resize(n + 1, INT_MAX);

    int start, target, weight;
    for (int i = 0; i < m; i++)
    {
        cin >> start >> target >> weight;
        graph[start].push_back({target, weight});
    }
}

// 최단거리 구하기 위한 다익스트라 알고리즘
void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[start] = 0;    // 시작 정점 거리 0으로 초기화
    pq.push({0, start});

    while (!pq.empty())
    {
        int current_dist = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (current_dist > dist[current])
            continue;

        for (auto &edge : graph[current])
        {
            int next = edge.first;
            int weight = edge.second;
            if (dist[next] > dist[current] + weight)
            {
                dist[next] = dist[current] + weight;
                pq.push({dist[next], next});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    vector<int> dist_from_x(n + 1);
    dijkstra(x);
    for (int i = 1; i <= n; i++)
    {
        dist_from_x[i] = dist[i];
    }

    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == x)
            continue;

        dijkstra(i);
        answer = max(answer, dist[x] + dist_from_x[i]);
    }

    cout << answer << "\n";

    return EXIT_SUCCESS;
}