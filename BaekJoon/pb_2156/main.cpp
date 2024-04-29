#include <iostream>
#include <vector>

using namespace std;

// dp[3]=arr[1]+arr[2]+arr[3]-min({arr[1],arr[2],arr[3]});

int solution(int n, vector<int> wine)
{
    int res = 0;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i], max(dp[i - 2] + wine[i], dp[i - 1]));
    }

    res = dp[n];

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> wine(n + 1);
    wine[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> wine[i];

    cout << solution(n, wine) << endl;

    return EXIT_SUCCESS;
}