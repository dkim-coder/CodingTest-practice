#include <iostream>
#include <vector>

using namespace std;

/*
지도의 각 칸에는 정수가 하나씩 쓰여져 있다.
주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다.
0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
*/

int N, M, X, Y, K;
int map[21][21];

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

struct dice{
    int left, right, up, down, back, front;

    dice()
    {
        this->left = 0;
        this->right = 0;
        this->up = 0;
        this->down = 0;
        this->back = 0;
        this->front = 0;
    }

    dice &operator=(const dice &ref)
    {
        if(this == &ref)
            return *this;
        
        this->left = ref.left;
        this->right = ref.right;
        this->up = ref.up;
        this->down = ref.down;
        this->back = ref.back;
        this->front = ref.front;

        return *this;
    }
};

void diceMove(const int cmd, dice &my_dice)
{
    dice tmp_dice = my_dice;
    switch (cmd)
    {
    case RIGHT:
        my_dice.up = tmp_dice.left;
        my_dice.right = tmp_dice.up;
        my_dice.down = tmp_dice.right;
        my_dice.left = tmp_dice.down;
        break;
    case LEFT:
        my_dice.up = tmp_dice.right;
        my_dice.right = tmp_dice.down;
        my_dice.down = tmp_dice.left;
        my_dice.left = tmp_dice.up;
        break;
    case UP:
        my_dice.up = tmp_dice.front;
        my_dice.front = tmp_dice.down;
        my_dice.down = tmp_dice.back;
        my_dice.back = tmp_dice.up;
        break;
    case DOWN:
        my_dice.up = tmp_dice.back;
        my_dice.front = tmp_dice.up;
        my_dice.down = tmp_dice.front;
        my_dice.back = tmp_dice.down;
        break;
    }

    return;
}

void solution(const vector<int> &command)
{
    dice my_dice;

    int cr, cc;
    int nr, nc;
    cr = X;
    cc = Y;

    for (auto &i : command)
    {
        nr = cr + dx[i];
        nc = cc + dy[i];

        if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            continue;

        diceMove(i, my_dice);

        if (map[nr][nc] == 0)
            map[nr][nc] = my_dice.down;
        else
        {
            my_dice.down = map[nr][nc];
            map[nr][nc] = 0;
        }

        cr = nr;
        cc = nc;
        cout << my_dice.up << "\n";
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> X >> Y >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    vector<int> command(K);
    for (int i = 0; i < K; i++)
        cin >> command[i];

    solution(command);

    return EXIT_SUCCESS;
}