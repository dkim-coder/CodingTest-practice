#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 99999999

using namespace std;
using pii = pair<int, int>;

static int N, M, X;
static vector<vector<pii>> graph;
static vector<vector<pii>> reverse_graph;
static vector<int> dist;
static vector<int> reverse_dist;

struct comp{
    bool operator()(const pii &a, const pii &b)
    {
        return a.second > b.second;
    }
};

void solution(vector<vector<pii>> &g, vector<int> &d)
{
    int res = 0;
    priority_queue<pii, vector<pii>, comp> pq;
    d.assign(N + 1, INF);
    pq.push({X, 0});
    d[X] = 0;

    while(!pq.empty())
    {
        int cur = pq.top().first;
        int cur_w = pq.top().second;
        pq.pop();

        if(cur_w > d[cur])
            continue;

        for(const auto& i : g[cur])
        {
            if(d[i.first] > cur_w + i.second){
                d[i.first] = cur_w + i.second;
                pq.push({i.first, cur_w + i.second});
            }
        }     
    }

    return;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> X;
    graph.assign(N + 1, vector<pii>());
    reverse_graph.assign(N + 1, vector<pii>());
    int a, b, w;
    for(int i = 0; i < M; i++)
    {
        cin >> a >> b >> w;
        graph[a].push_back({b, w}); // 정방향
        reverse_graph[b].push_back({a, w}); // 역방향
    }
    
    solution(graph, dist);  // 도착지까지 가는데 최단
    solution(reverse_graph, reverse_dist);  // 도착지에서 출발지 돌아가는데 최단

    int res = 0;
    for(int i = 1; i <= N; i++)
    {
        if(i !=X && dist[i] != INF && reverse_dist[i] != INF && res < dist[i] + reverse_dist[i])
        {
            res = dist[i] + reverse_dist[i];
        }
    }

    cout << res << '\n';

    return 0;
}