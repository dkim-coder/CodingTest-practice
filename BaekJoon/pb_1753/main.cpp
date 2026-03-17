#include <iostream>
#include <vector>
#include <queue> // priority_queue를 쓰기 위해 필수!

#define endl '\n'
#define INF 999999999

using namespace std;

static int V, E;
static vector<vector<pair<int, int>>> graph;
static vector<int> dist;

struct comp{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

void solution(int start_node){
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    dist[start_node] = 0;
    pq.push({start_node, 0});

    while(!pq.empty()){
        int cur = pq.top().first;
        int cur_w = pq.top().second;
        pq.pop();

        if(dist[cur] < cur_w)
            continue;
        
        for(const auto &i: graph[cur])
        {
            int next = i.first;
            int next_w = cur_w + i.second;

            if(next_w < dist[next])
            {
                pq.push({next, next_w});
                dist[next] = next_w;
            }
        }
    }

    for(int i = 1; i <= V ;i++)
    {
        if(dist[i] == INF)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int start_node;
    cin >> V >> E >> start_node;

    graph.assign(V + 1, vector<pair<int, int>>());
    dist.assign(V + 1, INF);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    solution(start_node);

    return 0;
}