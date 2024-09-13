#include <cstdio>
#include <utility>
#include <queue>
#include <limits.h>
#include <vector>

using namespace std;

short board[20][20];
short N;

short dx[] = {-1, 1, 0, 0};
short dy[] = {0, 0, -1, 1};

int solution(short r, short c)
{
    int res = 0;
    pair<int, int> fish;
    bool flag = true;
    fish.first = 2;
    fish.second = 0;

    while (flag)
    {
        queue<pair<pair<short, short>, int> > q;
        vector<pair<short, short> > v;
        q.push(make_pair(make_pair(r, c), 0));
        int dist = INT_MAX;
        vector<vector<bool> > check(N, vector<bool>(N, false));

        while (!q.empty())
        {
            short cr, cc;
            int cdist;
            cr = q.front().first.first;
            cc = q.front().first.second;
            cdist = q.front().second;
            q.pop();

            if (cdist > dist)
                break;

            if (board[cr][cc] < fish.first && board[cr][cc] > 0)
            {
                dist = cdist;
                v.push_back(make_pair(cr, cc));
            }

            for (short i = 0; i < 4; i++)
            {
                short nr = cr + dx[i];
                short nc = cc + dy[i];

                if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                    continue;

                if (board[nr][nc] > fish.first || check[nr][nc])
                    continue;

                q.push(make_pair(make_pair(nr, nc), cdist + 1));
                check[nr][nc] = true;
            }
        }

        if (v.size() == 0)
            flag = false;
        else
        {
            res += dist;
            int min_c = INT_MAX;
            int min_r = INT_MAX;
            for (int i = 0; i < v.size(); i++)
                if (v[i].first < min_r)
                    min_r = v[i].first;

            for (int i = 0; i < v.size(); i++)
                if (v[i].first == min_r && v[i].second < min_c)
                    min_c = v[i].second;

            fish.second++;
            board[min_r][min_c] = 0;
            r = min_r;
            c = min_c;

            while (fish.first <= fish.second)
            {
                fish.second -= fish.first;
                fish.first++;
            }
        }
    }

    return res;
}

int main()
{
    scanf("%hd", &N);
    short r, c;
    for (short i = 0; i < N; i++)
    {
        for (short j = 0; j < N; j++)
        {
            scanf("%hd", &board[i][j]);
            if (board[i][j] == 9)
            {
                r = i;
                c = j;
                board[i][j] = 0;
            }
        }
    }

    printf("%d\n", solution(r, c));

    return 0;
}