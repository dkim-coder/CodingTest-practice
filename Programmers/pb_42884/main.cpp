 #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
첫 sorting 을 나가는 곳 기준으로 정렬해야 함
카메라의 위치가 나가는 지점에 설치 된다고 생각.
만약 다음 차의 경로의 시작 지점이 진출 지점보다 크다면 답은 1 증가시키고, 진출 지점을 업데이트함.
*/

bool compare(vector<int> v1, vector<int> v2)
{
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> routes)
{
    int answer = 1;

    sort(routes.begin(), routes.end(), compare);

    int pos = routes[0][1];

    for (int i = 0; i < routes.size(); i++)
    {
        if (pos < routes[i][0])
        {
            pos = routes[i][1];
            answer++;
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> routes = {{-20, -15}, {-14, -5}, {-18, -13}, {-5, -3}};

    cout << "Answer : " << solution(routes) << endl;

    return EXIT_SUCCESS;
}