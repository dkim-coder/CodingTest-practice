#include <iostream>
#include <vector>

using namespace std;

#define MODUL 1000000007

int solution(int m, int n, vector<vector<int>> puddles)
{
    int res = 0;
    vector<vector<int>> maps(100, vector<int>(100, -1));

    maps[0][0] = 1;

    for (auto p : puddles)
        maps[p[0] - 1][p[1] - 1] = 0; // 물에 잠긴 지역

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (maps[i][j] == -1)
            {
                if (i == 0 && j == 0)
                    continue;
                else if (i == 0)
                    maps[i][j] = maps[i][j - 1] % MODUL;
                else if (j == 0)
                    maps[i][j] = maps[i - 1][j] % MODUL;
                else
                    maps[i][j] = (maps[i][j - 1] + maps[i - 1][j]) % MODUL;
            }
        }
    }

    res = maps[m - 1][n - 1];

    return res;
}

int main()
{
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = {{2, 2}};

    cout << solution(m, n, puddles) << endl;

    return EXIT_SUCCESS;
}