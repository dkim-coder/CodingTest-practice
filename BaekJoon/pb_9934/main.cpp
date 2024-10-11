#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int K;
template<typename T>
using myVector = vector<T>;
myVector<int> V;

void solution(int l, int r, int depth, myVector<myVector<int>> &tree)
{
    if(l == r)
    {
        tree[depth].push_back(V[l]);
        return;
    }
    int m = (l + r) >> 1;
    tree[depth].push_back(V[m]);
    solution(l, m - 1, depth + 1, tree);
    solution(m + 1, r, depth + 1, tree);

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K;
    int tmp;
    for(int i = 0; i < pow(2, K) - 1; i++){
        cin >> tmp;
        V.push_back(tmp);
    }

    myVector<myVector<int>> tree(K);
    solution(0, static_cast<int>(V.size() - 1), 0, tree);
    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j < tree[i].size(); j++)
            cout << tree[i][j] << " ";
        cout << "\n"; 
    }

    return 0;
}