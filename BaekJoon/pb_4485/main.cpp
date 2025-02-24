#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define EXIT_SUCCESS 0
#define endl '\n'

using namespace std;

int N;
short board[125][125];
short dist[125][125];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

inline void input()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    return;
}

struct comp
{
    bool operator()(const pair<short, pair<int, int>> &a, const pair<short, pair<int, int>> &b)
    {
        return a.first > b.first;
    }
};

int solution()
{
    input();
    int answer = 0;
    priority_queue<pair<short, pair<int, int>>, vector<pair<short, pair<int, int>>>, comp> pq;
    memset(dist, 1e6, sizeof(dist));
    dist[0][0] = board[0][0];
    pq.push({dist[0][0], {0, 0}});
    while (!pq.empty())
    {
        int cur_dist = pq.top().first;
        int cur_x = pq.top().second.first;
        int cur_y = pq.top().second.second;
        pq.pop();

        if (cur_dist > dist[cur_x][cur_y])
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;

            if (dist[nx][ny] > dist[cur_x][cur_y] + board[nx][ny])
            {
                dist[nx][ny] = dist[cur_x][cur_y] + board[nx][ny];
                pq.push({dist[nx][ny], {nx, ny}});
            }
        }
    }

    answer = dist[N - 1][N - 1];

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int idx = 1;
    while (true)
    {
        cin >> N;
        if (!N)
            break;

        cout << "Problem " << idx++ << ": " << solution() << endl;
    }

    return EXIT_SUCCESS;
}