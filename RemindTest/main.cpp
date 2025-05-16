#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

#if 0
int minCombinationCount(const vector<int>& weights, int target) {
    unordered_set<int> oneTurnWeights;

    int n = weights.size();
    for (int mask = 1; mask < (1 << n); ++mask) {
        int sum = 0;
        for (int i = 0; i < n; ++i)
            if (mask & (1 << i)) sum += weights[i];
        oneTurnWeights.insert(sum);
    }

    queue<pair<int, int>> q;
    unordered_set<int> visited;
    q.push({0, 0});
    visited.insert(0);

    while (!q.empty()) {
        auto [curr, steps] = q.front();
        q.pop();

        for (int add : oneTurnWeights) {
            int next = curr + add;
            if (next == target)
                return steps + 1;
            if (next < target && !visited.count(next)) {
                visited.insert(next);
                q.push({next, steps + 1});
            }
        }
    }

    return -1;
}
#endif

int minCombinationCount(const std::vector<int>& weights, int target) {
    vector<int> usableWeights;

    int n = weights.size();
    for (int mask = 1; mask < (1 << n); ++mask) {
        int sum = 0;
        for (int i = 0; i < n; ++i)
            if (mask & (1 << i)) sum += weights[i];
        usableWeights.push_back(sum);
    }

    const int INF = INT_MAX / 2;
    vector<int> dp(target + 1, INF);    // 벡터로 목표 타게팅
    dp[0] = 0;

    for (int i = 0; i <= target; ++i) {
        if (dp[i] == INF) 
            continue;
        for (int w : usableWeights) {   // 가능 것들 업데이트
            if (i + w <= target)
                dp[i + w] = min(dp[i + w], dp[i] + 1);
        }
    }

    return dp[target] == INF ? -1 : dp[target];
}

int main() {
    vector<int> weights = {18, 20, 28};
    int target = 45;

    int result = minCombinationCount(weights, target);
    cout << "최소 횟수: " << result << endl;

    return 0;
}
