#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;
using pii = pair<int, int>;

static int N;
static int board[25][25];
static bool visited[25][25];
static int dr[] = {-1, 1, 0, 0};
static int dc[] = {0, 0, -1, 1};
static vector<int> v;
static int depth;

bool comp(const int &a, const int &b){
    return a < b;
}

void dfs(const int &cr, const int &cc)
{
    for(int i = 0; i < 4; i++)
    {
        int nr = cr + dr[i];
        int nc = cc + dc[i];
        if(nr < 0 || nr >= N || nc < 0 || nc >= N)
            continue;
        if(visited[nr][nc] || board[nr][nc] == 0)
            continue;
        visited[nr][nc] = true;
        depth++;
        dfs(nr, nc);
    }

    return;
}

void solution()
{
    stack<pii> st;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(visited[i][j] || board[i][j] == 0)
                continue;
            
            visited[i][j] = true;
            depth = 1;
            dfs(i, j);
            v.push_back(depth);

            // if(board[i][j] == 1)
            // {
            //     st.push({i, j});
            //     visited[i][j] = true;
            //     v.push_back(1);

            //     while(!st.empty())
            //     {
            //         int cr = st.top().first;
            //         int cc = st.top().second;
            //         st.pop();
                
            //         for(int k = 0; k < 4; k++)
            //         {
            //             int nr = cr + dr[k];
            //             int nc = cc + dc[k];

            //             if(nr < 0 || nr >= N || nc < 0 || nc >= N)
            //                 continue;
            //             if(visited[nr][nc] || board[nr][nc] == 0)
            //                 continue;

            //             visited[nr][nc] = true;
            //             st.push({nr, nc});
            //             v[v.size() - 1]++;
            //         }
            //     }
            // }
        }
    }

    cout << v.size() << endl;
    sort(v.begin(), v.end(), less<int>());
    for(const auto &i: v)
        cout << i << endl;

    return;
}

int main(int argc, char *argv[])
{
    cin >> N;
    memset(board, 0, sizeof(board));
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < N; j++)
            board[i][j] = str[j] - '0';
    }

    solution();

    return 0;
}