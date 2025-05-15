#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'

using namespace std;

int n;
vector<string> v;

inline void input()
{
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    return;
}

void solve()
{
    input();

    vector<long long> nums;
    for(string &str: v){
        reverse(str.begin(), str.end());    // 문자열 뒤집기
        int idx = 0;
        while(true)
        {
            if(str[idx++] != '0')
                break;

            if(idx == str.length())
                break;
        }
        nums.push_back(stol(str.substr(idx - 1)));
    }
    
    sort(nums.begin(), nums.end(), less<long long>());

    for(const long long &num : nums)
        cout << num << endl;

    return;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}