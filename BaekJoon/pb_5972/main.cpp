#include <iostream>
#include <queue>
#include <vector>

#define INF 99999999

using namespace std;
using pii = pair<int, int>;

static int N, M;
static vector<vector<pii>> graph;
static vector<int> dist;

struct comp{
    bool operator()(const pii &a, const pii &b){
        return a.second > b.second;
    }
};

void solution(){
    priority_queue<pii, vector<pii>, comp> pq;
    pq.push({1, 0});
    dist[1] = 0;

    while(!pq.empty())
    {
        int cur = pq.top().first;
        int cur_w = pq.top().second;
        pq.pop();

        if(cur_w > dist[cur])
            continue;
        
        for(const auto &i: graph[cur])
        {
            if(cur_w + i.second < dist[i.first]){
                dist[i.first] = cur_w + i.second;
                pq.push({i.first, cur_w + i.second});
            }
        }
    }

    cout << dist[N] << endl;

    return;
}

int main(int argc, char *argv[])
{
    cin >> N >> M;
    graph.resize(N + 1);
    dist.assign(N + 1, INF);

    int a, b, w;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    solution();

    return 0;
}