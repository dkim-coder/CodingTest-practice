#include <iostream>
#include <cstring>

#define MAX 15

using namespace std;

static int n;
static bool board[MAX][MAX];
static bool col[MAX], diag1[2 * MAX - 1], diag2[2 * MAX - 1];   // 퀸이 놓아지는 경우 되지 못하는 열, 대각선들을 체크해 두는 것임

inline void init() {
    cin >> n;
    memset(board, false, sizeof(board));
    memset(col, false, sizeof(col));
    memset(diag1, false, sizeof(diag1));
    memset(diag2, false, sizeof(diag2));
}

void dfs(int queen_count, int &ans, int r) {
    if (queen_count == n) {
        ans++;
        return;
    }

    for (int j = 0; j < n; j++) {
        if (col[j] || diag1[r - j + n - 1] || diag2[r + j])
            continue;

        // 퀸 배치
        col[j] = diag1[r - j + n - 1] = diag2[r + j] = true;
        dfs(queen_count + 1, ans, r + 1);
        // 복구
        col[j] = diag1[r - j + n - 1] = diag2[r + j] = false;
    }
}

const int solve() {
    int ans = 0;
    dfs(0, ans, 0);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    cout << solve() << endl;

    return 0;
}