#include <iostream>
#include <vector>
#include <algorithm> // 사실 안 써도 되는데 귀찮으니

using namespace std;

/*
삼각형에서 거쳐간 숫자의 최댓값을 찾는 문제
왼쪽 아래 오른쪽 아래 둘중 하나만 갈 수 있음
*/

int solution(vector<vector<int>> triangle)
{
    int res = 0;

    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            // -1, 0 이렇게 두 개 가능
            if (j == 0)
                triangle[i][0] += triangle[i - 1][0];
            else if (j == triangle[i].size() - 1)
                triangle[i][triangle[i].size() - 1] += triangle[i - 1][triangle[i - 1].size() - 1];
            else
            {
                triangle[i][j] += (triangle[i - 1][j - 1] > triangle[i - 1][j]) ? triangle[i - 1][j - 1] : triangle[i - 1][j];
            }
        }
    }

    res = *max_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());

    return res;
}

int main()
{
    vector<vector<int>> triangle = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};

    cout << solution(triangle) << endl;

    return EXIT_SUCCESS;
}