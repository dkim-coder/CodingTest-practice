#include <iostream>
#include <cmath>

#define EXIT_SUCCESS 0
#define UNION 0
#define FIND 1
#define endl "\n"

using namespace std;

class solution
{
private:
    solution() = default;
    int n, m;
    int parent[1000001];
    bool func_union(const int node1, const int node2);
    int func_find(const int node);

public:
    static solution &get_instance();
    inline void input();
    void solve();
};

solution &solution::get_instance()
{
    static solution instance;
    return instance;
}

inline void solution::input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) // 여기에서 초기화도 같이
        parent[i] = i;

    return;
}

bool solution::func_union(const int node1, const int node2)
{
    int parent_node1 = func_find(node1);
    int parent_node2 = func_find(node2);

    if (parent_node1 == parent_node2)
        return true;

    if (parent_node1 < parent_node2)
        this->parent[parent_node2] = parent_node1;
    else
        this->parent[parent_node1] = parent_node2;

    return false;
}

int solution::func_find(const int node)
{
    if (this->parent[node] == node)
        return node;
    return this->parent[node] = func_find(parent[node]);
}

void solution::solve()
{
    int op, node1, node2;
    for (int i = 0; i < m; i++)
    {
        cin >> op >> node1 >> node2;
        switch (op)
        {
        case UNION:
            func_union(node1, node2);

            break;
        case FIND:
            int parent_node1 = func_find(node1);
            int parent_node2 = func_find(node2);

            if (parent_node1 == parent_node2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;

            break;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solution &s = solution::get_instance();
    s.input();
    s.solve();

    return EXIT_SUCCESS;
}