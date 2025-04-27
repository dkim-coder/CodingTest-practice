#include <iostream>
#include <vector>

using namespace std;

int solution(int n)
{
    if (n < 2)
        return 1;

    vector<vector<int>> dragon_ages(n + 1, vector<int>(n + 1, 0)); // [날짜][드래곤 나이] 드래곤 수
    vector<int> eggs(n + 1, 0);                                    // 드래곤 알의 수
    eggs[0] = 1;

    for (int day = 1; day <= n; day++)
    {
        eggs[day] = eggs[day - 1]; // 이전 날 알수 로 현재 날의 알 수 업데이트

        if (day >= 2)
        {
            int hatched_eggs = 0;
            if (day == 2)
                hatched_eggs = 1; // 초기 알 부화
            else
            {
                int breeding_dragons = 0; // 2일 전의 알 들의 부화
                for (int age = 0; age < day - 2; age++)
                    if (age < 4)
                        breeding_dragons += dragon_ages[day - 2][age];
                hatched_eggs = breeding_dragons;
            }

            eggs[day] -= hatched_eggs;  // 부화한 알 수 만큼 알의 개수 감소 시켜야함
            dragon_ages[day][0] = hatched_eggs;
        }

        for (int age = day - 1; age > 0; age--)
            dragon_ages[day][age] = dragon_ages[day - 1][age - 1];  // 드래곤들의 나이 업데이트

        int new_eggs = 0;
        for (int age = 0; age < 4 && age < day; age++)  // 드래곤 알 수 업데이트
            new_eggs += dragon_ages[day][age];
        eggs[day] += new_eggs;
    }

    int dragons_unable = 0;
    int dragons_able = 0;

    for (int age = 0; age <= n; age++)
    {
        if (age < 4)
            dragons_able += dragon_ages[n][age];
        else
            dragons_unable += dragon_ages[n][age];
    }
    
    return dragons_unable + dragons_able + eggs[n];
}

int main(int argc, char **argv)
{
    cout << "결과: " << solution(6) << endl;
    
    return 0;
}