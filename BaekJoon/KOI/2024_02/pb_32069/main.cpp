#include <stdio.h>
#include <queue>
#include <set>

using namespace std;

long long l, a;
int n, k;
const long long dx[] = {-1, 1}; // 왼쪽과 오른쪽으로 이동하기 위한 배열
queue<pair<long long, long long>> q; // BFS를 위한 큐, (위치, 거리)
set<long long> visited; // 방문한 위치를 저장하는 집합

// 위치가 도로 범위 내에 있는지 확인하는 함수
bool isPossible(long long x) {
    return 0 <= x && x <= l;
}

int main() {
    // 도로 길이, 가로등 개수, 출력할 위치 개수를 입력 받는다
    scanf("%lld%d%d", &l, &n, &k);
    
    // 각 가로등의 위치를 입력 받고 큐에 추가, 방문 표시
    for (int i = 0 ; i < n ; ++i) {
        scanf("%lld", &a);
        q.push({ a, 0 });
        visited.insert(a);
    }
    
    // BFS 시작
    while (!q.empty()) {
        long long here = q.front().first;
        long long dist = q.front().second;
        q.pop();
        
        // 현재 위치의 어두운 정도 (가장 가까운 가로등까지의 거리)를 출력
        printf("%lld\n", dist);
        --k;
        
        // K개의 위치를 모두 출력했으면 프로그램 종료
        if (k == 0) {
            return 0;
        }
        
        // 현재 위치의 왼쪽과 오른쪽 이웃을 탐색
        for (int i = 0 ; i < 2 ; ++i) {
            long long there = here + dx[i];
            
            // 이웃 위치가 도로 범위 내에 있고 아직 방문하지 않았다면 큐에 추가
            if (isPossible(there) && !visited.count(there)) {
                q.push({ there, dist + 1 });
                visited.insert(there);
            }
        }
    }
}