#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    string in_str;
    string bomb_str;
    stack<char> st;

    cin >> in_str;
    cin >> bomb_str;

    for (auto i : in_str)
    {
        st.push(i);
        if (i != bomb_str.back())   // back 맨 마지막 반환
            continue;
        else
        {
            string tmp;
            for (int j = 0; j < bomb_str.length(); j++)
            {
                if(st.empty())
                    break;
                tmp.push_back(st.top());
                st.pop();
            }
            reverse(tmp.begin(), tmp.end());    // algorihtm 에 reverse 하면 순서 바꿔줌
            if (tmp != bomb_str)
            {
                for (auto k : tmp)
                {
                    st.push(k);
                }
            }
        }
    }

    string answer;
    while (!st.empty())
    {
        answer += st.top();
        st.pop();
    }
    reverse(answer.begin(), answer.end());

    if (!answer.length())
        cout << "FRULA" << endl;
    else
        cout << answer << endl;

    return EXIT_SUCCESS;
}