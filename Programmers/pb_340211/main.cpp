#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    map<int, map<pair<int, int>, int>> M;

    for(int i = 0; i < routes.size(); ++i)
    {
        int StartPosX = points[routes[i][0] - 1][0];
        int StartPosY = points[routes[i][0] - 1][1];
        int Second = 0;

        M[Second][make_pair(StartPosX, StartPosY)] += 1;

        for(int j = 1; j <= routes[i].size() - 1; ++j)
        {
            int EndPosX = points[routes[i][j] - 1][0];
            int EndPosY = points[routes[i][j] - 1][1];

            while(true)
            {
                if(StartPosX == EndPosX)
                {
                    if(StartPosY == EndPosY)
                    {
                        break;
                    }
                    else if(StartPosY < EndPosY)
                    {
                        StartPosY += 1;
                    }
                    else
                    {
                        StartPosY -= 1;
                    }
                }
                else if(StartPosX < EndPosX)
                {
                    StartPosX += 1;
                }
                else
                {
                    StartPosX -= 1;
                }

                M[++Second][make_pair(StartPosX, StartPosY)] += 1;
            }
        }
    }

    for(const auto& X : M)
    {
        for(const auto& Y : X.second)
        {
            if(Y.second >= 2)
            {
                answer += 1;
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> points = {{3, 2}, {6, 4}, {4, 7}, {1, 4}};
    vector<vector<int>> routes = {{4, 2}, {1, 3}, {2, 4}};

    cout << solution(points, routes) << endl;

    return EXIT_SUCCESS;
}