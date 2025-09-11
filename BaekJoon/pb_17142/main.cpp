#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define BLANK 0
#define WALL 1
#define VIRUS 2

using namespace std;

int N, M; 
int board[50][50];
bool visited[50][50];
vector<pair<int, int>> virus;
vector<int> virus_idx;
int res;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int target_cnt;

struct svirus
{
    int r, c, depth;
    svirus() = default;
    svirus(const int r, const int c, const int depth) : r(r), c(c), depth(depth){}
};

/**
 * @brief bfs로 탐색을 해서 이동 최소 거리를 구해야 함
 * 
 */
void bfs()
{
    int cnt = 0;
    int max_depth = 0;
    memset(visited, false, sizeof(visited));
    queue<svirus> q;
    for(int i = 0; i < virus_idx.size(); i++){
        q.push({virus[virus_idx[i]].first, virus[virus_idx[i]].second, 0});
        visited[virus[virus_idx[i]].first][virus[virus_idx[i]].second] = true;
    }

    while(!q.empty())
    {
        int cr = q.front().r;
        int cc = q.front().c;
        int depth = q.front().depth;
        q.pop();
        if(depth >= res)
            return;
        

        // @note 중요한 점이 현재 depth로 끝내버리면 큐에 남아 있는데도 불구하고 이전게 되기 때문에 해결방법으로는 큐 구조체에 카운트도 같이 넣어주거나 했어야 했을 것 같음 
        if(cnt == target_cnt){
            if(max_depth < res)
                res = max_depth;
            return;
        }

        for(int i = 0; i < 4; i++)
        {
            int nr = cr + dx[i];
            int nc = cc + dy[i];
            int ndepth = depth + 1;

            if(nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;
            if(board[nr][nc] == WALL || visited[nr][nc])
                continue;
            
            visited[nr][nc] = true;
            if(board[nr][nc] == BLANK)
                cnt++;
            max_depth= max(max_depth, ndepth);
            q.push({nr, nc, ndepth});
        }
    }

    return;
}

/**
 * @brief 
 * 
 * @param cnt 배열에 추가한 인덱스 개수 
 * @param idx 현재 조합에 탐색을 시작하고 있는 인덱스
 */
void solve(const int cnt, const int idx)    // 조합으로 경우 구해줘야함
{
    if(cnt == M)
    {
        bfs();
        return;
    }

    for(int i = idx; i < virus.size(); i++)
    {
        virus_idx[cnt] = i;
        solve(cnt + 1, i + 1);
    }

    return;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    virus_idx.resize(M);
    target_cnt = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == VIRUS)
                virus.push_back(make_pair(i, j));
            if(board[i][j] == BLANK)
                target_cnt++;
        }
    }

    res = INT32_MAX;    
    solve(0, 0);
    if(res == INT32_MAX)
        res = -1;
    cout << res << endl;

    return 0;
}