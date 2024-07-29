#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct ball
{
    int rx, ry;
    int bx, by;
    int cnt;

    ball(int rx = 0, int ry = 0, int bx = 0, int by = 0, int cnt = 0)
    {
        this->rx = rx;
        this->ry = ry;
        this->bx = bx;
        this->by = by;
        this->cnt = cnt;
    }
};

int solution(const int N, const int M, vector<vector<char>> &board)
{
    int res = -1;
    int end_x;
    int end_y;
    ball start;
    queue<ball> q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 'R')
            {
                start.rx = i;
                start.ry = j;
                board[i][j] = '.';
            }

            if (board[i][j] == 'B')
            {
                start.bx = i;
                start.by = j;
                board[i][j] = '.';
            }

            if (board[i][j] == 'O')
            {
                end_x = i;
                end_y = j;
            }
        }
    }

    start.cnt = 0;
    q.push(start);
    while (!q.empty())
    {
        int crx, cry, cbx, cby, ccnt;
        crx = q.front().rx;
        cry = q.front().ry;
        cbx = q.front().bx;
        cby = q.front().by;
        ccnt = q.front().cnt;
        q.pop();

        if (crx == end_x && cry == end_y)
            return ccnt;

        if (ccnt > 10)
            return -1;

        for (int i = 0; i < 4; i++)
        {
            int nrx, nry, nbx, nby;
            nrx = crx;
            nry = cry;
            nbx = cbx;
            nby = cby;

            while (true)
            {
                nrx += dx[i];
                nry += dy[i];
                if (board[nrx][nry] == '#')
                {
                    nrx -= dx[i];
                    nry -= dy[i];
                    break;
                }

                if (board[nrx][nry] == 'O')
                    break;
            }

            while (true)
            {
                nbx += dx[i];
                nby += dy[i];
                if (board[nbx][nby] == '#')
                {
                    nbx -= dx[i];
                    nby -= dy[i];
                    break;
                }

                if (board[nbx][nby] == 'O')
                    break;
            }

            if (board[nbx][nby] == 'O')
                continue;

            if (nrx == nbx && nry == nby)
            {
                switch (i)
                {
                case 0:
                    if (crx < cbx)
                        nbx++;
                    else
                        nrx++;
                    break;
                case 1:
                    if (crx < cbx)
                        nrx--;
                    else
                        nbx--;
                    break;
                case 2:
                    if (cry < cby)
                        nby++;
                    else
                        nry++;
                    break;
                case 3:
                    if (cry < cby)
                        nry--;
                    else
                        nby--;
                    break;
                }
            }

            q.push(ball(nrx, nry, nbx, nby, ccnt + 1));
        }
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<char>> board;

    for (int i = 0; i < N; i++)
    {
        vector<char> tmp(M);
        for (int j = 0; j < M; j++)
        {
            cin >> tmp[j];
        }
        board.push_back(tmp);
    }

    cout << solution(N, M, board) << endl;

    return EXIT_SUCCESS;
}