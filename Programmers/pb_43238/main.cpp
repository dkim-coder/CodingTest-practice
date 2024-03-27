#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
하나가 10억 이상씩 엄청 크다고 하면 이분 탐색을 고려해 볼 수 있음.
-> 큰것에 대해 이분탐색을 한다고 생각하면 됨.
key : 탐색을 시간에 대해서 하게 됨. 시간의 탐색 범위는 최대 n * 최대로 걸리는 심사위원임
-> 시간에 대해 몇명이 가능한지만 각 심사위원이 해당 시간에 몇명 심사할 수 있는지로 생각하면됨.
*/

bool isCan(int n, vector<int> times, long long t)
{
    long long cnt = 0;
    for (auto i : times)
    {
        cnt += t / (long long)i;
    }

    if (cnt >= (long long)n)
        return true;

    return false;
}

long long solution(int n, vector<int> times)
{
    sort(times.begin(), times.end());
    long long answer = 0;
    long long start = 1;
    long long end = *(times.end() - 1) * static_cast<long long>(n);
    long long mid;

    while (start <= end)    // 이분 탐색 종료 조건
    {
        mid = (start + end) / 2;
        bool res = isCan(n, times, mid);

        if (res)
        {
            answer = mid;   // 처리할 수 있기 때문에 값을 대입
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return answer;
}

int main()
{
    int n = 6;
    vector<int> times = {7, 10};

    cout << "answer : " << solution(n, times) << endl;

    return EXIT_SUCCESS;
}