#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
dp[i] = max(dp[i - 1] + sequence[i], sequence[i])
*/

long long solution(vector<int> sequence)
{
    long long res = 0;
    int n = sequence.size();

    vector<int> seq1;
    vector<int> seq2;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            seq1.push_back(sequence[i]);
            seq2.push_back(-sequence[i]);
        }
        else
        {
            seq1.push_back(-sequence[i]);
            seq2.push_back(sequence[i]);
        }
    }

    vector<long long> dp1(n);
    vector<long long> dp2(n);

    dp1[0] = seq1[0];
    dp2[0] = seq2[0];
    for (int i = 1; i < n; i++)
    {
        dp1[i] = max(dp1[i - 1] + (long long)seq1[i], (long long)seq1[i]);
        dp2[i] = max(dp2[i - 1] + (long long)seq2[i], (long long)seq2[i]);
    }

    long long max1 = *max_element(dp1.begin(), dp1.end());
    long long max2 = *max_element(dp2.begin(), dp2.end());
    res = max1 > max2 ? max1 : max2;

    return res;
}

int main()
{
    vector<int> sequence = {2, 3, -6, 1, 3, -1, 2, 4}; // 최대 500,000

    cout << solution(sequence) << endl;

    return EXIT_SUCCESS;
}