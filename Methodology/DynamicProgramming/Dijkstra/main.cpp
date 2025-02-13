#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int n, m, x;
vector<vector<pair<int, int>>> graph; // 인접리스트 사용, < 연결 노드, 가중치 >
vector<int> dist;                    // 출발 노드에서 도착 노드까지 최단 거리를 기록하는 벡터

void input()
{
    cin >> n >> m >> x;
    graph.resize(n + 1);
    dist.resize(n + 1);

    int start, target, weight;
    for (int i = 0; i < m; i++)
    {
        cin >> start >> target >> weight;
        graph[start].push_back({target, weight});
    }
}

// 다익스트라 알고리즘: 최단거리 구하는 알고리즘으로 그리디와 다이나믹 프로그래밍을 결합
// 그리디 요소: 방문되지 않은 노드중에서 현재까지 이동 가중치가 가장 낮은 노드를 선택
//  - 즉, 최단 거리를 구하기 위해서는 지속적으로 최단 경로로 이동한다는 개념을 기반함
// 다이나믹 프로그래밍 요소: 다음 노드까지의 최단 거리를 계산할때 이전에 계산했던 값을 사용해서 업데이트 하기 때문
void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[start] = 0;    // 시작 정점 거리 0으로 초기화
    pq.push({0, start});    // {노드까지의 최단 거리 값, 노드}

    while (!pq.empty())
    {
        int current_dist = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (current_dist > dist[current])   // 최소 힙에서 꺼낸 정점이 최소 거리를 가지는 정점이 아니라면 무시한다는 뜻
            continue;

        for (auto &edge : graph[current])
        {
            int next = edge.first;
            int weight = edge.second;
            if (dist[next] > dist[current] + weight)    // 다음 노드의 최단 거리 값이 현재 노드를 거쳐서 가는 것보다 크면 업데이트 후 힙에 삽입
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