#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

bool isChangable(string str1, string str2)
{
    int cnt = 0;
    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] != str2[i])
            cnt++;
    }

    if (cnt == 1)
        return true;
    else
        return false;
}

/*
문제의 특성상 최단이니까 bfs 가 채택
그리고 한번 실패한 단어 노드는 다른데서 방문될 필요가 없기 때문에 각 노드크기만큼만 방문됬는지 체크로 체크가능
시작 노드 세팅 후 -> 큐가 빌때 까지 하는데 타겟 문자와 같으면 종료 시키면 된다. -> 문제에 따라 달라지는 부분
*/
int bfs(string begin, string target, vector<string> words)
{
    int answer = 0;
    queue<pair<string, int>> q;
    vector<bool> visit(words.size(), false);

    q.push({begin, 0}); // 시작 노드 삽입
    while (!q.empty())
    {
        string tmp_str = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (target.compare(tmp_str) == 0)
        {
            answer = cnt;
            break;
        }

        for (int i = 0; i < words.size(); i++) // 인접 노드 탐색
        {
            if (!visit[i])
            {
                if (isChangable(tmp_str, words[i]))
                {
                    q.push({words[i], cnt + 1});
                    visit[i] = true;
                }
            }
        }
    }

    return answer;
}

int d_answer = 50;

void dfs(string cur, string target, vector<string> words, int depth, vector<bool> d_visit)
{
    if (d_answer <= depth)
        return;

    if (cur == target)
    {
        if (d_answer > depth)
            d_answer = depth;
        return;
    }

    for (int i = 0; i < words.size(); i++)
    {
        if (!d_visit[i] && isChangable(cur, words[i]))
        {
            d_visit[i] = true;
            dfs(words[i], target, words, depth + 1, d_visit);
            d_visit[i] = false;
        }
    }

    return;
}

int main()
{
    string begin = "hit";
    string target = "cog";
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<bool> d_visit(50, false);
    cout << bfs(begin, target, words) << endl;
    dfs(begin, target, words, 0, d_visit);
    cout << d_answer << endl;
    return EXIT_SUCCESS;
}