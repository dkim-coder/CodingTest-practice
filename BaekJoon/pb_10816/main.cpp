#include <iostream>
#include <vector>
#include <unordered_map> // 해시 기능 key, value
#include <unordered_set> // 복수 같은 거 제거하기 위해서 사용 가능

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    vector<int> v1(n);
    for (int i = 0; i < n; i++)
        cin >> v1[i];
    cin >> m;
    vector<int> v2(m);
    for (int i = 0; i < m; i++)
        cin >> v2[i];

    unordered_map<int, int> um;
    for (auto v : v1)
        um[v] += 1;
    
    for (auto v : v2)
    {
        cout << um[v] << " ";
    }

    return EXIT_SUCCESS;
}