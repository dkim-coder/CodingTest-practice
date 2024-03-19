#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
        return false;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(string numbers)
{
    unordered_set<int> us;  // 중복은 제거되는 세트 

    sort(numbers.begin(), numbers.end());

    do
    {
        for (int i = 0; i < numbers.length(); i++)
        {
            string tmp = numbers.substr(0, i + 1);  // 스트링의 서브 스트링 반환해주는 함수
            int num = stoi(tmp);    // 스트링 정수로 반환 해주는 함수
            if (isPrime(num))
                us.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    return us.size();
}

int main()
{
    string numbers_1 = "17";
    string numbers_2 = "001";

    cout << solution(numbers_1) << endl;

    return EXIT_SUCCESS;
}