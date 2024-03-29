#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool kruskal_compare(vector<int> v1, vector<int> v2)
{
    return v1[2] < v2[2];
}

int getParent(vector<int> &parent, int n)
{
    if (parent[n] == n)
        return n;
    return getParent(parent, parent[n]);
}

void unionParent(vector<int> &parent, int n1, int n2)
{
    int p1 = getParent(parent, n1);
    int p2 = getParent(parent, n2);

    if (p1 < p2)
        parent[p2] = p1;
    else
        parent[p1] = p2;

    return;
}

bool findParent(vector<int> &parent, int n1, int n2)
{
    int p1 = getParent(parent, n1);
    int p2 = getParent(parent, n2);

    if (p1 == p2)
        return true;
    else
        return false;
}

int kruskal(int num_node, vector<vector<int>> input) // 간선의 가중치가 작은 것 부터 탐색하는 방법, 서로소인지 확인하는 과정이 필요함
{
    int answer = 0;
    vector<int> parent(num_node + 1); // 해당 노드의 부모 노드를 저장하기 위함, union-find

    for (int i = 1; i < parent.size(); i++)
        parent[i] = i;

    // 가중치 기준 오름차순 정렬
    sort(input.begin(), input.end(), kruskal_compare);

    int cnt = 0; // 추가된 간선의 수 체크하기 위함
    // 가중치 작은 것부터 탐색
    for (int i = 0; i < input.size(); i++)
    {
        // 두 노드가 서로소 이면 union 하고 answer 증가
        if (!findParent(parent, input[i][0], input[i][1]))
        {
            unionParent(parent, input[i][0], input[i][1]);
            answer += input[i][2];
            if (++cnt == num_node - 1)
                return answer;
        }
    }

    return answer;
}

struct prim_compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second; // 오름차순 정렬
    }
};

int prim(int num_node, vector<vector<int>> input)
{
    int answer = 0;

    vector<bool> visit(num_node + 1, false);
    vector<vector<pair<int, int>>> graph(num_node + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, prim_compare> pq;

    // 그래프로 저장
    for (int i = 0; i < input.size(); i++){
        graph[input[i][0]].push_back({input[i][1], input[i][2]});
        graph[input[i][1]].push_back({input[i][0], input[i][2]});
    }

    for (int i = 0; i < graph[1].size(); i++)
        pq.push(graph[1][i]);
    visit[1] = true;

    while (!pq.empty())
    {
        int node = pq.top().first;
        int weight = pq.top().second;
        pq.pop();

        if (visit[node])
            continue;

        visit[node] = true;
        answer += weight;

        for (int i = 0; i < graph[node].size(); i++)
        {
            if (!visit[graph[node][i].first])
                pq.push(graph[node][i]);
        }
    }
    
    return answer;
}

int main()
{
    int num_node;
    int num_edge;
    cin >> num_node >> num_edge;
    vector<vector<int>> input; // [노드 1, 노드 2, 가중치]

    for (int i = 0; i < num_edge; i++)
    {
        vector<int> tmp(3, 0);
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        input.push_back(tmp);
    }

    // cout << "Kruskal : " << kruskal(num_node, input) << endl;
    // cout << "Prim : " << prim(num_node, input) << endl;
    cout << prim(num_node, input) << endl;

    return EXIT_SUCCESS;
}