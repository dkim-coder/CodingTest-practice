# 탐색 방법 

## DFS
- 스택 자료구조 활용
```cpp
template <typename T>
void dfs_stack()
{
    stack<T> st;                    // 스택 선언
    vector<bool> visit;             // 노드 방문 여부 표시
    st.push(node);                  // 시작 노드 스택에 삽입
    visit[node] = true;             // 시작 노드 방문 표시
    
    while(!st.empty())              // 스택이 비어있을 때 까지 반복
    {
        // 스택에서 노드 꺼내기
        T cur_node = st.top();  
        st.pop();

        for(;;){                    // 꺼낸 노드와 연결된 노드 탐색
            if(visit[next_node])    // 다음 노드가 이미 방문되었다면 탐색 x
                continue;
            // 방문되지 않은 노드라면 방문처리 후 스택에 삽입
            visit[next_node] = true;    
            st.push(next_node);
        }
    }
}
```

- 재귀호출 구현
```cpp
vector<bool> visit;
template <typename T>
void dfs_recursive(T cur_node)
{
    visit[cur_node] = true;     // 현재 노드 방문 표시

    for(;;){                    // 현재 노드와 인접한 노드 탐색
        if(!visit[next_node])   // 다음 노드가 방문되지 않았을 경우 재귀 호출
            dfs(next_node);
    }
}
```

## BFS
- 큐 자료구조 활용
```cpp
template <typename T>
void bfs_queue()
{
    queue<T> q;                    // 큐 선언
    vector<bool> visit;            // 노드 방문 여부 표시
    q.push(node);                  // 시작 노드 큐에 삽입
    visit[node] = true;            // 시작 노드 방문 표시
    
    while(!q.empty())              // 큐가 비어있을 때 까지 반복
    {
        // 큐에서 노드 꺼내기
        T cur_node = q.front();  
        q.pop();

        for(;;){                    // 꺼낸 노드와 연결된 노드들 탐색
            if(visit[next_node])    // 다음 노드가 이미 방문되었다면 탐색 x
                continue;
            // 방문되지 않은 노드라면 방문처리 후 큐에 삽입
            visit[next_node] = true;    
            q.push(next_node);
        }
    }
}
```

## Backtracking
### 탐색 공간 최적화 방법
- 현재 탐색하는 노드에서 다음 탐색할 노드들이 더 이상 의미없는 경우에 사용하는 기법.
- 만약 유망하지 않다면, 이전 부모노드로 돌아가 다른 노드들의 탐색을 시작한다.
```cpp
template <typename T>
void backtracking(T cur_node)
{
    if(cur_node is not promising)       // 탐색하는 노드가 유망하지 않다면 다음 노드 탐색하지 않음
        return;
    
    if(end condition){                  // 정답을 찾았다면 업데이트
        write the solution
        return;
    }

    for(;;){                            // 다음 탐색할 노드들 재귀 호출
        backtracking(next_node);
    }
}
```