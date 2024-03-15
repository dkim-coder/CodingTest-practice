#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 소수 판별 여부 함수 필요
bool isPrime(int num)
{
    if (num <= 1)
        return false;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int solution(string numbers)
{
    int answer = 0;
    vector<int> vec_numbers(numbers.length(), 0);
    vector<int> check(numbers.length(), 0);

    for (auto i : numbers)
        vec_numbers.push_back(atoi(i));

    for (int i = 1; i <= vec_numbers.size(); i++)
    {
        vector<int> vec_tmp_numbers;
        do
        {
        }
    }

    return answer;
}

int main()
{
    string numbers_1 = "17";
    string numbers_2 = "001";

    cout << solution(numbers_1) << endl;
    cout << solution(numbers_2) << endl;

    return EXIT_SUCCESS;
}