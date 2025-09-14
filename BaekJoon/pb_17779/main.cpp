#include <bits/stdc++.h>
using namespace std;

int N;
int A[21][21];
int res;
int TOTAL; // 전체 인구 합

bool isValid(int x, int y, int d1, int d2) {
    return (x + d1 + d2 <= N && 1 <= y - d1 && y + d2 <= N);
}

void update(int x, int y, int d1, int d2) {
    static int area[21][21];
    memset(area, 0, sizeof(area));

    // 1) 경계선만 5로 표시
    for (int i = 0; i <= d1; ++i) {
        area[x + i][y - i] = 5;                 // 1번
        area[x + d2 + i][y + d2 - i] = 5;       // 4번
    }
    for (int i = 0; i <= d2; ++i) {
        area[x + i][y + i] = 5;                 // 2번
        area[x + d1 + i][y - d1 + i] = 5;       // 3번
    }

    // 2) 각 구역 인구 (경계선 전까지만 누적)
    int pop[6] = {0};

    // 1번 구역: r = 1..x+d1-1, c = 1..y (왼쪽→오른쪽, 5를 만나면 그 행 종료)
    for (int r = 1; r <= x + d1 - 1; ++r) {
        for (int c = 1; c <= y; ++c) {
            if (area[r][c] == 5) break;
            pop[1] += A[r][c];
        }
    }

    // 2번 구역: r = 1..x+d2, c = N..y+1 (오른쪽→왼쪽, 5를 만나면 그 행 종료)
    for (int r = 1; r <= x + d2; ++r) {
        for (int c = N; c >= y + 1; --c) {
            if (area[r][c] == 5) break;
            pop[2] += A[r][c];
        }
    }

    // 3번 구역: r = x+d1..N, c = 1..(y-d1+d2-1) (왼쪽→오른쪽, 5를 만나면 종료)
    for (int r = x + d1; r <= N; ++r) {
        for (int c = 1; c <= y - d1 + d2 - 1; ++c) {
            if (area[r][c] == 5) break;
            pop[3] += A[r][c];
        }
    }

    // 4번 구역: r = x+d2+1..N, c = N..(y-d1+d2) (오른쪽→왼쪽, 5를 만나면 종료)
    for (int r = x + d2 + 1; r <= N; ++r) {
        for (int c = N; c >= y - d1 + d2; --c) {
            if (area[r][c] == 5) break;
            pop[4] += A[r][c];
        }
    }

    // 5번 구역 = 전체 - (1~4)
    pop[5] = TOTAL - (pop[1] + pop[2] + pop[3] + pop[4]);

    int mx = *max_element(pop + 1, pop + 6);
    int mn = *min_element(pop + 1, pop + 6);
    res = min(res, mx - mn);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    TOTAL = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) {
            cin >> A[i][j];
            TOTAL += A[i][j];
        }

    res = INT_MAX;

    for (int x = 1; x <= N; ++x)
        for (int y = 1; y <= N; ++y)
            for (int d1 = 1; d1 <= N; ++d1)
                for (int d2 = 1; d2 <= N; ++d2)
                    if (isValid(x, y, d1, d2))
                        update(x, y, d1, d2);

    cout << res << "\n";
    return 0;
}
