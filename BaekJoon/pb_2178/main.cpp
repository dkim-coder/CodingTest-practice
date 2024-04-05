#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
1이 갈수 있는 경로
*/

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Node
{
    int x, y;
    int cnt;
};

int BFS(vector<vector<int>> maps)
{
    vector<vector<bool>> visit(maps.size(), vector<bool>(maps[0].size(), false));
    queue<Node> q;
    q.push({0, 0, 1});
    visit[0][0] = true;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        maps[x][y] = cnt;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size() || maps[nx][ny] == 0 || visit[nx][ny])
                continue;

            visit[nx][ny] = true;
            q.push({nx, ny, cnt + 1});
        }
    }

    return maps[maps.size() - 1][maps[0].size() - 1];
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> maps(N);

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            maps[i].push_back(str[j] - '0');
        }
    }
    
    cout << BFS(maps) << endl;

    return EXIT_SUCCESS;
}