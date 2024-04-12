#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int n, m;
    int res = 0;
    cin >> n >> m;
    unordered_set<string> us;
    for (int i = 0; i < n; i++)
    {
        string in;
        cin >> in;
        us.insert(in);
    }

    for (int i = 0; i < m; i++)
    {
        string in;
        cin >> in;
        if (us.find(in) != us.end())
            res++;
    }

    cout << res << endl;

    return EXIT_SUCCESS;
}