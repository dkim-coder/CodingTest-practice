#include <stdio.h>
#include <algorithm>

using namespace std;

int n, q, l, r;
long long X[200010], P[200010];

/**
 * 특정 집에서 회의를 개최할 때의 비용을 계산하는 함수
 * @param i - 회의 세트에 포함된 집들의 시작 인덱스
 * @param j - 회의 세트에 포함된 집들의 끝 인덱스
 * @param k - 회의를 개최하는 집의 인덱스
 * @return - 집 k에서 모일 때의 총 비용
 */
long long getCost(int i, int j, int k) {
    long long leftCost = (long long)(k - i + 1) * X[k] - (P[k] - P[i - 1]);
    long long rightCost = (P[j] - P[k - 1]) - (long long)(j - k + 1) * X[k];
    
    return leftCost + rightCost;
}

int main() {
    // n: 집의 개수, q: 질의의 개수
    scanf("%d%d", &n, &q);
    
    // 집의 좌표와 누적 합 계산
    for (int i = 1 ; i <= n ; ++i) {
        scanf("%lld", &X[i]);
        P[i] = P[i - 1] + X[i];
    }
    
    // 각 질의에 대해 처리
    while (q--) {
        scanf("%d%d", &l, &r);
        // 주어진 범위 [l, r]에 해당하는 집의 인덱스 범위를 찾기 위해 이분 탐색 사용
        int lo = lower_bound(X + 1, X + n + 1, l) - X;
        int hi = upper_bound(X + 1, X + n + 1, r) - X - 1;
        
        // 범위 내에 집이 없을 경우
        if (lo >= hi) {
            puts("0");
        } else {
            // 최대 회의 비용과 최소 회의 비용 계산
            long long maxStress = max(getCost(lo, hi, lo), getCost(lo, hi, hi));
            long long minStress = getCost(lo, hi, (lo + hi) / 2);
            
            // 최소 피로도를 출력
            printf("%lld\n", maxStress - minStress);
        }
    }
}