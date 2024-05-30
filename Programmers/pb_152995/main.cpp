#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(const vector<vector<int>> &scores)
{
    int res = 1;
    int target = scores[0][0] + scores[0][1];

    for (int i = 1; i < scores.size(); i++)
    {
        if (scores[i][0] + scores[i][1] > target)
        {
            for(int j = 0; j < scores.size(); j++)
            {
                if(scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1])
                {
                    res--;
                    break;
                }
            }
            res++;
            if (scores[i][0] > scores[0][0] && scores[i][1] > scores[0][1])
                return -1;
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> scores = {{2, 2}, {1, 4}, {3, 2}, {3, 2}, {2, 1}};

    cout << solution(scores) << endl;

    return EXIT_SUCCESS;
}