#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
약수들은 제곱근까지 확인하면 구할 수 있음.
해당 약수로 나누었을 때도 확인 필요
*/

#if 0
int numModular(const int num)
{
    int res = 0;

    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            res++;
            if (i != num / i)
                res++;
        }
    }

    return res;
}
#endif

struct S
{
    int num;
    int cnt;
};

bool comp(S &a, S &b)
{
    if (a.cnt == b.cnt)
        return a.num < b.num;
    return a.cnt > b.cnt;
}

vector<int> solution(int e, vector<int> starts)
{
    vector<int> res;

    vector<S> dp(e + 1);
    for (int i = 1; i <= e; i++)
    {
        dp[i].num = i;
        dp[i].cnt = 1;
    }

    for (int i = 2; i <= e; i++)
    {
        for (int j = 1; j <= e / i; j++)
        {
            dp[i * j].cnt++;
        }
    }

    sort(dp.begin() + 1, dp.end(), comp);

    for (int i = 0; i < starts.size(); i++)
    {
        for (int j = 1; j <= e; j++)
        {
            if (dp[j].num >= starts[i] && dp[j].num <= e)
            {
                res.push_back(dp[j].num);
                break;
            }
        }
    }

    return res;
}

int main()
{
    int e = 8;
    vector<int> starts = {1, 3, 7};

    vector<int> res = solution(e, starts);
    for (auto r : res)
        cout << r << " ";
    cout << "\n";

    return EXIT_SUCCESS;
}