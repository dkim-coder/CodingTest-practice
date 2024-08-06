#include <iostream>
#include <vector>

using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

int ROOM[52][52];
int N, M;
int R, C, D;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int &res, int cr, int cc, int direction)
{
    bool check = false;

    if (ROOM[cr][cc] == 0)
    {
        res++;
        ROOM[cr][cc] = 2;
    }

    for (int i = 0; i < 4; i++)
    {
        if (ROOM[cr + dx[i]][cc + dy[i]] == 0)
        {
            check = true;
            break;
        }
    }

    if (check)
    {
        int next_direction = direction - 1;

        if (next_direction == -1)
            next_direction = 3;

        while(true)
        {
            int nr, nc;
            nr = cr + dx[next_direction];
            nc = cc + dy[next_direction];
            if(ROOM[nr][nc] == 0){
                dfs(res, nr, nc, next_direction);
                break;
            }
            else{
                next_direction--;
                if(next_direction == -1)
                    next_direction = 3;
            }
        }
    }else
    {
        int back_direction = direction - 2;
        if (back_direction < 0)
            back_direction = 4 - abs(back_direction);

        if (ROOM[cr + dx[back_direction]][cc + dy[back_direction]] != 1)
            dfs(res, cr + dx[back_direction], cc + dy[back_direction], direction);
        else
            return;
    }

    return;
}

int solution()
{
    int res = 0;

    dfs(res, R + 1, C + 1, D);

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    cin >> R >> C >> D;
    for (int i = 0; i < N + 2; i++)
    {
        for (int j = 0; j < M + 2; j++)
        {
            if (i == 0 || i == N + 1 || j == 0 || j == M + 1)
                ROOM[i][j] = 1;
            else
                cin >> ROOM[i][j];
        }
    }

    cout << solution() << "\n";

    return EXIT_SUCCESS;
}