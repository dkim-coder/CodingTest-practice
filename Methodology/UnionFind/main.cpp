#include <iostream>

// union find 정리
namespace unionfind
{
    using namespace std;

    int func_find(int parent[], int node);

    void func_union(int parent[], int node1, int node2)
    {
        // 부모 노드 탐색
        int parent_node1 = func_find(parent, node1);
        int parent_node2 = func_find(parent, node2);

        if (parent_node1 == parent_node2) // 부모 노드가 같다면 같은 집합에 속하기 때문에 종료
            return;

        // 부모 노드를 서로 같게 해주는데, 부모 노드가 더 작은곳으로 업데이트
        if (parent_node1 < parent_node2)
            parent[parent_node2] = parent_node1;
        else
            parent[parent_node1] = parent_node2;

        return;
    }

    // 해당 node가 속한 부모 노드를 찾아서 반환
    int func_find(int parent[], int node) // parent[] : 각 노드 번호의 부모 노드 번호를 저장하고 있는 배열, node 현재 탐색 노드
    {
        if (parent[node] == node)
            return node;
        return parent[node] = func_find(parent, parent[node]); // 부모노드를 찾게되면 해당 노드의 부모노드를 업데이트 하면서 찾는 과정 시간을 최적화
    }
}

using namespace unionfind;

int main()
{

    return EXIT_SUCCESS;
}