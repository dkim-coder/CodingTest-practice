#include <iostream>
#include <cstring>

#define MAX 15

using namespace std;

static int n;
static bool board[MAX][MAX];
constexpr static int dx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
constexpr static int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};

inline void init()
{
    cin >> n;
    memset(board, false, sizeof(board));

    return;
}

const bool check(const int r, const int c)
{
    for(int i = 0; i < sizeof(dx) / sizeof(int); i++)
    {
        int cr = r;
        int cc = c;
        while(true)
        {
            cr += dx[i];
            cc += dy[i];

            if(cr < 0 || cr >= n || cc < 0 || cc >= n)
                break;
            
            if(board[cr][cc])
                return false;
        }
    }

    return true;
}

void dfs(const int queen_count, int &ans)
{
    if (queen_count == n)
    {
        ans++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j])
                continue;

            if (!check(i, j))
                continue;

            board[i][j] = true;
            dfs(queen_count + 1, ans);
            board[i][j] = false;
        }
    }

    
    return;
}

const int solve()
{
    int ans = 0;

    dfs(0, ans);

    return ans;
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    cout << solve() << endl;

    return 0;
}