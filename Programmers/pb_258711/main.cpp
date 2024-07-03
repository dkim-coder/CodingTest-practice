#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> edges)
{
    vector<int> answer(4, 0);
    vector<pair<int, int>> in_out_cnt(1000001, {0, 0});    // index -> node_num | first -> in, second -> out
    int node_num = 0;

    for(const auto &e : edges)
    {
        in_out_cnt[e[0]].second++;
        in_out_cnt[e[1]].first++;
        node_num = max(node_num, max(e[0], e[1]));
    }

    for(int i = 1; i <= node_num; i++)
    {
        if(in_out_cnt[i].first == 0 && in_out_cnt[i].second >= 2)   // addition node
            answer[0] = i;
        else if(in_out_cnt[i].first >= 1 && in_out_cnt[i].second == 0)  // 막대 그래프
            answer[2]++;
        else if(in_out_cnt[i].first >= 2 && in_out_cnt[i].second == 2)  // 8자
            answer[3]++;
    }

    answer[1] = in_out_cnt[answer[0]].second - answer[2] - answer[3];

    return answer;
}

int main()
{
    vector<vector<int>> edges = {{4, 11}, {1, 12}, {8, 3}, {12, 7}, {4, 2}, {7, 11}, {4, 8}, {9, 6}, {10, 11}, {6, 10}, {3, 5}, {11, 1}, {5, 3}, {11, 9}, {3, 8}};

    for (const auto &i : solution(edges))
        cout << i << endl;

    return EXIT_SUCCESS;
}