#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool resolve(const vector<int> &diffs, const vector<int> &times, const long long &limit, const int &level)
{
    long long spend_time = 0;
    
    spend_time = times[0];
    for(int i = 1; i < diffs.size(); i++)
    {
        if(diffs[i] <= level)
            spend_time += times[i];
        else{
            int repeat_times = diffs[i] - level;
            spend_time += (times[i - 1] + times[i]) * repeat_times + times[i];
        }
    }

    return spend_time <= limit ;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int max_level = *max_element(diffs.begin(), diffs.end());
    int min_level = 1;
    int mid_level = (max_level + min_level) / 2;

    answer = max_level;
    while(min_level <= max_level)   // 4 5 6
    {
        if(resolve(diffs, times, limit, mid_level))
        {
            answer = min(answer, mid_level);
            max_level = mid_level - 1;
            mid_level = (min_level + max_level) / 2;
        }else{
            min_level = mid_level + 1;
            mid_level = (min_level + max_level) / 2;
        }
    }

    return answer;
}

int main()
{
    vector<int> diffs = {1, 328, 467, 209, 54};
    vector<int> times = {2, 7, 1, 4, 3};
    long long limit = 1723;

    cout << solution(diffs, times, limit) << "\n";

    return EXIT_SUCCESS;
}