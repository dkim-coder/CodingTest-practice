#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using PII = pair<int, int>;

int n;
vector<PII> v;

inline void input()
{
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second; // first: x, second: y

    return;
}

bool compare(const PII &a, const PII &b)
{
    return a.first < b.first;
}

const int solve()
{
    int ans = 0;

    input();
    sort(v.begin(), v.end(), compare);

    // 높 낮 높 이게 안되는거자나 낮 높 낲은 되도

    int acc = 0;
    for(const PII &cur : v)
    {
        // min -> min
        // up
    }

    return ans;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve() << endl;

    return 0;
}