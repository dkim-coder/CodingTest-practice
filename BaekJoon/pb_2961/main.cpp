#include <iostream>
#include <vector>

#define EXIT_SUCCESS 0
#define endl '\n'

using namespace std;

using pii = pair<int, int>;

short N;
vector<pii> ingredients;
vector<bool> selected;

inline void input()
{
    cin >> N;
    ingredients.resize(N);
    for (auto i = 0; i < N; i++)
        cin >> ingredients[i].first >> ingredients[i].second;

    return;
}

const int solution()
{
    int ans = INT32_MAX;
    input();
    for(int i = 1; i < (1 << N); i++)
    {
        int sour = 1, bitter = 0;
        for(int j = 0; j < N; j++)
        {
            if(i & (1 << j))
            {
                sour *= ingredients[j].first;
                bitter += ingredients[j].second;
            }
        }
        ans = min(ans, abs(sour - bitter));
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solution() << endl;

    return EXIT_SUCCESS;
}