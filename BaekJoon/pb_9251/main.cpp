#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
    private:
        Solution() = default;
        ~Solution() = default;
        Solution(const Solution&) = delete;
        Solution& operator=(const Solution&) = delete;
        string str1, str2;
    public:
        static Solution& getInstance();
        void input();
        inline int max(int a, int b) { return a > b ? a : b; }
        int solve();
};

Solution& Solution::getInstance()
{
    static Solution instance;
    return instance;
}

void Solution::input()
{
    cin >> str1 >> str2;

    return;
}

int Solution::solve()
{
    int answer = 0;
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    for(int i = 1; i <= str1.size(); i++)
    {
        for(int j = 1; j <= str2.size(); j++)
        {
            if(str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    answer = dp[str1.size()][str2.size()];
    return answer;
}

int main()
{
    Solution& s = Solution::getInstance(); 
    s.input();
    cout << s.solve() << "\n";

    return 0;
}