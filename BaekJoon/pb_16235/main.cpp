#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

struct node
{
    int nutrition;
    int tree_num;
    deque<int> age;

    node()
    {
        nutrition = 5;
        tree_num = 0;
    }
};

int N, M, K;
node board[13][13];
int A[13][13];

bool comp(int &a, int &b)
{
    return a < b;
}

int solution()
{
    int res = 0;

    for (int cnt = 0; cnt < K; cnt++)
    {
        // 봄, 여름
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (board[i][j].tree_num > 0)
                {
                    sort(board[i][j].age.begin(), board[i][j].age.end(), comp);
                    int k = 0;
                    int tmp;
                    for (k = 0; k < board[i][j].tree_num; k++)
                    {
                        if (board[i][j].age[k] <= board[i][j].nutrition)
                        {
                            board[i][j].nutrition -= board[i][j].age[k];
                            board[i][j].age[k]++;
                        }
                        else
                            break;
                    }
                    tmp = k;
                    for(; k < board[i][j].tree_num; k++)
                        board[i][j].nutrition += board[i][j].age[k] / 2;
                    for(; tmp < board[i][j].tree_num; tmp++)
                        board[i][j].age.pop_back();

                    board[i][j].tree_num = board[i][j].age.size();
                }
            }
        }

        // 가을
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (board[i][j].tree_num > 0)
                {
                    for (auto at : board[i][j].age)
                    {
                        if (at % 5 == 0)
                        {
                            board[i - 1][j - 1].tree_num++;
                            board[i - 1][j - 1].age.push_back(1);
                            board[i - 1][j].tree_num++;
                            board[i - 1][j].age.push_back(1);
                            board[i - 1][j + 1].tree_num++;
                            board[i - 1][j + 1].age.push_back(1);
                            board[i][j - 1].tree_num++;
                            board[i][j - 1].age.push_back(1);
                            board[i][j + 1].tree_num++;
                            board[i][j + 1].age.push_back(1);
                            board[i + 1][j - 1].tree_num++;
                            board[i + 1][j - 1].age.push_back(1);
                            board[i + 1][j].tree_num++;
                            board[i + 1][j].age.push_back(1);
                            board[i + 1][j + 1].tree_num++;
                            board[i + 1][j + 1].age.push_back(1);
                        }
                    }
                }
            }
        }

        // 겨울
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                board[i][j].nutrition += A[i][j];
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            res += board[i][j].tree_num;

    return res;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);

    int r, c, age;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &A[i][j]);

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &r, &c, &age);
        board[r][c].tree_num++;
        board[r][c].age.push_back(age);
    }

    printf("%d\n", solution());

    return 0;
}