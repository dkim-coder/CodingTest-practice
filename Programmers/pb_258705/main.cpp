#include <iostream>
#include <string>
#include <vector>

using namespace std;

#if 0
#define DUMMY -1

int g_res = 0;

bool isDone(int n, vector<int> tops, vector<int> v)
{
    for (int i = 0; i < n; i++)
    {
        if (tops[i] == 1)
        {
            if (i < n - 1)
            {
                if (v[i] == 3 && v[i + 1] == 1)
                    return false;
            }
        }
        else // tops[i] == 0
        {
            if (v[i] == 2)
                return false;
            if (i < n - 1)
            {
                if (v[i] == 3 && v[i + 1] == 1)
                    return false;
            }
        }
    }
    return true;
}

void dfs(int n, vector<int> tops, vector<int> cur)
{
    // 만약 size -> 판단 들어가고
    if (cur.size() == n)
    {
        if (isDone(n, tops, cur)) // 실제로 생성 되는지 판단 함수
        {
            g_res++;
        }
        return;
    }

    // 아니면
    cur.push_back(DUMMY);
    for (int i = 0; i < 4; i++)
    {
        if (tops[cur.size() - 1] == 0)
        {
            if (cur.size() == 1)
            {
                if (i == 2)
                    continue;
            }
            else
            {
                if (cur[cur.size() - 2] == 3)
                {
                    if (i == 1 || i == 2)
                        continue;
                }
            }
            cur.back() = i;
            dfs(n, tops, cur);
        }
        else
        {
            cur.back() = i;
            if (cur.size() > 1)
            {
                if (cur[cur.size() - 2] == 3 && i == 1)
                    continue;
            }
            dfs(n, tops, cur);
        }
        // dfs(n, tops, cur);
    }

    return;
}

int solution(int n, vector<int> tops)
{
    int answer = 0;
    g_res = 0;

    vector<int> cur;
    dfs(n, tops, cur);

    answer = g_res % 10007;

    return answer;
}
#endif

int solution(int n, vector<int> tops)
{
    int answer = 0;
    int MOD = 10007;
    vector<int> dp1(n, 0);
    vector<int> dp2(n, 0);
    dp1[0] = 1;
    dp2[0] = 2 + tops[0];

    for (int i = 1; i < n; i++)
    {
        dp1[i] = (dp1[i - 1] + dp2[i - 1]) % MOD;
        dp2[i] = ((dp1[i - 1] * (1 + tops[i])) + (dp2[i - 1] * (2 + tops[i]))) % MOD;
    }

    answer = (dp1.back() + dp2.back()) % MOD;

    return answer;
}

int main()
{
    // int n = 4;
    // vector<int> tops = {1, 1, 0, 1};
    int n = 10;
    vector<int> tops(10, 0);

    cout << solution(n, tops) << endl;

    return EXIT_SUCCESS;
}