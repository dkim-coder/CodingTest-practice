#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
Si 에 시작해서 Ti 에 끝나는 N 개 수업 주어짐
최소의 강의실을 사용해서 모든 수업을 가능하게 해야 함.
수업이 끝난 직후에 다음 수업 시작 가능 Ti <= Sj 면 i 와 j 수업은 같이 들을 수 있다
*/

struct compare
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int solution(int n, vector<pair<int, int>> v)
{
    priority_queue<int, vector<int>, compare> pq;   // 끝나는 시간 기준 우선순위 큐

    sort(v.begin(), v.end());   // 시작 시간으로 정렬

    pq.push(v[0].second);   // 처음 꺼 삽입하고

    for (int i = 1; i < n; i++)
    {
        pq.push(v[i].second);   // 다음꺼 끝나는 시간 삽입

        if (pq.top() <= v[i].first) // 하지만 만약 다음꺼 시작 시간이 끝나는 시간보다 크면 우선순위 큐에서 위에꺼 제거됨
            pq.pop();
    }

    return pq.size();   // 우선순위 큐 크기가 총 강의 실 개수가 됨
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        pair<int, int> tmp = {s, t};
        v.push_back(tmp);
    }

    cout << solution(n, v) << endl;

    return EXIT_SUCCESS;
}