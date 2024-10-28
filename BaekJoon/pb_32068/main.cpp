#include <iostream>

#define endl "\n"

using namespace std;
using ll = long long;
using st = short;

ll L, R, S;

ll solution()
{
    ll answer = 0;

    if(R - S <= S - L)
        answer = (R - S) * 2;
    else
        answer = (S - L) * 2 + 1;

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    st cnt;
    cin >> cnt;

    for(st i = 0; i < cnt; ++i)
    {
        cin >> L >> R >> S;
        cout << solution() << endl;
    }

    return EXIT_SUCCESS;
}