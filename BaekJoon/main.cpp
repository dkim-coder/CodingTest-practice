#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

static int test_case, n, d, c, a, b, s;
static vector<int> dist;
static vector<vector<pair<int,int>>> graph;

struct comp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    }
};

pair<int, int> solution()
{
    pair<int, int> res = {0, 0};
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    fill(dist.begin() + 1, dist.begin() + n + 1 , INT32_MAX);
    pq.push({c, 0});
    dist[c] = 0;

    while(!pq.empty())
    {
        int cur = pq.top().first;
        int cur_dist = pq.top().second;
        pq.pop();
        if(cur_dist > dist[cur])
            continue;

        for(const auto &i : graph[cur])
        {
            if(dist[i.first] > dist[cur] + i.second)
            {
                dist[i.first] = dist[cur] + i.second;
                pq.push({i.first, dist[i.first]});
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(dist[i] != INT32_MAX){
            res.first++;
            res.second = max(res.second, dist[i]);
        }
    }

    return res;
}

int main(int argc, char *argv[])
{
    cin >> test_case;
    while(test_case--)
    {
        cin >> n >> d >> c;
        dist = vector<int>(n + 1);
        graph = vector<vector<pair<int, int>>>(n + 1);
        for(int i = 0; i < d; i++)
        {
            cin >> a >> b >> s;
            graph[b].push_back({a, s});
        }
        pair<int, int> res = solution();
        cout << res.first << " " << res.second << endl;
    }

    return 0;
}