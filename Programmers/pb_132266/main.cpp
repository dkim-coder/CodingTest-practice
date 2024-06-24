#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    if (a[0] < b[0])
        return true;
    else if (a[0] == b[0])
        return a[1] < b[1];
    else
        return false;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination)
{
    vector<int> answer;
    vector<vector<int>> maps(n + 1);

    sort(roads.begin(), roads.end(), comp);

    for (int i = 0; i < roads.size(); i++)
    {
        maps[roads[i][0]].push_back(roads[i][1]);
        maps[roads[i][1]].push_back(roads[i][0]);
    }

    for (int i = 0; i < sources.size(); i++)
    {
        queue<pair<int, int>> q;
        vector<bool> check(n + 1, false);
        q.push({sources[i], 0});
        check[sources[i]] = true;
        bool g_check = false;

        while (!q.empty())
        {
            int pos = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if (pos == destination)
            {
                answer.push_back(cnt);
                g_check = true;
                break;
            }

            for (int j = 0; j < maps[pos].size(); j++)
            {
                if (!check[maps[pos][j]])
                {
                    q.push({maps[pos][j], cnt + 1});
                    check[maps[pos][j]] = true;
                }
            }
        }
        if (!g_check)
            answer.push_back(-1);
    }

    return answer;
}

int main()
{
    int n = 5;
    // vector<vector<int>> roads = {{1, 2}, {1, 4}, {2, 4}, {2, 5}, {4, 5}};
    vector<vector<int>> roads = {{1, 2}, {1, 4}, {2, 4}, {2, 5}, {4, 5}};
    vector<int> sources = {1, 3, 5};
    int destination = 5;

    for (auto i : solution(n, roads, sources, destination))
        cout << i << " ";

    return EXIT_SUCCESS;
}