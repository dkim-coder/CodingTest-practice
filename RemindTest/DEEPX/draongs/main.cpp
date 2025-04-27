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

        // 2일 지난 알 들은 부화
        if (day >= 2)
        {
            int hatched_eggs = 0;
            if (day == 2)
                hatched_eggs = 1; // 초기 알 부화
            else
            {
                int breeding_dragons = 0; // 2일 전의 알 들의 부화
                for (int age = 0; age < day - 2; age++)
                    // 나이가 0~3일인 드래곤만 알을 낳을 수 있음
                    if (age < 4)
                        breeding_dragons += dragon_ages[day - 2][age];
                hatched_eggs = breeding_dragons;
            }

            // 알 감소, 나이 0인 드래곤 증가
            eggs[day] -= hatched_eggs;
            dragon_ages[day][0] = hatched_eggs;
        }

        // 3. 이전 날의 드래곤들 나이 증가
        for (int age = day - 1; age > 0; age--)
        {
            dragon_ages[day][age] = dragon_ages[day - 1][age - 1];
        }

        // 4. 알을 낳을 수 있는 드래곤들이 알을 낳음 (나이 0~3인 드래곤)
        int new_eggs = 0;
        for (int age = 0; age < 4 && age < day; age++)
        {
            new_eggs += dragon_ages[day][age];
        }
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