#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int dfs(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<bool> check(n, false); // 노드 방문했는지 체크하기 위함
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (!check[i]) // 초기 노드 삽입 부분
        {
            st.push(i);
            check[i] = true;
        }
        else
        {
            continue;
        }

        while (!st.empty())
        {
            int cur_node = st.top();
            st.pop();
            for (int j = 0; j < computers[cur_node].size(); j++) // 인접 노드 탐색 부분
            {
                if (!check[j] && cur_node != j && computers[cur_node][j] == 1) // 인접한거 방문으로 바꾸기
                {
                    check[j] = true;
                    st.push(j);
                }
            }
        }
        answer++;
    }
    return answer;
}

int bfs(int n, vector<vector<int>> computers)
{
    int answer = 0;
    queue<int> q;
    vector<bool> check(n, false);   // 방문을 체크하기 위한 부분

    for (int i = 0; i < n; i++)     // 노드 전부 탐색해야하기 때문에 반복문으로 묶어줌
    {
        if (!check[i])  // 방문되지 않은거에서 시작
        {
            q.push(i); // 초기 노드 삽입
            check[i] = true;
        }else{  // 이미 방문한건 할 필요가 없음
            continue;
        }

        while (!q.empty())
        {
            int cur_node = q.front();   // 시작시는 항상 빼고 시작
            q.pop();

            for (int j = 0; j < computers[cur_node].size(); j++) // 인접 노드 체크
            {
                if (cur_node != j && !check[j] && computers[cur_node][j]) // 같으면 안되고, 방문한것도 안되고, 연결되어있어야하고
                {
                    q.push(j);
                    check[j] = true;
                }
            }
        }
        answer++;
    }

    return answer;
}

int main()
{
    vector<vector<int>> computers = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

    cout << dfs(3, computers) << endl;
    cout << bfs(3, computers) << endl;

    return 1;
}