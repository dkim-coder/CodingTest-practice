#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_MOVE 5

int n;
int map[20][20];
int res;

vector<vector<int>> move(vector<vector<int>> v, int direct)
{
    switch (direct)
    {
    case 0: // up
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            int pv;
            for (int j = 0; j < n; j++)
            {
                if (v[j][i] != 0)
                {
                    if (cnt == 0)
                    {
                        pv = v[j][i];
                        v[j][i] = 0;
                        v[cnt++][i] = pv;
                        continue;
                    }

                    if (pv == v[j][i])
                    {
                        v[j][i] = 0;
                        v[cnt - 1][i] = pv * 2;
                        pv = 0;
                    }
                    else
                    {
                        pv = v[j][i];
                        v[j][i] = 0;
                        v[cnt++][i] = pv;
                    }
                }
            }
        }
        break;
    case 1: // down
        for (int i = 0; i < n; i++)
        {
            int cnt = n - 1;
            int pv;
            for (int j = n - 1; j >= 0; j--)
            {
                if (v[j][i] != 0)
                {
                    if (cnt == n - 1)
                    {
                        pv = v[j][i];
                        v[j][i] = 0;
                        v[cnt--][i] = pv;
                        continue;
                    }

                    if (pv == v[j][i])
                    {
                        v[j][i] = 0;
                        v[cnt + 1][i] = pv * 2;
                        pv = 0;
                    }
                    else
                    {
                        pv = v[j][i];
                        v[j][i] = 0;
                        v[cnt--][i] = pv;
                    }
                }
            }
        }
        break;
    case 2: // left
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            int pv;
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] != 0)
                {
                    if (cnt == 0)
                    {
                        pv = v[i][j];
                        v[i][j] = 0;
                        v[i][cnt++] = pv;
                        continue;
                    }

                    if (pv == v[i][j])
                    {
                        v[i][j] = 0;
                        v[i][cnt - 1] = pv * 2;
                        pv = 0;
                    }
                    else
                    {
                        pv = v[i][j];
                        v[i][j] = 0;

                        v[i][cnt++] = pv;
                    }
                }
            }
        }
        break;
    case 3:
        for (int i = 0; i < n; i++)
        {
            int cnt = n - 1;
            int pv;
            for (int j = n - 1; j >= 0; j--)
            {
                if (v[i][j] != 0)
                {
                    if (cnt == n - 1)
                    {
                        pv = v[i][j];
                        v[i][j] = 0;
                        v[i][cnt--] = pv;
                        continue;
                    }

                    if (pv == v[i][j])
                    {
                        v[i][j] = 0;

                        v[i][cnt + 1] = pv * 2;
                        pv = 0;
                    }
                    else
                    {
                        pv = v[i][j];
                        v[i][j] = 0;

                        v[i][cnt--] = pv;
                    }
                }
            }
        }
        break;
    }

    return v;
}

void dfs(vector<vector<int>> v, int cnt)
{
    if (cnt == MAX_MOVE)
    {
        for (int i = 0; i < n; i++)
            res = max(res, *max_element(v[i].begin(), v[i].end()));
        return;
    }

    for (int i = 0; i < 4; i++)
        dfs(move(v, i), cnt + 1);

    return;
}

void solution()
{
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            v[i][j] = map[i][j];
    }

    res = 0;
    dfs(v, 0);

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    solution();
    cout << res << "\n";

    return EXIT_SUCCESS;
}