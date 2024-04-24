#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
N개 집이 수직선 위에 존재 C개 공유기 설치 가장 인접한 두 공유기 거리가 최대
조합 돌리고, 이중 최단을 찾게?
*/

bool compare(long long a, long long b)
{
    return a < b;
}

long long solution(int n, int m, vector<long long> home)
{
    long long res = 0;
 
    sort(home.begin(), home.end(), compare);
    vector<bool> check(n, false);
    for (int i = 0; i < m; i++)
        check[i] = true;
    sort(check.begin(), check.end());
    
    do
    {
        vector<long long> tmp;
        vector<long long> tmp_dix(m - 1);
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (check[i])
            {
                tmp.push_back(home[i]);
                if(idx)
                    tmp_dix[idx - 1] = tmp[idx] - tmp[idx - 1];
                idx++;
            }
        }

        long long t = *min_element(tmp_dix.begin(), tmp_dix.end());
        if (res < t)
            res = t;

    } while (next_permutation(check.begin(), check.end()));

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> home(n);
    for (int i = 0; i < n; i++)
        cin >> home[i];

    cout << solution(n, m, home) << endl;

    return EXIT_SUCCESS;
}