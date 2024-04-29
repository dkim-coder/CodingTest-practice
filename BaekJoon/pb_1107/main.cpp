#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool isPossible(int n, vector<bool> number)
{
    string s = to_string(n);

    for (int i = 0; i < s.size(); i++)
    {
        if (!number[s[i] - '0'])
            return false;
    }
    return true;
}

int solution(string channel, int n, vector<bool> number)
{
    int res = 0;

    res = abs(stoi(channel) - 100);

    for (int i = 0; i <= 1000000; i++)  // 단순하게 1 부터 끝까지 모두 체크하게 하는데, 해당 번호를 바로 누를 수 없으면 안된다. 그걸 isPossible 로 체크해 주는 것
    {
        if (isPossible(i, number))
        {
            int tmp = abs(stoi(channel) - i) + to_string(i).size();
            res = min(res, tmp);
        }
    }

    return res;
}

int main()
{
    string channel;
    int n;
    cin >> channel >> n;
    vector<bool> number(10, true); // true면 정상 작동 버튼을 나타냄
    for (int i = 0; i < n; i++)
    {
        int idx;
        cin >> idx;
        number[idx] = false;
    }

    if (channel == "100")
    {
        cout << 0 << endl;
        return EXIT_SUCCESS;
    }

    cout << solution(channel, n, number) << endl;

    return EXIT_SUCCESS;
}