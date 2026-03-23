#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#if 0
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);
    vector<int> dp(N, 1);   // dp[i]: i까지의 최대 부분 수열 길이
    int max_len = 1;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }   

    for (int i = 1; i < N; i++) {   // 갱신될 최대 부분 수열 길이 
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_len = max(max_len, dp[i]);
    }

    cout << max_len << "\n";

    return 0;
}
#endif

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> lis;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        // 크면 뒤에 이어 붙임
        if (lis.empty() || lis.back() < num) {
            lis.push_back(num);
        } 
        else {  // 작거나 같으면 -> 현재 정렬된 상태니까 크거나 같은 젤 앞에거 찾아서 바꿔버림 -> 작게 바꿀수록 뒤에 큰걸 앞 if에 걸릴 확률이 늘어나니까
            auto it = lower_bound(lis.begin(), lis.end(), num);
            *it = num; 
        }
    }

    cout << lis.size() << "\n";

    return 0;
}