#include <iostream>
#include <vector>

using namespace std;

short N;
vector<int> X, T;

int solution()
{
    int answer = 0;

    // 처음부터 끝으로 이동하고 돌아오면서 체크하면 됨
    answer = X[N];   
    
    for(short i = N; i > 0; i--)
    {
        if(answer < T[i])
            answer = T[i];
        answer += X[i] - X[i - 1];
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    int tmp;
    X.push_back(0);
    for (short i = 0; i < N; i++)
    {
        cin >> tmp;
        X.push_back(tmp);
    }

    T.push_back(0);
    for (short i = 0; i < N; i++)
    {
        cin >> tmp;
        T.push_back(tmp);
    }

    cout << solution() << "\n";

    return 0;
}