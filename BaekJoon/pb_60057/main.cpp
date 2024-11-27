#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

int solution(string s) {
    int answer = 0;
    
    int max_token_len = s.length() / 2;

    answer = s.length();
    for(int i = 1; i <= max_token_len; i++)
    {
        int tmp = s.length();
        for(int j = 0; j <= s.length() - i * 2;)
        {
            if(s.substr(j, i) == s.substr(j + i, i))
            {
                string str = s.substr(j, i);
                int cnt = 1;
                int cur_idx = j;
                while(str == s.substr(cur_idx + i * cnt, i))
                {
                    cnt++;
                }
                j += i * cnt;
                tmp -= (cnt * i - (to_string(cnt).length() + i));
            }else
                j += i;
        }
        answer = min(answer, tmp);
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "aaaaaaaaaabbbbbbbbbb";

    cout << solution(s) << endl;

    return EXIT_SUCCESS;
}