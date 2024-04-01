#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
/*
int getParent(vector<int> &parent, int n)
{
    if (parent[n] == n)
        return n;
    return parent[n] = getParent(parent, parent[n]);
}

void unionParent(vector<int> &parent, int n1, int n2)
{
    n1 = getParent(parent, n1);
    n2 = getParent(parent, n2);

    if (n1 != n2)
        parent[n1] = n2;

    // if (n1 < n2)
    //     parent[n2] = n1;
    // else
    //     parent[n1] = n2;

    return;
}

bool findParent(vector<int> &parent, int n1, int n2)
{
    n1 = getParent(parent, n1);
    n2 = getParent(parent, n2);

    if (n1 == n2)
        return true;
    else
        return false;
}

bool kruskal_compare(vector<int> v1, vector<int> v2)
{
    return v1[2] < v2[2];
}

int kruskal(int n, vector<vector<int>> graph)
{
    int answer = 0;
    vector<int> parent(n + 1);
    for (int i = 1; i < parent.size(); i++)
        parent[i] = i;

    sort(graph.begin(), graph.end(), kruskal_compare);

    vector<int> res;
    for (int i = 0; i < graph.size(); i++)
    {
        if (!findParent(parent, graph[i][0], graph[i][1]))
        {
            unionParent(parent, graph[i][0], graph[i][1]);
            res.push_back(graph[i][2]);
        }
    }

    for (int i = 0; i < res.size() - 1; i++)
        answer += res[i];

    return answer;
}
*/
struct prim_comp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int prim(int n, vector<vector<int>> graph)
{
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, prim_comp> pq;
    vector<vector<pair<int, int>>> g(n + 1);
    vector<bool> visit(n + 1, false);

    for (auto c : graph)
    {
        g[c[0]].push_back({c[1], c[2]});
        g[c[1]].push_back({c[0], c[2]});
    }

    for (int i = 0; i < g[1].size(); i++)   // 처음 시작 노드를 방문처리하고 힙에 모두 삽입
        pq.push(g[1][i]);
    visit[1] = true;

    int cur_max = 0;
    while (!pq.empty())
    {
        int node = pq.top().first;
        int weight = pq.top().second;
        pq.pop();
        if (visit[node])
            continue;

        visit[node] = true;
        cur_max = max(cur_max, weight);
        answer += weight;
        for (int i = 0; i < g[node].size(); i++)
        {
            if (!visit[g[node][i].first])
                pq.push(g[node][i]);
        }
    }

    answer -= cur_max;

    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph;
    for (int i = 0; i < m; i++)
    {
        vector<int> tmp(3);
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        graph.push_back(tmp);
    }

    // cout << kruskal(n, graph) << endl;
    cout << prim(n, graph) << endl;

    return EXIT_SUCCESS;
}