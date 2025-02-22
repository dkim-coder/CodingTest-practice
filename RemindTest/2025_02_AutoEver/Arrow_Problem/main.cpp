#include <iostream>
#include <vector>

#define EXIT_SUCCESS 0

/**
 * @file main.cpp
 * @date 2025-02-22
 * @author jeus5771@naver.com
 * @version 1.0
 * @brief 오토에버 화살 문제 복기 및 풀이
 */
namespace AutoEver
{
    using namespace std;

    template <typename T>
    class Arrow
    {
    private:
        Arrow() = default;
        ~Arrow() = default;
        Arrow(const Arrow &) = delete;
        Arrow &operator=(const Arrow &) = delete;
        T N, M, K;                      // 보드 크기 (N x N), 화살 개수, 목표 점수
        vector<vector<T>> board;        // 보드 점수 정보
        vector<T> weights;              // 화살의 무게
        vector<vector<T>> arrow_scores; // 화살이 보드의 맞히는 곳에 따른 획득 점수
        vector<vector<T>> dp;           // 배낭문제 기반 dp 솔루션

    public:
        /**
         * @brief 싱글톤 패턴 객체 반환
         *
         * @return Arrow&
         */
        static Arrow &get_instance();

        /**
         * @brief 입력을 받는 함수
         *
         * @return void
         */
        inline void input();

        /**
         * @brief 화살이 맞히는 곳에 따른 점수를 계산해서 저장
         *
         * @return void
         */
        void set_arrow_scores();

        /**
         * @brief 목표 점수를 획득할 수 있는 가장 적은 화살의 필요 무게를 계산 및 출력
         *
         * @return void
         */
        void solve();
    };

    template <typename T>
    Arrow<T> &Arrow<T>::get_instance()
    {
        static Arrow instance;
        return instance;
    }

    template <typename T>
    void Arrow<T>::input()
    {
        cin >> N >> M >> K;
        board.resize(N, vector<T>(N));
        weights.resize(M + 1);
        for (auto &row : board)
            for (auto &elem : row)
                cin >> elem;
        for (int i = 1; i <= M; i++) // 편의상 화살의 정보는 1부터 시작
            cin >> weights[i];
        return;
    }

    template <typename T>
    void Arrow<T>::set_arrow_scores()
    {
        arrow_scores.resize(M + 1, vector<T>(N * N, 0));
        for (int i = 1; i <= M; i++)                // 화살
            for (int j = 0; j < N; j++)             // 화살이 맞히는 row
                for (int k = 0; k < N; k++)         // 화살이 맞히는 column
                    for (int l = 0; l < N; l++)     // 보드의 row
                        for (int m = 0; m < N; m++) // 보드의 column
                            if (abs(j - l) + abs(k - m) < i)
                                arrow_scores[i][j * N + k] += board[l][m];
        return;
    }

    template <typename T>
    void Arrow<T>::solve()
    {
        input();
        set_arrow_scores();
        T INF = static_cast<T>(1e9);
        dp.resize(M + 1, vector<T>(K + 1, INF));
        dp[0][0] = 0;

        for (int i = 1; i <= M; i++)
        {
            for (int j = 0; j <= K; j++)
            {
                if (j == 0)     // 목표 점수가 0일 때는 화살이 필요하지 않으며, 무게도 0이므로 0으로 초기화
                    dp[i][j] = 0;
                else
                    for (int k = 0; k < N * N; k++)
                        if (j - arrow_scores[i][k] >= 0)
                            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - arrow_scores[i][k]] + weights[i]); // INF, INF + weigths[i] 에는 INF가 저장되어 불가능을 뜻하게 됨
            }
        }

        if(dp[M][K] == INF)
            cout << -1 << '\n';
        else
            cout << dp[M][K] << '\n';

        return;
    }
}

using namespace AutoEver;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto &arrow = Arrow<int>::get_instance();
    arrow.solve();

    return EXIT_SUCCESS;
}