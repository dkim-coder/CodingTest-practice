#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

bool comp(int a, int b)
{
    return a < b;
}

pair<int, int> w_d(vector<vector<int>> dice, vector<int> ch, int n)
{
    pair<int, int> res;
    vector<int> a_c;
    vector<int> b_c;
    for (int i = 0; i < ch.size(); i++)
    {
        if (ch[i] == 1)
            a_c.push_back(i);
        else
            b_c.push_back(i);
    }

    int cnt = pow(6, n);
    vector<int> A_case(cnt, 0);
    vector<int> B_case(cnt, 0);

    for (int i = 0; i < cnt; i++)
    {
        int a_r = 0;
        int b_r = 0;
        int ccc = i;
        for (int j = n - 1; j >= 0; j--)
        {
            if (j > 0)
            {
                int ttt = ccc / (int)pow(6, j);
                a_r += dice[a_c[j]][ttt];
                b_r += dice[b_c[j]][ttt];
                ccc -= (int)pow(6, j) * ttt;
            }
            else
            {
                a_r += dice[a_c[j]][ccc % 6];
                b_r += dice[b_c[j]][ccc % 6];
            }
        }
        A_case[i] = a_r;
        B_case[i] = b_r;
    }

    int res_1 = 0;
    int res_2 = 0;
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < cnt; j++)
        {
            if (A_case[i] > B_case[j])
                res_1++;
            else if(A_case[i] < B_case[j])
                res_2++;
        }
    }

    res = {res_1, res_2};

    return res;
}

vector<int> solution(vector<vector<int>> dice)
{
    vector<int> answer;
    vector<int> idx(dice.size(), 0);
    int n = dice.size() / 2;
    for (int i = 0; i < n; i++)
        idx[i] = 1;
    sort(idx.begin(), idx.end(), comp);

    map<vector<int>, int> res;
    do
    {
        if (res.find(idx) == res.end())
        {
            pair<int, int> tmp = w_d(dice, idx, n);
            vector<int> tmp_idx(idx.size(), 0);
            for (int i = 0; i < idx.size(); i++)
            {
                if (idx[i] == 0)
                    tmp_idx[i] = 1;
                else
                    tmp_idx[i] = 0;
            }
            res[idx] = tmp.first;
            res[tmp_idx] = tmp.second;
        }else
        {
            continue;
        }
    } while (next_permutation(idx.begin(), idx.end()));

    int tt = 0;
    vector<int> tmp_answer;
    for (auto p : res)
    {
        if (p.second > tt){
            tt = p.second;
            tmp_answer = p.first;
        }
    }

    for (int i = 0; i < tmp_answer.size(); i++)
    {
        if (tmp_answer[i] == 1)
            answer.push_back(i + 1);
    }

    return answer;
}

int main()
{
    vector<vector<int>> dice = {{1, 2, 3, 4, 5, 6}, {3, 3, 3, 3, 4, 4}, {1, 3, 3, 4, 4, 4}, {1, 1, 4, 4, 5, 5}};

    vector<int> answer = solution(dice);

    for (auto i : answer)
        cout << i << " ";

    return EXIT_SUCCESS;
}