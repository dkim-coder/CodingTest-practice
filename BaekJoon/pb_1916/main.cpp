#include <iostream>
#include <vector>
#include <queue>

#define INF 99999999

using namespace std;
using PII = pair<int, int>;

int n, m;
int st, dest;
vector<int> dist;
vector<vector<PII>> graph;

inline void input()
{   
    cin >> n;
    cin >> m;
    graph.resize(n + 1);
    int start, end, weight;
    for(int i = 0; i < m; i++)
    {
        cin >> start >> end >> weight;
        graph[start].push_back(make_pair(end, weight));
    }
    cin >> st >> dest;

    return;
}

struct comp{
    bool operator()(const PII &a, const PII &b)
    {
        return a.second > b.second;
    }
};

// 다익스트라는 방문되지 않은 정점들중 가장 최소 거리 값을 가지는 정점을 선택해 최소 거리를 업데이트 하는 방식임. -> 최소거리는 최소거리만으로 이동한 집합 이기 때문임.
void dijkstra(int start)
{
    dist.resize(n + 1, INF);
    dist[start] = 0;
    priority_queue<PII, vector<PII>, comp> pq;  // 현재 방문되지 않은 정점들 중 가장 최소 가중치를 가지는 엣지를 선택하기 위해 힙 사용
    pq.push(make_pair(start, dist[start]));

    while(!pq.empty())
    {
        int cur = pq.top().first;
        int weight = pq.top().second;
        pq.pop();

        if(weight > dist[cur])  // 최소 힙에서 꺼낸 노드가 최소 거리를 가지지 않는다면 무시한다는 뜻
            continue;

        for(const auto &i : graph[cur])     // 방문된 노드에서 최단 경로를 업데이트하는데 더 작은 경우에만 추가
        {
            if(dist[i.first] > dist[cur] + i.second)
            {
                dist[i.first] = dist[cur] + i.second;
                pq.push(make_pair(i.first, dist[i.first]));
            }
        }
    }

    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    dijkstra(st);
    cout << dist[dest] << "\n";

    return 0;
}