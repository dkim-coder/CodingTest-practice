#include <iostream>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;

/*
만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
*/

char board[101][101];

#define EMPTY 0
#define BODY 1
#define APPLE 2

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int solution(const int n, const vector<pair<int, int>> &apple_pos, const vector<pair<int, char>> &snake_move)
{
    int res = 1;
    memset(board, EMPTY, sizeof(board));

    for (auto &i : apple_pos)
        board[i.first][i.second] = APPLE;

    deque<pair<int, int>> dq;
    board[1][1] = BODY;
    int direct = RIGHT;
    dq.push_front({1, 1});
    int past_time = 0;

    for (auto &i : snake_move)
    {
        for (int j = 0; j < i.first - past_time; j++)
        {
            int nr, nc;
            nr = dq.front().first + dx[direct];
            nc = dq.front().second + dy[direct];

            if (nr <= 0 || nr > n || nc <= 0 || nc > n)
                return res;

            if (board[nr][nc] == APPLE)
            {
                board[nr][nc] = BODY;
                dq.push_front({nr, nc});
            }
            else if (board[nr][nc] == EMPTY)
            {
                board[nr][nc] = BODY;
                dq.push_front({nr, nc});
                board[dq.back().first][dq.back().second] = EMPTY;
                dq.pop_back();
            }
            else
                return res;

            res++;
        }

        past_time = i.first;
        if (i.second == 'L')
        {
            if (direct == UP)
                direct = LEFT;
            else if (direct == LEFT)
                direct = DOWN;
            else if (direct == RIGHT)
                direct = UP;
            else
                direct = RIGHT;
        }
        else
        {
            if (direct == UP)
                direct = RIGHT;
            else if (direct == LEFT)
                direct = UP;
            else if (direct == RIGHT)
                direct = DOWN;
            else
                direct = LEFT;
        }
    }

    while (true)
    {
        int nr, nc;
        nr = dq.front().first + dx[direct];
        nc = dq.front().second + dy[direct];

        if (nr <= 0 || nr > n || nc <= 0 || nc > n)
            return res;

        if (board[nr][nc] == APPLE)
        {
            board[nr][nc] = BODY;
            dq.push_front({nr, nc});
        }
        else if (board[nr][nc] == EMPTY)
        {
            board[nr][nc] = BODY;
            dq.push_front({nr, nc});
            board[dq.back().first][dq.back().second] = EMPTY;
            dq.pop_back();
        }
        else
            return res;

        res++;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int apple_num;
    int move_num;
    vector<pair<int, int>> apple_pos;
    vector<pair<int, char>> snake_move;

    cin >> n;
    cin >> apple_num;
    for (int i = 0; i < apple_num; i++)
    {
        int row, column;
        cin >> row >> column;
        apple_pos.push_back(make_pair(row, column));
    }
    cin >> move_num;
    for (int i = 0; i < move_num; i++)
    {
        int sec;
        char direct;
        cin >> sec >> direct;
        snake_move.push_back(make_pair(sec, direct));
    }

    cout << solution(n, apple_pos, snake_move) << "\n";

    return EXIT_SUCCESS;
}