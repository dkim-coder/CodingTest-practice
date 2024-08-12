#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int calDiff(const int &n, const vector<vector<int>> &s, const vector<int> &v)
{
    int res = 0;
    int left = 0;
    int right = 0;

    vector<int> left_idx;
    vector<int> right_idx;
    for(int i = 0; i < n; i++)
    {
        if(v[i] == 0)
            left_idx.push_back(i);
        else
            right_idx.push_back(i);
    }

    for (int i = 0; i < n / 2 - 1; i++)
    {
        for (int j = i + 1; j < n / 2; j++)
        {
            left += s[left_idx[i]][left_idx[j]];
            left += s[left_idx[j]][left_idx[i]];
            right += s[right_idx[i]][right_idx[j]];
            right += s[right_idx[j]][right_idx[i]];
        }
    }

    res = right - left;

    return abs(res);
}

int solution(const int &n, const vector<vector<int>> &s)
{
    int res = 999999;
    int tmp = 0;

    vector<int> v(n, 0);

    for (int i = n / 2; i < n; i++)
        v[i] = 1;

    do
    {
        tmp = calDiff(n, s, v);
        if (tmp < res)
            res = tmp;
    } while (next_permutation(v.begin(), v.end()));

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> s(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> s[i][j];
    }

    cout << solution(n, s) << "\n";

    return EXIT_SUCCESS;
}