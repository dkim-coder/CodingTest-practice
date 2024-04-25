#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
DP의 핵심은 다음 것의 연산에 이전 결과가 사용되기 때문에 이전 결과들을 다시 계산하지 않고 저장한 다는 점.
*/

int getN(int N, int idx)
{
    int res = N;
    for (int i = 1; i <= idx; i++)
    {
        res = res * 10 + N;
    }
    return res;
}

int solution(int N, int number)
{
    if (N == number)
        return 1;

    vector<unordered_set<int>> dp(8); // dp[i] -> i개 n으로 만들 수 있는 숫자들을 저장
    dp[0].insert(N);

    for (int k = 1; k < 8; k++)
    {
        dp[k].insert(getN(N, k));   // 처음에는 5, 55, 555... 같은 숫자들을 넣어줌

        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (i + j + 1 != k)
                    continue;
                for (int a : dp[i])
                {
                    for (int b : dp[j])
                    {
                        dp[k].insert(a + b);

                        if (a - b > 0)
                            dp[k].insert(a - b);

                        dp[k].insert(a * b);

                        if (a / b > 0)
                            dp[k].insert(a / b);
                    }
                }
            }
        }

        if (dp[k].find(number) != dp[k].end())
            return k + 1;
    }

    return -1;
}

int main()
{
    int N = 5;
    int number = 12;

    cout << "Answer : " << solution(5, 12) << endl;

    return EXIT_SUCCESS;
}