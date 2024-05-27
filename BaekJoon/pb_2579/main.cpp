#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
세 계단 연속 x
경우의 수
o o x
o x o
x o o
*/
int solution(const vector<int> &stair)
{
    int res = 0;
    vector<int> dp(stair.size(), 0);
    dp[0] = stair[0];
    dp[1] = stair[0] + stair[1];
    dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

    for (int i = 3; i < stair.size(); i++)
        dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);

    return dp[dp.size() - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> stair(n, 0);
    for (auto &i : stair)
        cin >> i;

    cout << solution(stair) << endl;

    return EXIT_SUCCESS;
}