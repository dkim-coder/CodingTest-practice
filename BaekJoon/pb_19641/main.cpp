#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
각 노드 left = 부모 노드의 left + 1
각 노도의 right = left + 서브트리의 노드의 개수 * 2 + 1
*/

int n, r;
pair<int, int> ans[100001];
vector<vector<int>> v;

int go(int node, int pre, int last)
{

    int subSum = 0;

    for (auto &i : v[node])
    {
        if (i != pre)
        {
            subSum += go(i, node, last + subSum * 2 + 1);
        }
    }
    ans[node] = {last + 1, last + 1 + subSum * 2 + 1};

    return subSum + 1;
}

struct Node
{
    int idx;
    int left;
    int right;
};

void dfs()
{
    stack<Node> st;
    st.push({r, 1, 0}); // 최상단 node 의 left 값은 1

    while (!st.empty())
    {
        int cur_idx = st.top().idx;
        int left = st.top().left;
        int right = st.top().right;

        st.pop();
        if (int i = 0; i < v[cur_idx].size(); i++) // 인접 노드 탐색
        {
            if(v[cur_idx][i] == cur_idx + 1)
                st.push({})
        }
    }

    return;
}

int main()
{

    cin >> n; // 노드 총 개수
    v.resize(n + 1);

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        while (1)
        {
            int k;
            cin >> k;
            if (k == -1)
                break;
            v[t].push_back(k);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end()); // 오름차순 정렬
    }

    cin >> r; // 루트 노드 번호

    go(r, 0, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << i << ' ' << ans[i].first << ' ' << ans[i].second << '\n';
    }
}