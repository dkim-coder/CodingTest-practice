#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Solution
{
    private:
        static const int dx[4];        
        static const int dy[4];        
        static const int row_size;
        int col_size;
        T answer;
        T **sticker;
    public:
        Solution();
        virtual ~Solution();
        void input();
        virtual void solve();
        T get_answer() const { return answer; }
};

template <typename T>
const int Solution<T>::dx[4] = {0, 0, 1, -1};

template <typename T>
const int Solution<T>::dy[4] = {1, -1, 0, 0};

template <typename T>
const int Solution<T>::row_size = 2;

template <typename T>
Solution<T>::Solution()
{
    col_size = 0;
    answer = static_cast<T>(0);
    sticker = new T*[row_size];
    for(int i = 0; i < row_size; i++)
        sticker[i] = nullptr;
}

template <typename T>
Solution<T>::~Solution()
{
    if(sticker != nullptr)
    {
        for(int i = 0; i < row_size; i++)
        {
            delete[] sticker[i];
        }
        delete[] sticker;
    }
}

template <typename T>
void Solution<T>::input()
{
    cin >> col_size;
    for(int i = 0; i < row_size; i++)
    {
        if(sticker[i] == nullptr)
            sticker[i] = new T[col_size];
        else{
            delete[] sticker[i];
            sticker[i] = new T[col_size];
        }
        
        for(int j = 0; j < col_size; j++)
            cin >> sticker[i][j];
    }

    return;
}

template <typename T>
void Solution<T>::solve()
{
    this->answer = static_cast<T>(0);
    if (this->col_size == 0) return;

    vector<vector<T>> dp(row_size, vector<T>(col_size, static_cast<T>(0)));

    dp[0][0] = this->sticker[0][0];
    dp[1][0] = this->sticker[1][0];

    if (col_size > 1) {
        dp[0][1] = this->sticker[0][1] + dp[1][0];
        dp[1][1] = this->sticker[1][1] + dp[0][0];
    }

    for (int i = 2; i < col_size; i++) {
        dp[0][i] = this->sticker[0][i] + max(dp[1][i-1], dp[1][i-2]);
        dp[1][i] = this->sticker[1][i] + max(dp[0][i-1], dp[0][i-2]);
    }

    answer = max(dp[0][col_size - 1], dp[1][col_size - 1]);

    return;
}

int main()
{
    int n;
    cin >> n;
    Solution<int> *s = new Solution<int>();
    while(n--)
    {
        s->input();
        s->solve();
        cout << s->get_answer() << '\n';
    }
    delete s;

    return 0;
}