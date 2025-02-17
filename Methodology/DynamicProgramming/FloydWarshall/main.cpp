#include <iostream>
namespace floydwarshall
{
    using namespace std;

    int n, m;
    int **board;

    inline void input() // setting
    {
        cin >> n;
        cin >> m;

        board = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {

            board[i] = new int[n + 1];
            fill(&board[i][0], &board[i][n + 1], INT32_MAX);
            board[i][i] = 0;
        }

        int st, dest, weight;
        for (int i = 0; i < m; i++)
        {
            cin >> st >> dest >> weight;
            if (weight < board[st][dest])
                board[st][dest] = weight;
        }

        return;
    }

    inline void free_memory()
    {
        if (board != nullptr)
        {
            for (int i = 0; i <= n; i++)
                delete[] board[i];

            delete[] board;
            board = nullptr;
        }
    }

    void solution()
    {
        for (int k = 1; k <= n; k++) // 경유지
        {
            for (int i = 1; i <= n; i++) // 시작점
            {
                for (int j = 1; j <= n; j++) // 도착점
                {
                    if (board[i][k] != INT32_MAX && board[k][j] != INT32_MAX)
                    {
                        board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
                    }
                }
            }
        }
        return;
    }
}

using namespace floydwarshall;

int main()
{
    input();
    solution();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++){
            if(board[i][j] == INT32_MAX)
                cout << 0 << " ";
            else
                cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    free_memory();

    return EXIT_SUCCESS;
}