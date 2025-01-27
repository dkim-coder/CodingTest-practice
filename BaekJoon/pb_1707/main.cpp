// 이분 그래프 탐색
#include <iostream>
#include <vector>
#include <string>
#include <stack>

#define endl "\n"
#define EXIT_SUCCESS 0

using namespace std;

using st = short;

// 그래프 끊기는 경우 고려해야 함
string solution(const vector<vector<st>> &graph, const st v)
{
    vector<bool> visited(v + 1, false);
    vector<bool> color(v + 1, false);
    st start = 1;
    stack<st> s;
    st cnt = 1;

    while (cnt < v)
    {
        for (; start <= v && visited[start]; start++)
        {
            continue;
        }
        if (start > v)
            break;

        s.push(start);
        visited[start] = true;

        while (!s.empty())
        {
            st cur = s.top();
            s.pop();

            for (auto next : graph[cur])
            {
                if (visited[next])
                {
                    if (color[cur] != color[next])
                        continue;
                    else
                        return "NO";
                }
                else
                {
                    visited[next] = true;
                    color[next] = !color[cur];
                    s.push(next);
                    cnt++;
                }
            }
        }
    }

    return "YES";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    st k, v, e;
    st v1, v2;
    vector<string> answer;
    cin >> k;
    for (st i = 0; i < k; ++i)
    {
        cin >> v >> e;
        if (v == 1)
        {
            answer.push_back("YES");
            continue;
        }

        vector<vector<st>> graph(v + 1);
        for (st j = 0; j < e; ++j)
        {
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        answer.push_back(solution(graph, v));
    }

    for (auto const &ans : answer)
        cout << ans << endl;

    return EXIT_SUCCESS;
}
