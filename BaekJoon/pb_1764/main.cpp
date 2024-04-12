#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> name;
    unordered_set<string> us;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        us.insert(tmp);
    }

    for (int i = 0; i < m; i++)
    {
        string tmp;
        cin >> tmp;
        if (us.find(tmp) != us.end())
            name.push_back(tmp);
    }

    sort(name.begin(), name.end());

    cout << name.size() << endl;
    for (auto n : name)
        cout << n << endl;

    return EXIT_SUCCESS;
}