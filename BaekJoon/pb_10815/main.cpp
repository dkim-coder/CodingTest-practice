#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> my, int num)
{
    int start = 0;
    int end = my.size() - 1;
    int mid;

    while(start <= end)
    {
        mid = (start + end) / 2;
        if(my[mid] == num)
            return 1;
        else if(my[mid] < num)
        {
            start = mid + 1;
        }else
        {
            end = mid - 1;
        }
    }

    return 0;
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> my(n);
    for (int i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;
        my.push_back(tmp);
    }
    sort(my.begin(), my.end());

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        long long tmp;
        cin >> tmp;
        cout << binarySearch(my, tmp) << " ";
    }

    return EXIT_SUCCESS;
}