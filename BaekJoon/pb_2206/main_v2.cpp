/*
 * 양방향 BFS 
 */

#include <iostream>
#include <cstring>
#include <queue>

#define endl '\n'
#define LIMIT 1

using namespace std;

static int N, M;
static int board[1001][1001];
static int start[1001][1001];   // 시작점에서 각 좌표에 갈 수 있는 최단
static int end[1001][1001];     // 도착점에서 각 좌표에 갈 수 있는 최단
static bool visited[1001][1001];
static int dr[4] = {-1, 1, 0, 0};
static int dc[4] = {0, 0, -1, 1};

int solution(){
    // 시작점
    memset(visited, false, sizeof(visited));
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    visited[0][0] = true;

    memset(start, 0, sizeof(start));
    start[0][0] = 1;
    while(!q.empty())
    {
        pair<pair<int, int>, int> cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = cur.first.first + dr[i];
            int nc = cur.first.second + dc[i];

            if(nr < 0 || nc < 0 || nr >= N || nc >= M)
                continue;
            
            if(visited[nr][nc] || board[nr][nc] == 1)
                continue;
            
        }
    }
}

int main(int argc, char *argv[]){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < M; j++){
            board[i][j] = str[j] - '0';
        }
    }

    return 0;
}