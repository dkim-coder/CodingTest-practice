#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

/*
문제 설명사람을 모두 태울 수 있는 가장 작은 구명보트 개수 구하기
*/

int solution(vector<int> people, int limit)
{
    int answer = 0;
    deque<int> dq;

    for (auto i : people)
        dq.push_back(i);

    sort(dq.begin(), dq.end());

    int cur_cnt = 0;
    while (cur_cnt < people.size())
    {
        if (dq.size() == 1)
        {
            cur_cnt++;
        }
        else if (dq.back() + dq.front() <= limit)
        {
            cur_cnt+=2;
            dq.pop_back();
            dq.pop_front();
        }
        else
        {
            cur_cnt++;
            dq.pop_back();
        }
            answer++;

    }

    return answer;
}

int main()
{
    vector<int> people = {70, 50, 80, 50};
    int limit = 100;

    cout << solution(people, limit);

    return EXIT_SUCCESS;
}