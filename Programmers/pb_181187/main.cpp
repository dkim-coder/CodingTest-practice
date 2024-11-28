#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define endl "\n"
#if 0
#define DIST(X, Y) sqrt(pow(X, 2) + pow(Y, 2)) 

inline bool check(const int &r1, const int &r2, float dist)
{
    return dist >= r1 && dist <= r2; 
}
#endif

long long solution(int r1, int r2) {
    long long answer = 0;
    answer *= 4;

    for(int i = 1; i < r2 + 1; i++)
    {
        if(i < r1)
            answer += floor(sqrt(pow(r2, 2) - pow(i, 2))) - ceil(sqrt(pow(r1 , 2) - pow(i, 2))) + 1;
        else
            answer += floor(sqrt(pow(r2, 2) - pow(i, 2)) + 1);
    }
    answer *= 4;

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int r1, r2;
    r1 = 2;
    r2 = 3;

    cout << solution(r1, r2) << endl;

    return EXIT_SUCCESS;
}