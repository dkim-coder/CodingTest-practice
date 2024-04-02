#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <algorithm>

using namespace std;

int cnt_max;

int bfs(int n, vector<vector<int>> edge)
{
    int answer = 0;
    unordered_set<int> us;  // 결과 노드 저장 하기 위함
    queue<pair<int, int>> q;    // 첫번째는 현재 노드, 두번째는 현재까지의 cnt 값
    vector<bool> visit(n + 1, false);   // 방문 여부를 체크하기 위함
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));  // 그래프로 보기 위함
    for (int i = 0; i < edge.size(); i++)
    {
        graph[edge[i][0]][edge[i][1]] = true;
        graph[edge[i][1]][edge[i][0]] = true;
    }

    cnt_max;
    q.push({1, 0}); // 시작노드 처음 cnt -
    visit[1] = true;
    while (!q.empty())
    {
        int c_node = q.front().first;
        int c_cnt = q.front().second;
        if (c_cnt == cnt_max)
        {
            us.insert(c_node);
        }
        else if (c_cnt > cnt_max)
        {
            cnt_max = c_cnt;
            us.clear();
            us.insert(c_node);
        }

        q.pop();

        for (int i = 0; i < graph[c_node].size(); i++)
        {
            if (!graph[c_node][i])
                continue;
            if (visit[i])
                continue;

            q.push({i, c_cnt + 1});
            visit[i] = true;
        }
    }

    answer = us.size();

    return answer;
}

int main()
{
    int n = 6;
    vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};

    cout << "Answer_BFS : " << bfs(n, edge) << endl;

    return EXIT_SUCCESS;
}