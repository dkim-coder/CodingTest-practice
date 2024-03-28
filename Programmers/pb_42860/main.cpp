#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name)
{
    int answer = 0;

    answer = name.length() - 1;

    /*
    문제의 핵심부 : 좌우 이동을 최소화 해야함
    -> A가 연속적으로 나온 경우 돌아온 방향으로 틀지 그대로 진행 할 지 검사가 필요
    */
    for (int i = 1; i < name.length(); i++)
    {
        if (name[i] == 'A')
        {
            int left = i - 1;
            while (i < name.length() && name[i] == 'A')
                i++;
            int right = name.length() - i;

            answer = min(answer, 2 * right + left);
            answer = min(answer, 2 * left + right);
        }
    }

    for (auto i : name)     // 각 알파벳의 위아래 이동 횟수의 최솟 값은 아스키 코드를 활용해 쉽게 구하는 것이 가능함.
    {
        if (i == 'A')
            continue;

        int up = i - 'A';
        int down = 'Z' - i + 1;

        answer += min(up, down);
    }

    return answer;
}

int main()
{
    string name = "JEROEN";

    cout << "Answer : " << solution(name) << endl;

    return EXIT_SUCCESS;
}