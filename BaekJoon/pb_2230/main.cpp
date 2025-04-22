#include <iostream>
#include <cstring>
#include <algorithm>

#define endl '\n'

using namespace std;

static int n, m;
static int arr[100000];

inline void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    return;
}

int solve()
{
    int ans = INT32_MAX;

    input();

    sort(&arr[0], &arr[n], less<int>());
    int left, right;
    int tmp;

    left = 0; right = 0;
    while(true)
    {
        tmp = arr[right] - arr[left];

        if(tmp < m){
            right++;
            if(right == n)
                break;
            continue;
        }else if(tmp == m)
            return m;
        else{
            ans = min(ans, tmp);
            left++;
        }
    }

    return ans;
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve() << endl;

    return EXIT_SUCCESS;
}