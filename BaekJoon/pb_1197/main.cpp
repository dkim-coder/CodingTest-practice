/**
 * 프림 알고리즘
 * 최소 힙 사용
 * 1. 시작 노드는 아무거나 선택
 * 2. 간선들을 다 넣음
 * 3. 방문하지 않은 노드가 있다면 방문처리하고 그 정점과 연결된 간선들 또 주르륵 넣은
 * 4. 추가된 간선이 정점 - 1 개면 종료
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

static int V, E;
static vector<vector<pll>> graph;
static vector<bool> visited;

struct comp{
    bool operator()(const pll &a, const pll &b){
        return a.second > b.second;
    }
};

const ll solution(){
    ll res = 0;
    priority_queue<pll, vector<pll>, comp> pq;
    ll st_node = 1;
    visited[st_node] = true;
    for(const pll &i: graph[st_node])
        pq.push({i.first, i.second});

    ll edge_cnt = 0;
    pll tmp;    
    while(!pq.empty()){
        tmp = pq.top();
        pq.pop();
        ll node = tmp.first;
        ll weight = tmp.second;
        if(visited[node])
            continue;

        res += weight;
        visited[node] = true;
        if(++edge_cnt == V - 1)
            return res;

        for(const pll &i: graph[node])
            pq.push({i.first, i.second});
    }
    res = -1;

    return res;
}

int main(const int argc, const char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;
    // graph = vector<vector<pii>>(V + 1);
    graph.assign(V + 1, vector<pll>());
    visited.assign(V + 1, false);
    ll a, b, w;
    for(int i = 0; i < E; i++)
    {
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    const ll res = solution();
    cout << res << '\n';

    return 0;
}