#include <iostream>
#include <vector>
#include <algorithm>

#define SELECT_NUMS 6

using namespace std;
static int output[SELECT_NUMS];

void combination(const vector<int> &nums, const int cnt, const int idx)
{
    if(cnt == SELECT_NUMS)
    {
        for(int i = 0; i < SELECT_NUMS; i++)
            cout << output[i] << " ";
        cout << '\n';

        return;
    }

    for(int i = idx; i < nums.size(); i++)
    {
        output[cnt] = nums[i];
        combination(nums, cnt + 1, i + 1);
    }

    return;
}

void solve(const int &num)
{
    vector<int> nums(num);
    for(int i = 0; i < num; i++)
        cin >> nums[i];
    
    sort(nums.begin(), nums.end(), less<int>());
    combination(nums, 0, 0);

    return;
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    while(true)
    {
        cin >> num;
        if(!num)
            break;

        solve(num);
        cout << '\n';
    }

    return 0;
}