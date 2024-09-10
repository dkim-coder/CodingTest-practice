#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

#define blank 0
#define house 1
#define ch_house 2

#define reDist(a, b, c, d) (abs((a) - (b)) + abs((c) - (d)))

char board[51][51];
char n, m;
short dx[] = {-1, 1, 0, 0};
short dy[] = {0, 0, -1, 1};

int solution(vector<pair<char, char> > h, vector<pair<char, char> > ch)
{
    int res = INT_MAX;

    vector<int> v(ch.size(), 1);
    for (char i = 0; i < m; i++)
        v[i] = 0;

    do
    {
        int tmp = 0;
        for (int i = 0; i < h.size(); i++)
        {
            int min_dist = INT_MAX;
            for(int j = 0; j < v.size(); j++)
            {
                if(v[j] == 0){
                    if(reDist(h[i].first, ch[j].first, h[i].second, ch[j].second) < min_dist)
                        min_dist = reDist(h[i].first, ch[j].first, h[i].second, ch[j].second);
                }
            }
            tmp += min_dist;
        }

        if(tmp < res)
            res = tmp;
    }while (next_permutation(v.begin(), v.end()));

    return res;
}

int main()
{
    vector<pair<char, char> > h;
    vector<pair<char, char> > ch;
    scanf("%hhd %hhd", &n, &m);
    for (char i = 0; i < n; i++)
    {
        for (char j = 0; j < n; j++)
        {
            scanf("%hhd", &board[i][j]);
            if (board[i][j] == house)
                h.push_back(make_pair(i, j));
            else if (board[i][j] == ch_house)
                ch.push_back(make_pair(i, j));
        }
    }
    printf("%d\n", solution(h, ch));

    return 0;
}