#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2)
{
    int answer = 0;

    int start = h1 * 3600 + m1 * 60 + s1;   // 초로 변환
    int end = h2 * 3600 + m2 * 60 + s2;

    if (start % 360 == 0 || start % 360 == 12)
        answer++;

    while (start < end)
    {
        double c_h, c_m, c_s;
        double n_h, n_m, n_s;

        c_h = (start / (double)120) / 360 - (start / 120) / 360;
        c_m = (start / (double)10) / 360 - (start / 10) / 360;
        c_s = (start * (double)6) / 360 - (start * 6) / 360;

        n_h = ((start + 1) / (double)120) / 360 - ((start + 1) / 120) / 360;
        n_m = ((start + 1) / (double)10) / 360 - ((start + 1) / 10) / 360;
        n_s = ((start + 1) * (double)6) / 360 - ((start + 1) * 6) / 360;

        if (n_h == 0)
            n_h = 360;
        if (n_m == 0)
            n_m = 360;
        if (n_s == 0)
            n_s = 360;

        if (c_s < c_h && n_s >= n_h)
            answer++;
        if (c_s < c_m && n_s >= n_m)
            answer++;

        if (n_h == n_m)
            answer--;

        start++;
    }

    return answer;
}

int main()
{
    int h1 = 0;
    int m1 = 5;
    int s1 = 30;
    int h2 = 0;
    int m2 = 7;
    int s2 = 0;

    cout << solution(h1, m1, s1, h2, m2, s2) << endl;

    return EXIT_SUCCESS;
}