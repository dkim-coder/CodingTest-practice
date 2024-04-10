#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

long long solution(int n, vector<int> works)
{
    long long answer = 0;

    sort(works.begin(), works.end(), compare); // 내림 차순 정렬

    int cur;
    int cnt = 0;
    while (true)
    {
        cur = works[0];
        if (cnt == n || cur == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            if (cur == works[i])
            {
                works[i] -= 1;
                if (++cnt == n)
                    break;
            }
            else
            {
                break;
            }
        }
    }

    for (auto w : works)
    {
        answer += pow(w, 2);
    }

    return answer;
}

int main()
{
    int n = 4;
    vector<int> works = {4, 3, 3};

    cout << "Answer : " << solution(n, works) << endl;

    return EXIT_SUCCESS;
}