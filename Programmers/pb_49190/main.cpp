#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

map<pair<int, int>, bool> visited;  // 그래프로 표시하는데 모든 좌표를 표시할 필요하 없을 경우 map을 해서 방문 처리 체크 가능
map<pair<pair<int, int>, pair<int, int>>, bool> edge; // 시작 정점과 끝 정점표시를 통해 방문 체크 가능
// 도형의 경우 사이클 --> 사이클의 경우 방문했던 점 다시 돌아오면 사이클을 형성 하는것으로 볼 수 있음

int solution(vector<int> arrows)
{
    int res = 0;
    pair<int, int> cur = {0, 0};    // 시작 좌표
    visited[cur] = true;    // 시작 좌표 방문 처리
    for (int a : arrows)
    {
        for (int i = 0; i < 2; i++)     // 그래프 도형의 크기를 두배로 늘려서 품 --> 모래시계 모양 같은 경우를 처리하기 위함
        {
            pair<int, int> next = {cur.first + dy[a], cur.second + dx[a]};  // 다음 좌표
            if (!edge[{cur, next}] && !edge[{next, cur}])   // 간선의 경우 양방향 체크 필요함 --> 현재 간선이 방문하지 않은 경우
            {
                if (visited[next])  // 이미 방문한 정점이라면
                    res++;
            }
            visited[next] = true;
            edge[{cur, next}] = true;
            cur = next;
        }
    }

    return res;
}

int main()
{
    vector<int> arrows = {6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0};

    cout << solution(arrows) << endl;

    return EXIT_SUCCESS;
}