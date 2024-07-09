#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Node
{
    int x;
    int y;

    // Node(int a, int b) : x(a), y(b) {};

    Node(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int n = land.size();
    int m = land[0].size();
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    unordered_map<int, int> um; // <y, count>

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (land[i][j] == 1 && !visit[i][j])
            {
                stack<Node> st;
                unordered_set<int> us; // y 만 가지면 됨
                int max_val = 1;
                // st.push(Node(i, j));
                st.emplace(i, j);
                us.insert(j);
                visit[i][j] = true;

                while (!st.empty())
                {
                    int x = st.top().x;
                    int y = st.top().y;
                    // int cnt = st.top().cnt;
                    st.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;

                        if (land[nx][ny] == 0 || visit[nx][ny])
                            continue;

                        if (land[nx][ny] == 1)
                        {
                            visit[nx][ny] = true;
                            st.emplace(nx, ny);
                            us.insert(ny);
                            max_val++;
                        }
                    }
                }

                if (max_val > 0)
                {
                    for (const auto &u : us){
                        um[u] += max_val;
                    }
                }
            }
        }
    }

    for (auto it = um.begin(); it != um.end(); it++)
    {
        if (it->second > answer)
            answer = it->second;
    }

    return answer;
}

int main()
{
    vector<vector<int>> land = {{0, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {1, 1, 0, 0, 0, 1, 1, 0}, {1, 1, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 1, 1}};

    cout << solution(land) << endl;

    return EXIT_SUCCESS;
}