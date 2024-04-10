#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
문제 핵심
2번 빼고 우선순위 큐에 계속 넣으면서 구해야 함
*/

// 우선 순위 큐의 정렬을 설정하기 위한 compare 사용법을 알야아 함.
struct compare{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int solution(int n, vector<int> cards)
{
    int res = 0;

    if(n == 1)
        return res;

    priority_queue<int, vector<int>, compare> pq;
    for(auto c : cards)
        pq.push(c);

    while(true)
    {
        int a,b, tmp;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();

        tmp = a + b;
        res += tmp;
        if(pq.empty())
            break;
        pq.push(tmp);
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> cards;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        cards.push_back(tmp);
    }

    cout << solution(n, cards) << endl;

    return EXIT_SUCCESS;
}