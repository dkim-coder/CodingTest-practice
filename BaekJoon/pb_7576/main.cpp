#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define endl "\n"

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<vector<int>> input(int &M, int &N)
{
    cin >> N >> M;
    vector<vector<int>> map(M, vector<int>(N, 0));
    
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            cin >> map[i][j];
    
    return map;
}

int bfs(vector<vector<int>> map, const int M, const int N)
{
    int ans = 0;
    queue<pair<int, int>> q;

    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            if(map[i][j] == 1)
                q.push({i, j});

    while(!q.empty())
    {
        int cr, cc;
        cr = q.front().first;
        cc = q.front().second;
        q.pop();

        for(int i = 0;i < 4; i++)
        {
            int nr, nc;
            nr = cr + dx[i];
            nc = cc + dy[i];

            if(nr < 0 || nr >= M || nc < 0 || nc >= N)
                continue;

            if(map[nr][nc] == -1)
                continue;

            if(map[nr][nc] != 0 && map[nr][nc] <= map[cr][cc] + 1)
                continue;

            q.push({nr, nc});
            map[nr][nc] = map[cr][cc] + 1;
        }
    }

    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            if(map[i][j] == 0)
                return -1;
            else
                ans = max(ans, map[i][j]);

    return ans - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;    
    vector<vector<int>> map;
    map = input(M, N);
    cout << bfs(map, M, N) << endl;

    return 0;
}