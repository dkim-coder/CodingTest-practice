#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K; // 표적 크기, 화살 개수, 목표 점수
    cin >> N >> M >> K;

    // 표적 점수 입력
    vector<vector<int>> target(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> target[i][j];

    // 화살 무게 입력 화살은 1번 인덱스 부터 시작하도록
    vector<int> weight(M + 1);
    for (int i = 1; i <= M; i++)
        cin >> weight[i];

    // 각 화살로 얻을 수 있는 점수 계산
    vector<vector<int>> arrow_scores(M + 1, vector<int>(N * N));
    for (int i = 1; i <= M; i++)
    {
        int power = i;
        int idx = 0;
        for (int x = 0; x < N; x++) // 화살이 맞는 x좌표
        {
            for (int y = 0; y < N; y++) // 화살이 맞는 y좌표
            {
                // 거리 탐색해서 조건 맞으면 획득 가능 점수 계산해서 저장
                int score = 0;
                for (int nx = 0; nx < N; nx++)
                    for (int ny = 0; ny < N; ny++)
                        if (abs(nx - x) + abs(ny - y) < power)
                            score += target[nx][ny];
                arrow_scores[i][idx++] = score;
            }
        }
    }

    // 배낭 문제 기반 풀이
    // 배낭 문제와의 차이점이라면 점수가 정확히 일치해야한다는 점임
    vector<vector<int>> dp(M + 1, vector<int>(K + 1, INF));
    for (int i = 1; i <= M; i++) // 화살 번호
    {
        for (int j = 0; j <= K; j++) // 점수
        {
            if (i == 1) // 첫 번째 화살은 그냥 넣어주기
            {
                for (int k = 0; k < N * N; k++)
                    if (j == arrow_scores[i][k])    // 점수가 정확히 맞아야 함
                        dp[i][j] = weight[i];
            }
            else
            {
                for (int k = 0; k < N * N; k++)
                    if (j - arrow_scores[i][k] >= 0)
                        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - arrow_scores[i][k]] + weight[i]);
            }
        }
    }

    cout << (dp[M][K] == INF ? -1 : dp[M][K]) << "\n";

    return 0;
}
