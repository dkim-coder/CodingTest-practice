
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
문제 핵심 요약
- 간선을 제외한 모든 것을 0 으로 치환시킴 -> 1만 따라서 가면 찾을 수 있음
- 붙어있는 경우를 해결하기 위해 2배의 사이즈로 키워서 해결함
*/

vector<vector<bool>> graph(102, vector(102, false));
vector<vector<bool>> g_visit(102, vector(102, false));
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Pos
{
    int x;
    int y;
    int dis;
};

void initGraph(vector<vector<int>> rectangle)
{
    // 직사각형을 true 으로 만듬
    for (int i = 0; i < rectangle.size(); i++)
    {
        for (int j = 0; j < rectangle[i].size(); j++)
            rectangle[i][j] *= 2;

        for (int j = rectangle[i][0]; j <= rectangle[i][2]; j++)
        {
            for (int k = rectangle[i][1]; k <= rectangle[i][3]; k++)
                graph[j][k] = true;
        }
    }

    // 직사각형 내부를 0 으로 만듬
    for (int i = 0; i < rectangle.size(); i++)
    {
        for (int j = rectangle[i][0] + 1; j < rectangle[i][2]; j++)
        {
            for (int k = rectangle[i][1] + 1; k < rectangle[i][3]; k++)
                graph[j][k] = false;
        }
    }

    return;
}

int bfs(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    int answer = 0;
    queue<Pos> q;

    initGraph(rectangle); // 그래프 초기화

    q.push({characterX * 2, characterY * 2, 0});
    g_visit[characterX * 2][characterY * 2] = true;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int dis = q.front().dis;
        q.pop();

        if (x == itemX * 2 && y == itemY * 2)
        {
            answer = dis / 2;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx <= 0 || nx > 101 || ny <= 0 || ny > 101 || g_visit[nx][ny])
                continue;
            if (!graph[nx][ny])
                continue;

            q.push({nx, ny, dis + 1});
            g_visit[nx][ny] = true;
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> rectangle = {{1, 1, 7, 4}, {3, 2, 5, 5}, {4, 3, 6, 9}, {2, 6, 8, 8}};
    int characterX = 1;
    int characterY = 3;
    int itemX = 7;
    int itemY = 8;

    cout << "answer : " << bfs(rectangle, characterX, characterY, itemX, itemY) << endl;

    return EXIT_SUCCESS;
}