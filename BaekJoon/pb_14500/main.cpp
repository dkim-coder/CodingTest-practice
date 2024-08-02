#include <iostream>
#include <vector>

using namespace std;

int N, M;
int board[500][500];

// 완탐 -> 종료 조건 4개

int res = 0;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs(vector<pair<int, int>> v)
{
    if (v.size() == 4)
    {
        int tmp = 0;
        for (auto i : v)
            tmp += board[i.first][i.second];

        if (tmp > res)
            res = tmp;
        return;
    }

    int cr = v.back().first;
    int cc = v.back().second;

    if (v.size() == 3)
    {
        int tmp_r = v[1].first;
        int tmp_c = v[1].second;

        for (int i = 0; i < 4; i++)
        {
            vector<pair<int, int>> t = v;

            int tmp_nr = tmp_r + dx[i];
            int tmp_nc = tmp_c + dy[i];

            if (tmp_nr < 0 || tmp_nr >= N || tmp_nc < 0 || tmp_nc >= M)
                continue;

            bool check = false;

            for (auto j : t)
            {
                if (j.first == tmp_nr && j.second == tmp_nc)
                {
                    check = true;
                    break;
                }
            }

            if (check)
                continue;
            else
            {
                t.push_back(make_pair(tmp_nr, tmp_nc));
                dfs(t);
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        vector<pair<int, int>> t = v;
        int nr = cr + dx[i];
        int nc = cc + dy[i];
        bool check = false;

        if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            continue;

        for (auto j : v)
        {
            if (j.first == nr && j.second == nc)
            {
                check = true;
                break;
            }
        }

        if (check)
            continue;

        t.push_back(make_pair(nr, nc));
        dfs(t);
    }

    return;
}

void solution()
{
    res = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            vector<pair<int, int>> v;
            v.push_back(make_pair(i, j));
            dfs(v);
        }
    }

    cout << res << "\n";

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    solution();

    return EXIT_SUCCESS;
}