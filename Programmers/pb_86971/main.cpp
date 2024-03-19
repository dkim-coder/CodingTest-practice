#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int solution(int n, vector<vector<int>> wires)
{
    int res = n;
    unordered_set<int> us1, us2;

    for (int i = 0; i < wires.size(); i++)
    {
        vector<vector<int>> tmp(wires);
        us1.insert(tmp[i][0]);
        us2.insert(tmp[i][1]);
        tmp.erase(tmp.begin() + i);
        do
        {
            for (int j = 0; j < tmp.size(); j++)
            {
                if (us1.find(tmp[j][0]) != us1.end())
                {
                    us1.insert(tmp[j][1]);
                    tmp.erase(tmp.begin() + j);
                }
                else if (us1.find(tmp[j][1]) != us1.end())
                {
                    us1.insert(tmp[j][0]);
                    tmp.erase(tmp.begin() + j);
                }
                else if (us2.find(tmp[j][0]) != us2.end())
                {
                    us2.insert(tmp[j][1]);
                    tmp.erase(tmp.begin() + j);
                }
                else if (us2.find(tmp[j][1]) != us2.end())
                {
                    us2.insert(tmp[j][0]);
                    tmp.erase(tmp.begin() + j);
                }
            }
        } while (tmp.size() != 0);

        if(abs((int)us1.size() - (int)us2.size()) < res)
            res = abs((int)us1.size() - (int)us2.size());

        us1.clear();
        us2.clear();
    }

    return res;
}

int main()
{
    vector<vector<int>> wires = {
        {1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}};

    cout << solution(9, wires) << endl;

    return EXIT_SUCCESS;
}