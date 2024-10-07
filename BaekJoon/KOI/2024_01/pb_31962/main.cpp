#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

short N, X;

int main()
{
    short answer = -1;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> X;
    pair<short, short> tmp;
    for (auto i = 0; i < N; i++)
    {
        cin >> tmp.first >> tmp.second;
        if(tmp.first + tmp.second <= X && tmp.first > answer)
            answer = tmp.first;
    }

    cout << answer << "\n";

    return 0;
}