#include <cstdio>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

short A[50][50];
short N, L, R;

short dx[] = {0, 0, -1, 1};
short dy[] = {-1, 1, 0, 0};

void dfs(short r, short c, vector<vector<bool>> &check, set<pair<short, short>> &s)
{
    // if(check[r][c])
    //     return;

    for(int i = 0; i < 4; i++)
    {
        short nr, nc;
        nr = r + dx[i];
        nc = c + dy[i];

        if(nr < 0 || nr >= N || nc < 0 || nc >= N)
            continue;

        if(check[nr][nc])
            continue;

        if(abs(A[r][c] - A[nr][nc]) >= L && abs(A[r][c] - A[nr][nc]) <= R)
        {
            check[nr][nc] = true;
            s.insert({nr, nc});
            dfs(nr, nc, check, s);
        }
    }
    
    return;
}


int solution()
{
    int res = 0;

    while(true)
    {
        vector<vector<bool>> check(static_cast<int>(N), vector<bool>(static_cast<int>(N), false));
        vector<set<pair<short, short>>> v;
        for(short i = 0; i < N; i++){
            for(short j = 0; j < N; j++){
                if(!check[i][j])
                {
                    set<pair<short, short>> s;
                    s.insert({i, j});
                    check[i][j] = true;
                    dfs(i, j, check, s);
                    v.push_back(s);
                }
            }
        }

        if(v.size() == N * N)
            break;

        for(int i = 0; i < v.size(); i++)
        {
            int val = 0;
            for(auto iter = v[i].begin(); iter != v[i].end(); iter++)
                val += A[iter->first][iter->second];

            for(auto iter = v[i].begin(); iter != v[i].end(); iter++)
                A[iter->first][iter->second] = static_cast<short>(val / v[i].size());
        }

        res++;
    }

    return res;
}

int main()
{
    scanf("%hd %hd %hd", &N, &L, &R);

    for(short i = 0; i < N; i++)
        for(short j = 0; j < N; j++)
            scanf("%hd", &A[i][j]);

    printf("%d\n", solution());

    return 0;
}