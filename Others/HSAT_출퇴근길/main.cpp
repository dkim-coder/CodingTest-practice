#include <iostream>
#include <vector>

using namespace std;

vector<int> v1[100001];
vector<int> v2[100001];
bool visited1[100001];
bool visited2[100001];
bool visited3[100001];
bool visited4[100001];

// 1. 순방향 그래프에서 S 출발 시 방문 가능 노드
// 2. 순방향 그래프에서 T 출발 시 방문 가능 노드
// 3. 역방향 그래프에서 S 출발 시 방문 가능 노드 -> 즉, 원래 그래프에서 S에 도달할 수 있는 출발 노드들을 의미
// 4. 역방향 그래프에서 T 출발 시 방문 가능 노드 -> 즉, 원래 그래프에서 T에 도달할 수 있는 출발 노드들을 의미

/*
NOTE: 방향 그래프에서 특정 정점으로 도달가능한지 판단할 때 역방향 그래프를 만들어서 사용하는 테크닉이 많이 사용됨
*/

// DFS 그래프 탐색 : 시작 정점에서 도달할 수 있는 노드들을 visted 배열에 표시
void dfs(int cur, bool visited[], vector<int> v[])
{
    if (visited[cur])   // 이미 방문한 노드는 스킵
        return;
    visited[cur] = true;
    for (auto next : v[cur])
    {
        dfs(next, visited, v);
    }
}
int main(int argc, char **argv)
{
    // 입력 및 초기화 부분
    int n, m, x, y, s, e, answer = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        v1[x].push_back(y); // 순방향 그래프
        v2[y].push_back(x); // 역방향 그래프
    }
    cin >> s >> e;

    // 출근길에는 e를 1번만 방문, 퇴근길에는 s를 한번만 방문
    visited1[e] = true;
    visited2[s] = true;
    
    dfs(s, visited1, v1);   // s 출발 시 도달 가능 노드 방문 처리
    dfs(e, visited2, v1);   // e 출발 시 도달 가능 노드 방문 처리

    dfs(s, visited3, v2);   // s 에 도달 가능한 노드들 방문 처리
    dfs(e, visited4, v2);   // e 에 도달 가능한 노드들 방문 처리
    for (int i = 1; i <= n; i++)
    {
        if (visited1[i] && visited2[i] && visited3[i] && visited4[i])
            answer++;
    }
    cout << answer - 2 << '\n';
    
    return 0;
}