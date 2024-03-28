#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 시간초과 나는 것.
// 순열과 정렬을 사용해 해결하려 했음.
/*
int solution(int distance, vector<int> rocks, int n) // 각 지점 사이의 최솟 값 중에 가장 큰 값을 retrun
{
    // rocks.size() - n 개를 선택하는 거지 순서 상관 없이
    int answer = 0;
    vector<bool> vec(rocks.size(), false);
    for (int i = 0; i < vec.size() - n; i++)
        vec[i] = true;

    sort(rocks.begin(), rocks.end());
    sort(vec.begin(), vec.end());

    do
    {
        vector<int> tmp;
        tmp.push_back(0);
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i])
            {
                tmp.push_back(rocks[i]);
            }
        }
        tmp.push_back(distance);

        int cur_min = 999999;

        for (int i = 1; i < tmp.size(); i++)
        {
            if (tmp[i] - tmp[i - 1] < cur_min)
                cur_min = tmp[i] - tmp[i - 1];
        }

        if (cur_min > answer)
            answer = cur_min;
    } while (next_permutation(vec.begin(), vec.end()));

    return answer;
}
*/

/*
int getRemovedRockCnt(vector<int> rocks, int mid, int dist)
{
    int before = 0;
    int end = dist;

    int removeCnt = 0;
    for (int i = 0; i < rocks.size(); i++)
    {
        if (rocks[i] - before < mid)
        {
            removeCnt++;
            continue;
        }
        before = rocks[i];
    }
    if (end - before < mid)
        removeCnt++;

    return removeCnt;
}

int solution(int distance, vector<int> rocks, int n)    // 마찬가지로 dist가 10억이상이니 dist 에 대해 이분탐색을 할 것이다 라는 아이디어를 얻을 수 있음.
{
    int answer = 0;

    sort(rocks.begin(), rocks.end());

    int left = 1;
    int right = distance;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (getRemovedRockCnt(rocks, mid, distance) <= n)
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return answer;
}
*/

int getRemovedRockCnt(vector<int> rocks, int mid, int dist)     // 지점간 최소 거리가 mid 일때 돌이 몇개 제거되는지
{
    int bef = 0;
    int cnt = 0;

    for(int i=0;i<rocks.size();i++)
    {
        if(rocks[i] - bef < mid)
        {
            cnt++;
            continue;
        }else{
            bef = rocks[i];
        }
    }

    if(dist - bef < mid)
        cnt++;

    return cnt;
}

int solution(int distance, vector<int> rocks, int n) // 마찬가지로 dist가 10억이상이니 dist 에 대해 이분탐색을 할 것이다 라는 아이디어를 얻을 수 있음.
{
    int answer = 0;
    sort(rocks.begin(), rocks.end());

    int left = 0;
    int right = distance;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (getRemovedRockCnt(rocks, mid, distance) <= n)   // mid 가 의미 하는 것이 지점간 최소 거리를 의미함
        {
            left = mid + 1;
            answer = mid;
        }
        else
        {
            right = mid - 1;
        }
    }

    return answer;
}

int main()
{
    int distance = 25;                       // 출발지점 부터 도착 지점 까지의 거리
    vector<int> rocks = {2, 14, 11, 21, 17}; // 바위가 있는 좌표
    int n = 2;                               // 제거할 바위의 수

    cout << solution(distance, rocks, n) << endl;

    return EXIT_SUCCESS;
}