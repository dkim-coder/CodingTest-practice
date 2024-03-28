#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    vector<bool> check(number.length(), true);

    char c_num = '9';
    int cnt = 0;
    int before = 0;
    while (true)
    {
        // 랭킹에 따른 로컬 최적 선택
        int tmp_cnt = 0;
        bool tmp_check = false;
        for (int i = before; i < number.length(); i++)
        {
            if (number[i] == c_num && tmp_cnt + cnt <= k)
            {
                for (int j = before; j < i; j++)
                {
                    check[j] = false;
                    cnt++;
                }
                before = i + 1;
                c_num = '9';
                tmp_check = true;
                break;
            }
            tmp_cnt++;
        }
        if (!tmp_check)
            c_num -= 1;
        // 제약사항 위반체크 -> 이 문제에서는 제약사항이 따로 없을 것 같음.

        // 문제 종결 체크
        if (cnt == k || before == number.length() - 1)
            break;
    }

    if (cnt != k)
    {
        for (int i = check.size() - 1; i >= 0; i--)
        {
            if (check[i])
            {
                check[i] = false;
                cnt++;
                if (cnt == k)
                    break;
            }
        }
    }

    for (int i = 0; i < check.size(); i++)
    {
        if (check[i])
            answer += number[i];
    }

    return answer;
}

int main()
{
    string number = "333221";
    int k = 2;

    cout << "Answer : " << solution(number, k) << endl;

    return EXIT_SUCCESS;
}