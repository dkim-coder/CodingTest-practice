#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// 그리디 접근 -> MST 문제로 예시
namespace greedy
{
    using namespace std;

    int V, E;                            // V: 정점 개수, E: 엣지 개수
    vector<pair<pair<int, int>, int>> v; // {{정점1, 정점2}, 가중치} -> 입력 받는데 사용
    vector<int> parent;                  // kruskal 알고리즘에서 union-find 사용하기 위함
    vector<bool> visited;                // prim 알고리즘에서 방문 정점 표시하기 위함

    bool compare(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
    {
        return a.second < b.second;
    }

    int func_find(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = func_find(parent[node]);
    }

    bool func_union(int node1, int node2)
    {
        int parent_node1 = func_find(node1);
        int parent_node2 = func_find(node2);

        if (parent_node1 == parent_node2)
            return false;
        else
        {
            if (parent_node1 < parent_node2)
                parent[parent_node2] = parent_node1;
            else
                parent[parent_node1] = parent_node2;

            return true;
        }
    }

    /* 크루스칼 알고리즘
    엣지의 가중치를 기준으로 오름차순해서 엣지를 하나씩 선택하면서 해결해 나가는 기법
    - 가중치가 작은 엣지들을 선택하고 사이클 여부를 판단하면서 스패닝 트리 될때까지 수행
    */
    int kruskal()
    {
        int answer = 0;
        int edge_cnt = 0; // 현재 선택된 엣지 개수 -> 엣지 개수가 (정점 개수 - 1) 이면 스패닝트리가 만족 된 것을 의미

        vector<pair<pair<int, int>, int>> tmp(v); // 가중치 기준 정렬하기 위해 원본 복사해서 사용
        sort(tmp.begin(), tmp.end(), compare);
        for (int i = 0; i <= V; i++) // 부모 정점 초기 세팅
            parent[i] = i;

        for (const auto &i : tmp) // 가중치가 작은 엣지부터 하나씩 꺼냄
        {
            if (func_find(i.first.first) != func_find(i.first.second)) // 두 정점이 같은 집합에 속해있지 않다면
            {
                func_union(i.first.first, i.first.second); // 같은 집합으로 합치고
                answer += i.second;
                edge_cnt++;
            }

            if (edge_cnt == V - 1)
                return answer;
        }

        return -1;
    }

    struct comp
    {
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return a.second > b.second;
        }
    };

    /* prim 알고리즘
    임의의 정점에서 시작
    선택된 정점들이 가지는 엣지들중에서 가장 작은 가중치를 선택하고 방문이 안되었으면 해당 엣지 선택, 아니면 다른 것 선택
    */
    int prim()
    {
        int answer = 0;
        int edge_cnt = 0;
        vector<vector<pair<int, int>>> graph(V + 1);                     // 인덱스 : 정점 번호 , {인접 정점, 가중치}
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq; // first: {노드1, 노드2}, second: 가중치
        fill(visited.begin(), visited.end(), false);                     // 방문 초기화

        for (const auto &i : v) // 그래프 세팅
        {
            graph[i.first.first].push_back({i.first.second, i.second});
            graph[i.first.second].push_back({i.first.first, i.second});
        }

        visited[1] = true; // 시작노드 -> 임의로 선택
        for (const auto &i : graph[1])
            pq.push({i.first, i.second}); // 선택된 정점이 가지는 엣지들 포함

        pair<int, int> tmp;
        while (!pq.empty())
        {
            tmp = pq.top();
            pq.pop();
            if (visited[tmp.first]) // 뽑은 정점이 이미 방문되었다면 무시
                continue;

            answer += tmp.second;
            edge_cnt++;
            visited[tmp.first] = true;
            for (const auto &i : graph[tmp.first]) // 선택된 정점의 엣지들 힙에 추가
                pq.push({i.first, i.second});

            if (edge_cnt == V - 1)
                return answer;
        }

        return -1;
    }

}

using namespace greedy;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;
    v.resize(E);
    parent.resize(V + 1);
    visited.resize(V + 1);
    for (int i = 0; i < E; i++)
        cin >> v[i].first.first >> v[i].first.second >> v[i].second;

    // cout << "kruskal: " << kruskal() << "\n";
    cout << prim() << "\n";

    return EXIT_SUCCESS;
}