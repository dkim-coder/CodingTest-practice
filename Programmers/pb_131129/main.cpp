#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
우선 순위
1. target 을 만드는 최소 횟수
2. target 을 만드는 최소 횟수가 동일 하다면 싱글과 불이 가장 많게 하도록

싱글, 더블, 트리플
1 ~ 20 까지 무조건 싱글
21 ~ 40 까지는 (더블, 트리플 1번) or 싱글 2번
41 ~ 60 까지는 50이면 불 1번, 트리블 1번, (더블, 트리플 1번 + 싱글 1번), 싱글 3번
*/

#if 0
int g_depth;
int g_s;

// 완탐 백트래킹
void dfs(int cur, int depth, int s)
{
    if (cur < 0 || depth > g_depth) // 백 트랙
        return;

    if (cur == 0)
    {
        if (depth < g_depth)
        {
            g_depth = depth;
            g_s = s;
        }
        else if (depth == g_depth)
        {
            if (g_s < s)
                g_s = s;
        }

        return;
    }

    dfs(cur - 50, depth + 1, s + 1); // 불

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            if (i == 1) // 싱글
            {
                dfs(cur - i * j, depth + 1, s + 1);
            }
            else
            {
                dfs(cur - i * j, depth + 1, s);
            }
        }
    }
}

vector<int> solution(int target)
{
    vector<int> res;
    g_depth = INT32_MAX;
    g_s = 0;

    dfs(target, 0, 0);

    res = {g_depth, g_s};

    return res;
}
#endif

// Bottom up 접근 방식 Dp[i] : i 점수를 만드는데 최소한으로 드는 조합수와 50점과 싱글 점수의 갯수

vector<int> solution(int target)
{
    vector<int> answer(2, 0); //  총 횟수, 싱클 불 횟수
    vector<vector<int>> dp(100001, vector<int>(2, 0));

    for (int i = 1; i <= 20; i++)
    {
        dp[i][0] = 1;
        dp[i][1] = 1;
        if (!dp[i * 2][0])
            dp[i * 2][0] = 1;
        if (!dp[i * 3][0])
            dp[i * 3][0] = 1;
    }
    dp[50][0] = 1;
    dp[50][1] = 1;

    for (int i = 21; i <= 60; i++)
    {
        if (!dp[i][0]) // 값이 현재 없는 것
        {
            dp[i][0] = 2; // 두 번만에 갈 수 있음
            for (int j = 1; j <= 20; j++)
            {
                if (dp[i - j][0] + 1 <= dp[i][0])
                    dp[i][1] = max(dp[i - j][1] + 1, dp[i][1]);
            }
        }
    }

    // 목표가 60보다 큰 경우, 50으로 자를지 60으로 자를지 정하며 계산
    if (target > 60)
    {
        for (int i = 61; i <= target; i++)
        {
            if (dp[i - 60][0] > dp[i - 50][0])
            {
                dp[i][0] = dp[i - 50][0] + 1;
                dp[i][1] = dp[i - 50][1] + 1;
            }
            else if (dp[i - 60][0] < dp[i - 50][0])
            {
                dp[i][0] = dp[i - 60][0] + 1;
                dp[i][1] = dp[i - 60][1];
            }
            else
            {
                dp[i][0] = dp[i - 50][0] + 1;
                dp[i][1] = max(dp[i - 60][1], dp[i - 50][1] + 1);
            }
        }
    }

    return dp[target];
}

int main()
{
    int target = 173;
    vector<int> res = solution(target);
    for (const auto &i : res)
        cout << i << " ";
    cout << "\n";

    return EXIT_SUCCESS;
}