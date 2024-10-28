# Union Find

1. Find
    int find(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }
2. Union
    void merge(int node1, int node2)
    {
        u = find(node1);
        v = find(node2);
        if(u == v)
            return;
        parent[u] = v;
    }