#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int distReturn(pair<int, int> p1, pair<int, int> p2)
{
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> houses;
    vector<int> check(n, 1);
    for (int i = 0; i < n; i++)
    {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        houses.push_back(tmp);
    }
    for (int i = 0; i < m; i++)
        check[i] = 0;

    int res = 999999;
    do
    {
        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            if (check[i])
            { // 1 이면 대피소
                for (int j = 0; j < n; j++)
                {
                    if (!check[j])
                    {
                        int dist = distReturn(houses[i], houses[j]);
                        if (dist > tmp)
                            tmp = dist;
                    }
                }
            }
        }
        if (tmp < res)
            res = tmp;
    } while (next_permutation(check.begin(), check.end()));

    cout << res << endl;

    return EXIT_SUCCESS;
}