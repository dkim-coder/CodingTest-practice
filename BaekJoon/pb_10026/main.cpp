#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int origin_dfs(vector<vector<char>> graph, int n)
{
    int answer = 0;
    vector<vector<bool>> visit(n, vector<bool>(n, false));
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j])
                continue;
            else
            {
                char color = graph[i][j];
                st.push({i, j});
                visit[i][j] = true;
                while (!st.empty())
                {
                    int x = st.top().first;
                    int y = st.top().second;
                    st.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (graph[nx][ny] != color || visit[nx][ny])
                            continue;

                        st.push({nx, ny});
                        visit[nx][ny] = true;
                    }
                }
                answer++;
            }
        }
    }

    return answer;
}

int another_dfs(vector<vector<char>> graph, int n)
{
    int answer = 0;
    vector<vector<bool>> visit(n, vector<bool>(n, false));
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j])
                continue;
            else
            {
                char color = graph[i][j];
                st.push({i, j});
                visit[i][j] = true;
                while (!st.empty())
                {
                    int x = st.top().first;
                    int y = st.top().second;
                    st.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (visit[nx][ny])
                            continue;

                        if (color == 'B')
                        {
                            if (graph[nx][ny] == 'B')
                            {
                                st.push({nx, ny});
                                visit[nx][ny] = true;
                            }
                        }
                        else
                        {
                            if (graph[nx][ny] != 'B')
                            {
                                st.push({nx, ny});
                                visit[nx][ny] = true;
                            }
                        }
                    }
                }
                answer++;
            }
        }
    }

    return answer;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> graph(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    }

    // cout << origin_dfs(graph, n) <<  " " << another_dfs(graph, n) << endl;
    // cout << another_dfs(graph, n) << endl;

    return EXIT_SUCCESS;
}