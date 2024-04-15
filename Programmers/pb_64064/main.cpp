#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool comp(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    else
    {
        for (int i = 0; i < str1.length(); i++)
        {
            if (str1[i] == '*')
                continue;
            else if (str1[i] != str2[i])
                return false;
        }
    }

    return true;
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    int answer = 0;

    vector<vector<int>> v(banned_id.size());

    for (int i = 0; i < banned_id.size(); i++)
    {
        for (int j = 0; j < user_id.size(); j++)
        {
            if (comp(banned_id[i], user_id[j]))
                v[i].push_back(j);
        }
    }

    return answer;
}

int main()
{
    vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id = {"fr*d*", "abc1**"};

    cout << solution(user_id, banned_id) << endl;

    return EXIT_SUCCESS;
}