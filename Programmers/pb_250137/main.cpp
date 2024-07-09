#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks)
{
    int answer = 0;
    int cur_health = health;
    int past_time = 0;

    for (const auto &a : attacks)
    {
        cur_health += (a[0] - past_time - 1) * bandage[1] + (a[0] - past_time - 1) / bandage[0] * bandage[2];
        if (cur_health > health)
            cur_health = health;
        cur_health -= a[1];
        if (cur_health <= 0)
            return -1;
        past_time = a[0];
    }
    answer = cur_health;

    return answer;
}

int main()
{
    vector<int> bandage = {5, 1, 5}; // 시전시간, 1초당 회복량, 추가 회복량
    int health = 30;
    vector<vector<int>> attacks = {{2, 10}, {9, 15}, {10, 5}, {11, 5}};

    cout << solution(bandage, health, attacks) << endl;

    return EXIT_SUCCESS;
}