#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// dp[i] = max(dp[i - 1], money + dp[i - 2])
// case 1. 첫 번째 집을 무조건 털고, 마지막 집을 털지 않는 경우
// case 2. 마지막 집을 무조건 털고 첫 번째 집을 털지 않는 경우로 나누어 생각

int solution(vector<int> money)
{
    int res = 0;

    vector<int> dp1(money.size(), 0);
    dp1[0] = money[0];
    dp1[1] = max(money[0], money[1]);
    for (int i = 2; i < money.size() - 1; i++)
        dp1[i] = max(dp1[i - 1], money[i] + dp1[i - 2]);

    vector<int> dp2(money.size(), 0);
    dp2[0] = 0;
    dp2[1] = money[1];
    for(int i = 2; i < money.size();i++)
        dp2[i] = max(dp2[i - 1], money[i] + dp2[i - 2]);

    res = max(dp1[money.size() - 2], dp2[money.size() - 1]);

    return res;
}

int main()
{
    vector<int> money = {1, 2, 3, 1};

    cout << "Answer : " << solution(money) << endl;

    return EXIT_SUCCESS;
}