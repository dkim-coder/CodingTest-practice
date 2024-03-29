#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

/*
bool compare(vector<int> v1, vector<int> v2)
{
    return v1[2] < v2[2];
}

int getParent(vector<int> &parent, int idx) // 노드의 부모노드 값 반환
{
    if (parent[idx] == idx)
        return idx;

    return getParent(parent, parent[idx]);
}

void unionParent(vector<int> &parent, int n1, int n2) // 두 노드가 속한 집합을 합침
{
    int p1 = getParent(parent, n1);
    int p2 = getParent(parent, n2);

    if (p1 < p2)
        parent[p2] = p1;
    else
        parent[p1] = p2;
}

bool findParent(vector<int> &parent, int n1, int n2) // 두 노드가 같은 집합에 속하는지 체크
{
    int p1 = getParent(parent, n1);
    int p2 = getParent(parent, n2);

    if (p1 == p2)
        return true;
    else
        return false;
}

int kruskal(int n, vector<vector<int>> costs)
{
    int answer = 0;
    vector<int> parent;
    int total = 0;

    for (int i = 0; i < n; i++)
        parent.push_back(i);

    // 엣지의 가중치를 기준으로 오름차순 정렬
    sort(costs.begin(), costs.end(), compare);

    // 낮은 가중를 가진걸 선택
    for (int i = 0; i < costs.size(); i++)
    {
        // 만약 서로소 집합이면 union 하고 엣지 수 추가
        if (!findParent(parent, costs[i][0], costs[i][1]))
        {
            unionParent(parent, costs[i][0], costs[i][1]);
            answer += costs[i][2];
            if (++total == n - 1)
                return answer;
        }
    }
}
*/

struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second; // 오름차순으로 됨 sort 와는 반대로 생각
    }
};

int prim(int n, vector<vector<int>> costs)
{
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    vector<vector<pair<int, int>>> graph(n);
    vector<bool> visit(n, false);

    for (auto c : costs)
    {
        graph[c[0]].push_back({c[1], c[2]}); // 목적지, 가중치
        graph[c[1]].push_back({c[0], c[2]});
    }

    for (int i = 0; i < graph[0].size(); i++)
        pq.push(graph[0][i]);
    visit[0] = true;

    while (!pq.empty())
    {
        pair<int, int> curline = pq.top();
        pq.pop();

        int node = curline.first;
        int weight = curline.second;

        if (visit[node])
            continue;
        visit[node] = true;
        answer += weight;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int nextnode = graph[node][i].first;
            if (!visit[nextnode])
                pq.push(graph[node][i]);
        }
    }

    return answer;
}

int main()
{
    int n = 4;
    vector<vector<int>> costs = {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}};

    // cout << "Answer : " << kruskal(n, costs);
    cout << "Prim's Answer : " << prim(n, costs) << endl;

    return EXIT_SUCCESS;
}