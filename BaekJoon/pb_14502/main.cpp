#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

#define MAX_WALL 3
#define BLANK 0
#define WALL 1
#define VIRUS 2

char N, M;
int INITIAL_VIRUS;
int INITIAL_WALL;

char dx[] = {-1, 1, 0, 0};
char dy[] = {0, 0, -1, 1};

/*
벽 3개 조합 모두 하면 경우의 수가 너무 많음.
어차피 막을 벽의 가지 수 는 2 사방향 이 기준으로 해볼까?
*/

int blankNum(vector<vector<char>> map, const vector<pair<char, char>> &virus_index, const vector<pair<char, char>> &candidate, const vector<char> &tmp)
{
    int res = 0;
    int virus_num = INITIAL_VIRUS;
    int wall_num = INITIAL_WALL + MAX_WALL;

    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i] == 0)
        {
            map[candidate[i].first][candidate[i].second] = WALL;
            res++;
        }
    }

    for (const auto &i : virus_index)
    {
        stack<pair<char, char>> st;
        st.push(make_pair(i.first, i.second));

        while (!st.empty())
        {
            char cx, cy;
            cx = st.top().first;
            cy = st.top().second;
            st.pop();

            for (int j = 0; j < 4; j++)
            {
                char nx, ny;
                nx = cx + dx[j];
                ny = cy + dy[j];
                
                if(map[nx][ny] == BLANK)
                {
                    map[nx][ny] = VIRUS;
                    virus_num++;
                    st.push(make_pair(nx, ny));
                }
            }
        }
    }

    res = N * M - virus_num - wall_num;

    return res;
}

int solution(vector<vector<char>> map, const vector<pair<char, char>> &virus_index, const vector<pair<char, char>> &candidate)
{
    int res = 0;

    vector<char> tmp(candidate.size(), 1);
    tmp[0] = 0;
    tmp[1] = 0;
    tmp[2] = 0;

    do
    {
        int t = blankNum(map, virus_index, candidate, tmp);
        if (t > res)
            res = t;
    } while (next_permutation(tmp.begin(), tmp.end()));

    return res;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    scanf("%hhd %hhd", &N, &M);
    vector<vector<char>> map(N + 2, vector<char>(M + 2));
    vector<pair<char, char>> virus_index;
    vector<pair<char, char>> candidate;
    INITIAL_VIRUS = 0;
    INITIAL_WALL = 0;

    for (int i = 0; i <= N + 1; i++)
    {
        for (int j = 0; j <= M + 1; j++)
        {
            if (i == 0 || i == N + 1 || j == 0 || j == M + 1)
                map[i][j] = WALL;
            else
            {
                scanf("%hhd", &map[i][j]);
                if (map[i][j] == VIRUS)
                {
                    virus_index.push_back(make_pair(i, j));
                    INITIAL_VIRUS++;
                }
                else if (map[i][j] == WALL)
                {
                    INITIAL_WALL++;
                }else
                {
                    candidate.push_back(make_pair(i, j));
                }
            }
        }
    }

    printf("%d\n", solution(map, virus_index, candidate));

    return EXIT_SUCCESS;
}