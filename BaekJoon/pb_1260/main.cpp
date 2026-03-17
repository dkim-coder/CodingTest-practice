#include <iostream>
#include <list>
#include <cstring>
#include <stack>
#include <queue>
#define endl '\n'

using namespace std;

static int N = 1'001;
static int M = 10'001;
static int V = 0;
static bool visited[1'001];
static list<int> graph[1'001];
static int answer[1'001];

// 입력
void input() {
    int a, b;
    
    for(int i = 0; i < N; i++)
        graph[i].clear();

    cin >> N >> M >> V;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    return;
}

// recursive dfs
void dfs(const int &cur, const int &depth){
    if(visited[cur])
        return;

    visited[cur] = true;
    answer[depth] = cur;

    for(const auto &next : graph[cur])
        dfs(next, depth + 1);

    return;
}

void bfs(){
    int depth = 1;
    queue<int> q;
    q.push(V);
    
    fill(visited, visited + N + 1, false);
    visited[V] = true;
    answer[depth] = V;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(const auto &next : graph[cur]){
            if(visited[next])
                continue;

            visited[next] = true;
            q.push(next);
            answer[++depth] = next;
        }
    }

    return;
}

int main(int argc, char** argv) {
    input();

    dfs(V, 1);
    for(int i = 1; i <= N; i++)
        cout << answer[i] << ' ';
    cout << endl;

    bfs();
    for(int i = 1; i <= N; i++)
        cout << answer[i] << ' ';

    return 0;
}