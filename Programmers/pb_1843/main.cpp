#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
사칙연산 문제

연산자 종류에 따라 경우를 나누어 주어야 한다.
    더하기의 경우 최대 + 최대 -> 최댓 값 계산 가능. / 최소 + 최소 -> 최소 값 계산 가능.
    빼기의 경우 최대 - 최소 -> 최댓 값 계산 가능. / 최소 - 최대 -> 최소 값 계산 가능.
최대 최소를 저장하기 위해 두 타입의 저장소가 필요하다. -> 각 연산자에 따라 최대를 계산하기 위한 조건이 달라지기 때문임.

k 는 연산자 인덱스를 나타냄.
"-" 인 경우
max_dp = i ~ k 까지 계산한 값의 최대값 - k + 1 ~ j 까지 계산한 값의 최소값
min_dp = i ~ k 까지 계산한 값의 최소값 - k + 1 ~ j 까지 계산한 값의 최대값

"+" 인 경우
max_dp = i ~ k 까지 계산한 값의 최대값 + k + 1 ~ j 까지 계산한 값의 최대값
min_dp = i ~ k 까지 계산한 값의 최소값 + k + 1 ~ j 까지 계산한 값의 최소값
*/

int solution(vector<string> arr)
{
    int res = -1;
    int max_dp[102][102] = {
        0,
    };
    int min_dp[102][102] = {
        0,
    };
    int numSize = arr.size() / 2 + 1;   // 숫자 개수를 나타냄.

    for (int i = 0; i < numSize; i++)
    {
        for (int j = 0; j < numSize; j++)
        {
            if (i == j)
            {
                max_dp[i][j] = stoi(arr[i * 2]);    // 숫자 인덱스 위치임.
                min_dp[i][j] = stoi(arr[i * 2]);
            }
            else
            {
                max_dp[i][j] = -10000000;
                min_dp[i][j] = 10000000;
            }
        }
    }

    for (int index = 1; index < numSize; index++)
    {
        for (int i = 0; i < numSize - index; i++)   // 부호 위치를 기준으로 앞쪽에서 나오는 최댓 값 체크 필요.
        {
            int j = index + i;
            for (int k = i; k < j; k++)     // 부호 위치를 기준으로 뒤쪽에서 나오는 최댓 값 체크 필요.
            {
                if (arr[k * 2 + 1] == "-")
                {
                    max_dp[i][j] = max(max_dp[i][j], max_dp[i][k] - min_dp[k + 1][j]);  // 해당 부호 위치에 따라. 기존에 저장된 값을 사용
                    min_dp[i][j] = min(min_dp[i][j], min_dp[i][k] - max_dp[k + 1][j]);
                }
                else if (arr[k * 2 + 1] == "+")
                {
                    max_dp[i][j] = max(max_dp[i][j], max_dp[i][k] + max_dp[k + 1][j]);
                    min_dp[i][j] = min(min_dp[i][j], min_dp[i][k] + min_dp[k + 1][j]);
                }
            }
        }
    }

    res = max_dp[0][numSize - 1];
    return res;
}

int main()
{
    vector<string> arr1 = {"1", "-", "3", "+", "5", "-", "8"};
    vector<string> arr2 = {"5", "-", "3", "+", "1", "+", "2", "-", "4"};

    cout << "Answer 1 : " << solution(arr1) << endl;
    cout << "Answer 2 : " << solution(arr2) << endl;

    return EXIT_SUCCESS;
}