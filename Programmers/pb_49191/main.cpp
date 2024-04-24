#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<vector<bool>> &b_results) // 플로이드 알고리즘의 변형
{
    int res = 0;

    // O(n^3)
    for (int i = 1; i <= n; i++)
    {
        for (int win = 1; win <= n; win++)
        {
            for (int lose = 1; lose <= n; lose++)
            {
                if (b_results[win][i] && b_results[i][lose])    // win 이 i 를 이기고, i 가 lose 를 이기면 win 이 lose 를 이긴다는 정보를 축적해 나가는것
                    b_results[win][lose] = true;    // 이긴 정보를 그래프에 축적
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (b_results[i][j] || b_results[j][i]) 
                cnt++;
        }   
        if (cnt == n - 1)   // 정보가 n - 1 개 모두 있는거 파악
            res++;
    }

    return res;
}

int main()
{
    int n = 5;
    vector<vector<int>> results = {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};
    vector<vector<bool>> b_results(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < results.size(); i++)
        b_results[results[i][0]][results[i][1]] = true;

    cout << solution(n, b_results) << endl;

    return EXIT_SUCCESS;
}