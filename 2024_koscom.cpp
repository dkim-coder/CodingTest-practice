#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define endl "\n"

vector<string> input = {"SEOUL", "DAEGU", "DAEGEON", "GWANGJU"};
vector<string> output = {"S", "D", "A", "G"};

/*
    1. 도시 이름 맨 앞 k 개 글자가 별칭
    2. 이전 별칭들과 겹친다면 순서가 바뀌지 않는 선에서 가능한 조합 중 알파벳 순서
    3. 도시 이름이 k 보다 부족하다면 '_' 로 채워줌
*/

vector<string> solution(vector<string> cities)
{
    vector<string> answer(cities.size());

    int len = 1;

    while(true)
    {
        set<string> s;
        for(int i = 0; i < cities.size(); i++)
        {
            string str;
            
            if(len <= cities[i].length())
            {
                str = cities[i].substr(0, len);
                if(s.find(str) == s.end())
                {
                    s.insert(str);
                    answer[i] = str;
                }else{
                    vector<int> v(cities[i].length(), 1);
                    vector<string> candidate;
                    for(int j = 0; j < len; j++)
                        v[j] = 0;
                    
                    do{
                        string tmp;
                        for(int j = 0; j < v.size(); j++)
                            if(!v[j])
                                tmp += cities[i][j];
                        candidate.push_back(tmp);
                    }while(next_permutation(v.begin(), v.end()));

                    sort(candidate.begin(), candidate.end());

                    for(int j = 0; j < candidate.size(); j++)
                    {
                        if(s.find(candidate[j]) == s.end())
                        {
                            s.insert(candidate[j]);
                            answer[i] = candidate[j];
                            break;
                        }
                    }

                    if(s.size() == i)
                    {
                        len++;
                        break;
                    }
                }
            }else{
                str = cities[i];
                for(int j = 0; j < len - cities[i].length(); j++)
                    str += '_';
                s.insert(str);
                answer[i] = str;
            }
        }
        
        if(s.size() == cities.size())
            break;
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> answer = solution(input);
    for(auto a : answer)
        cout << a << " ";
    cout << endl;
    
    return EXIT_SUCCESS;
}