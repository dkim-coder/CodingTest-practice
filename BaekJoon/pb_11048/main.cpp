#include <iostream>
#include <vector>

using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))

class Solution
{
private:
    // static int dx[3];
    // static int dy[3];
    int N, M;
    int answer;
    vector<vector<int>> board;

public:
    Solution();
    ~Solution();
    virtual void input();
    // virtual void dfs(int cr, int cc, int sum);
    virtual int dp() const;
    virtual int getAnswer();
    virtual void setAnswer(int answer);
};

// int Solution::dx[3] = {1, 0, 1};
// int Solution::dy[3] = {0, 1, 1};

Solution::Solution()
{
    this->answer = 0;
}

Solution::~Solution()
{
}

void Solution::input()
{
    cin >> this->N >> this->M;
    this->board = vector<vector<int>>(this->N, vector<int>(this->M, 0));
    for (int i = 0; i < this->N; i++)
    {
        for (int j = 0; j < this->M; j++)
        {
            cin >> this->board[i][j];
        }
    }
}

#if 0
void Solution::dfs(int cr, int cc, int sum)
{
    sum += this->board[cr][cc]; // 현재 위치의 값을 sum에 더함

    if (cr == this->N - 1 && cc == this->M - 1)
    {
        this->answer = max(this->answer, sum);
        return;
    }

    for (int i = 0; i < sizeof(Solution::dx) / sizeof(int); i++)
    {
        int nr = cr + Solution::dx[i];
        int nc = cc + Solution::dy[i];

        if (nr < 0 || nr >= this->N || nc < 0 || nc >= this->M)
            continue;

        this->dfs(nr, nc, sum);
    }
}
#endif

int Solution::dp() const
{
    vector<vector<int>> dp(this->N, vector<int>(this->M, 0));
    dp[0][0] = this->board[0][0];
    for (int i = 0; i < this->N; i++)
    {
        for (int j = 0; j < this->M; j++)
        {
            if (i > 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j] + this->board[i][j]);
            
            if (j > 0)
                dp[i][j] = max(dp[i][j], dp[i][j-1] + this->board[i][j]);
            
            if (i > 0 && j > 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + this->board[i][j]);
        }
    }
    
    return dp[this->N-1][this->M-1];
}

int Solution::getAnswer()
{
    return this->answer;
}

void Solution::setAnswer(int answer)
{
    this->answer = answer;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution *s = new Solution();
    s->input();
    // s->dfs(0, 0, 0);
    s->setAnswer(s->dp());
    cout << s->getAnswer() << "\n";
    delete s;

    return 0;
}