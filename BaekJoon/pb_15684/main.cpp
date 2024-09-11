#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

short N, M, H;
bool board[32][12];

bool isOk()
{
    bool res = true;

    for (int i = 1; i <= N; i++)
    {
        short cr, cc;
        cr = 1;
        cc = i;
        while (cr <= M)
        {
            if (board[cr][cc] && board[cr][cc + 1])
                cc++;
            else if (board[cr][cc] && board[cr][cc - 1])
                cc--;
            cr++;
        }

        if (cc != i)
            return false;
    }

    return res;
}

short bfs(const vector<pair<short, short>> &v)
{
    short res = -1;
    queue<set<pair<short, short>>> q;

    if (isOk())
        return 0;

    for (int i = 0; i < v.size(); i++)
    {
        set<pair<short, short>> t;
        t.insert(v[i]);
        q.push(t);
    }

    while (!q.empty())
    {
        set<pair<short, short>> cs;
        vector<pair<pair<short, short>, bool>> tmp;
        cs = q.front();
        q.pop();

        for (auto iter = cs.begin(); iter != cs.end(); iter++)
        {
            tmp.push_back({{iter->first, iter->second}, board[iter->first][iter->second]});
            tmp.push_back({{iter->first, iter->second + 1}, board[iter->first][iter->second + 1]});
            board[iter->first][iter->second] = true;
            board[iter->first][iter->second + 1] = true;
        }

        if (isOk())
            return static_cast<short>(cs.size());
        else
        {
            for (int i = 0; i < tmp.size(); i++)
                board[tmp[i].first.first][tmp[i].first.second] = tmp[i].second;
        }

        if (cs.size() < 3)
        {
            for (int i = 0; i < v.size(); i++)
            {
                set<pair<short, short>> ns;
                ns = cs;
                if (cs.find(v[i]) == cs.end())
                {
                    ns.insert(v[i]);
                    q.push(ns);
                }
            }
        }
    }

    return res;
}

int main()
{
    scanf("%hd %hd %hd", &N, &H, &M);

    for (int i = 0; i < M + 2; i++)
        memset(board[i], false, sizeof(bool) * N + 2);

    short a, b;
    for (int i = 0; i < H; i++)
    {
        scanf("%hd %hd", &a, &b);
        board[a][b] = true;
        board[a][b + 1] = true;
    }

    vector<pair<short, short>> v;
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (!(board[i][j] || board[i][j + 1]))
                v.push_back({i, j});
        }
    }

    printf("%hd", bfs(v));

    return 0;
}