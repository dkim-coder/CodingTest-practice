# dfs/bfs 기본구조
## dfs/bfs(int x, int y)
### 
    // 필요에 따라 방문체크 한 것 확인하는 메모리 필요
    
    stack.push(시작노드) OR queue.push(시작노드)
    while(!stack.empty() OR !queue.empty())
    {
        stack.top() OR queue.front() 
        stack.pop() OR queue.pop()

        for(인접 노드 탐색)
        {
            // 내용은 문제에 따라 달라짐
            stack.push(노드) OR queue.push(노드)
        }
    }

## dfs 재귀
###
    - 종결조건
    - 인접정점들에 대해 재귀호출