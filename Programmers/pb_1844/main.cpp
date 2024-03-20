#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(vector<vector<int>> maps, int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});    // 시작 노드 삽입
    while (!q.empty()) // 큐가 모두 빌 때가지 해야하는 것
    {
        // 큐 처음 원소 빼기
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) // 해당 노드의 인접한 노드 모두 탐색 큐에 넣어주는 것임
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size())
                continue;
            if (maps[nx][ny] == 0)
                continue;
            if (maps[nx][ny] == 1)
            {
                maps[nx][ny] = maps[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    if (maps[maps.size() - 1][maps[0].size() - 1] == 1)
        return -1;
    else
        return maps[maps.size() - 1][maps[0].size() - 1];
}

int dfs_1(vector<vector<int>> maps, int x, int y)
{
    stack<pair<int, int>> st;
    st.push({x, y});

    while (!st.empty())
    {
        int x = st.top().first;
        int y = st.top().second;
        st.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size())
                continue;
            if (maps[nx][ny] == 0)
                continue;
            if (maps[nx][ny] == 1)
            {
                st.push({nx, ny});
                maps[nx][ny] = maps[x][y] + 1;
            }
        }
    }

    if (maps[maps.size() - 1][maps[0].size() - 1] == 1)
        return -1;
    else
        return maps[maps.size() - 1][maps[0].size() - 1];
}

int main()
{
    // 1이 벽이 없는 자리
    vector<vector<int>> maps = {
        {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}}};

    cout << bfs(maps, 0, 0) << endl;
    cout << dfs_1(maps, 0, 0) << endl;

    return EXIT_SUCCESS;
}