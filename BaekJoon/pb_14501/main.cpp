#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char n;
char t[16];
int p[16];
int dp[16];

inline int MAX(int a, int b)
{
    return a > b ? a : b;
}

int solution()
{
    int res = 0;

    char deadline;
    for (char i = n; i > 0; i--)
    {
        deadline = i + t[i];
        if (deadline > n + 1)
            dp[i] = dp[i + 1];
        else
            dp[i] = MAX(dp[i + 1], dp[deadline] + p[i]);
    }

    res = dp[1];

    return res;
}

int main()
{
    scanf("%hhd", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%hhd %d", &t[i], &p[i]);
    }

    printf("%d\n", solution());

    return EXIT_SUCCESS;
}