#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 1000002
#define Out first
#define In second

pair<int, int> InOutcheck[MAX] = {};

int maxNode = -1;

/*
TODO : 풀이 해설 작성 필요
*/

vector<int> solution(vector<vector<int>> edges) 
{
    vector<int> answer(4, 0);

    for (int i = 0; i < edges.size(); i++)
    {
        InOutcheck[edges[i][0]].Out++;  // 노드에서 나가는 간선의 수
        InOutcheck[edges[i][1]].In++;   // 노드로 들어오는 간선의 수
        maxNode = max(maxNode, max(edges[i][0], edges[i][1]));  // 총 노드 개수
    }

    for (int i = 1; i <= maxNode; i++)
    {
        if (InOutcheck[i].Out >= 2 && InOutcheck[i].In == 0)    // 나가는 간선이 2개 이상, 들어오는 간선이 0개
            answer[0] = i;
        else if (InOutcheck[i].Out == 0 && InOutcheck[i].In >= 1)
            answer[2]++;
        else if (InOutcheck[i].Out >= 2 && InOutcheck[i].In >= 2)   // 나가고 들어오는개 2개 모두 2개 이상 8 자
            answer[3]++;
    }

    answer[1] = InOutcheck[answer[0]].Out - (answer[2] + answer[3]);

    return answer;
}

int main()
{
    vector<vector<int>> edges = {{4, 11}, {1, 12}, {8, 3}, {12, 7}, {4, 2}, {7, 11}, {4, 8}, {9, 6}, {10, 11}, {6, 10}, {3, 5}, {11, 1}, {5, 3}, {11, 9}, {3, 8}};

    for (const auto &i : solution(edges))
        cout << i << endl;

    return EXIT_SUCCESS;
}