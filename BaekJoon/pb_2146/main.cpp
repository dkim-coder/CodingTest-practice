#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define EXIT_SUCCESS 0
#define VISIT 2
#define LAND 1
#define SEA 0

template <typename T1, typename T2>
class Base
{
    protected:
        T1 N;
        T1 answer;
        T2 **board;
    public:
        Base();
        virtual ~Base();
        virtual void input();
        virtual void solve() = 0;
        T1 get_answer() const { return this->answer; }
};

template <typename T1, typename T2>
Base<T1, T2>::Base()
{
    this->N = 0;
    this->answer = 0;
    this->board = nullptr;
}

template <typename T1, typename T2>
Base<T1, T2>::~Base()
{
    if(this->board != nullptr)
    {
        for(int i = 0; i < this->N; i++)
        {
            delete [] this->board[i];
        }
        delete [] this->board;
    }
}

template <typename T1, typename T2>
void Base<T1, T2>::input()
{
    cin >> this->N;
    this->board = new T2*[this->N];
    for(int i = 0; i < this->N; i++)
    {
        this->board[i] = new T2[this->N];
        for(int j = 0; j < this->N; j++)
        {
            cin >> this->board[i][j];
        }
    }

    return;
}

template <typename T1, typename T2>
class Solution : public Base<T1, T2>
{
    private:
        static const int dx[4];
        static const int dy[4];
        vector<set<pair<T2, T2>>> islands;
        void make_island();
    public:
        Solution() {}
        virtual ~Solution() {}
        virtual void solve() override;
};

template <typename T1, typename T2>
const int Solution<T1, T2>::dx[4] = {0, 0, -1, 1};

template <typename T1, typename T2>
const int Solution<T1, T2>::dy[4] = {-1, 1, 0, 0};

template <typename T1, typename T2>
void Solution<T1, T2>::make_island()
{
    this->islands.clear();
    queue<pair<T2, T2>> q;
    for(int i = 0; i < this->N; i++)
    {
        for(int j = 0; j < this->N; j++)
        {
            if(this->board[i][j] == LAND)
            {
                q.push(make_pair(i, j));
                this->board[i][j] = VISIT;
                set<pair<T2, T2>> island;
                island.insert(make_pair(i, j));
                while(!q.empty())
                {
                    pair<T2, T2> cur = q.front();
                    q.pop();
                    for(int k = 0; k < 4; k++)
                    {
                        T2 nx = cur.first + Solution<T1, T2>::dx[k];
                        T2 ny = cur.second + Solution<T1, T2>::dy[k];

                        if(nx < 0 || nx >= this->N || ny < 0 || ny >= this->N)
                            continue;

                        if(this->board[nx][ny] == LAND)
                        {
                            q.push(make_pair(nx, ny));
                            this->board[nx][ny] = VISIT;
                            island.insert(make_pair(nx, ny));
                        }
                    }
                }
                this->islands.push_back(island);
            }
        }
    }

    return;
}

template <typename T1, typename T2>
void Solution<T1, T2>::solve()
{
    make_island();
    this->answer = this->N * this->N;

    for (const auto& island : this->islands)
    {
        queue<pair<T2, T2>> q;
        vector<vector<int>> dist(this->N, vector<int>(this->N, -1));

        for (const auto& pos : island)
        {
            q.push(pos);
            dist[pos.first][pos.second] = 0;
        }

        while (!q.empty())
        {
            pair<T2, T2> cur = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                T2 nx = cur.first + Solution<T1, T2>::dx[k];
                T2 ny = cur.second + Solution<T1, T2>::dy[k];

                if (nx < 0 || nx >= this->N || ny < 0 || ny >= this->N)
                    continue;

                if (dist[nx][ny] == -1)
                {
                    if (this->board[nx][ny] == SEA)
                    {
                        dist[nx][ny] = dist[cur.first][cur.second] + 1;
                        q.push(make_pair(nx, ny));
                    }
                    else if (this->board[nx][ny] == VISIT)
                    {
                        this->answer = min(this->answer, dist[cur.first][cur.second]);
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Base<int, int> *base = new Solution<int, int>();
    base->input();
    base->solve();
    cout << base->get_answer() << endl;
    delete base;

    return EXIT_SUCCESS;
}