#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

char tmp[200];

string solution(string s) {
    string answer = "";
    bool flag = true;
    int idx = 0;

    for(const auto &i : s)
    {
        if(i == ' ')
        {
            flag = true;
            tmp[idx] = i;
            idx++;
            continue;
        }
        
        if(flag)
        {
            tmp[idx] = toupper(i);
            flag = false;
        }
        else{
            tmp[idx] = tolower(i);
        }

        idx++;
    }

    answer = tmp;

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "3people unFollowed me";

    cout << solution(s) << endl;

    return EXIT_SUCCESS;
}