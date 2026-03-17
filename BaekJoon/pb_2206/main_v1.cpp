#include <iostream>
#include <cstring>
#include <queue>

#define end '\n'
#define LIMIT 1

using namespace std;

static int N, M;
static int board[1001][1001];
static bool visited[2][1001][1001];    // 맨 앞이 벽을 부순 횟수
static int dr[4] = {-1, 1, 0, 0};
static int dc[4] = {0, 0, -1, 1};
struct node {
    int r, c;
    int depth;
    int cnt;// 벽 부술수 있는 남은 횟수

    node(int r = 0, int c = 0, int depth = 1, int cnt = 1) : r(r), c(c), depth(depth), cnt(cnt){}
};

int solution(){
    int res = -1;
    queue<node> q;
    q.push(node(0, 0, 1, 0));
    visited[0][0][0] = true;// 벽을 안부수고 방문
   
    while(!q.empty())
    {
        node cur = q.front();
        q.pop();
        if(cur.r == N - 1 && cur.c == M - 1)
            return cur.depth;

        // 벽을 안부수고 이동
        for(int i = 0; i < 4; i++){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;

            if(board[nr][nc] == 1)
                continue;

            if(visited[cur.cnt][nr][nc])
                continue;

            visited[cur.cnt][nr][nc] = true;
            q.push(node(nr, nc, cur.depth + 1, cur.cnt));
        }

        // 벽을 부수고 이동하는경우
        if(cur.cnt < LIMIT){
            for(int i = 0; i < 4; i++){
                int nr = cur.r + dr[i];
                int nc = cur.c + dc[i];
    
                if(nr < 0 || nr >= N || nc < 0 || nc >= M)
                    continue;
    
                if(board[nr][nc] == 0)
                    continue;

                if(visited[cur.cnt + 1][nr][nc])
                    continue;
                
                visited[cur.cnt + 1][nr][nc] = true;
                q.push(node(nr, nc, cur.depth + 1, cur.cnt + 1));
            }
        }
    }

    return res;
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
    memset(visited, false, sizeof(visited));
    
    cout << solution() << endl;

    return 0;
}