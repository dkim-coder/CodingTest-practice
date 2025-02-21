#include <iostream>
#include <vector>

using namespace std;

int N, M;                  // N: 노드의 개수, M: 간선의 개수
vector<vector<int>> graph; // 인접리스트로 그래프 표현
vector<bool> visited;      // 방문 여부 저장

/**
 * @brief 입력을 받는 함수
 *
 * @details 노드의 개수(N)와 간선의 개수(N)를 입력받고 인접리스트로 그래프를 표현
 * 노드는 1번 노드부터 시작한다
 * 무방향 그래프이다
 * @return void
 */
inline void input()
{
    cin >> N >> M;
    graph.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    return;
}

/**
 * @brief 그래프 탐색
 *
 * @param past 이전 방문 노드
 * @param cur 현재 방문 노드
 * @param cnt 현재 방문하는 노드가 속한 집합의 노드 개수
 * @param flag 사이클이 존재하는지 여부 (false  : 사이클이 존재, ture : 사이클이 존재하지 않음)
 */
void dfs(const int past, const int cur, int &cnt, bool &flag)
{
    if (visited[cur])
        return;
    visited[cur] = true;
    cnt++;

    for (int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i];
        if (past == next)   // 다음 노드가 이전 노드라면 패스
            continue;

        if (visited[next])  // 다음 노드가 이미 방문한 노드라면 사이클 존재하는 것
        {
            flag = false;
            continue;
        }

        dfs(cur, next, cnt, flag);
    }

    return;
}

/**
 * @brief 독립적으로 존재하는 최대 정점 개수 구하기
 *
 * @return const int
 */
const int solution()
{
    int answer = 0;
    input();
    visited.resize(N + 1, false);

    for (int i = 1; i <= N; i++)
    {
        if (visited[i])
            continue;
        int cnt = 0;
        bool flag = true;
        dfs(-1, i, cnt, flag);
        if (!flag || !(cnt % 2))
            answer += cnt / 2;
        else
            answer += cnt / 2 + 1;
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solution() << "\n";

    return 0;
}