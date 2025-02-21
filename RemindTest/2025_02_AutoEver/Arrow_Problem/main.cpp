#include <iostream>
#include <vector>

namespace arrow
{
    using namespace std;

    class Arrow
    {
    private:
        Arrow() = default;
        ~Arrow() = default;
        int N, M, K;
        vector<vector<int>> board;
        vector<int> weight;

    public:
        static Arrow &getInstance()
        {
            static Arrow instance;
            return instance;
        }

        inline void input();
        const int get_score() const
        {
            int ans = 0;

            return ans;
        }
    };

    inline void Arrow::input()
    {
        cin >> N >> M >> K;
        board.resize(N, vector<int>(N));
        weight.resize(M);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> board[i][j];

        for (int i = 0; i < M; i++)
            cin >> weight[i];

        return;
    }
}

using namespace arrow;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Arrow &arrow = Arrow::getInstance();

    return EXIT_SUCCESS;
}