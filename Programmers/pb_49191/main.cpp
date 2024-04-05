#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
{4, 3} 4번 선수가 3번 선수를 이긴 것을 뜻함
정확히 등수를 판단할 수 있는 기준이 필요함
1 명이 확실하게 정해지면 어떻게 되지
*/

int solution(int n, vector<vector<int>> results)
{
    int answer = 0;
    return answer;
}

int main()
{
    int n = 5;
    vector<vector<int>> results = {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};

    cout << "Answer : " << solution(n, results) << endl;

    return EXIT_SUCCESS;
}