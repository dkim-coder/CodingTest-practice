#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

// pass-by-value
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    vector<vector<int>> matrix;
    vector<vector<int>> gift_scores;
    vector<int> next_gifts(friends.size(), 0);
    unordered_map<string, int> hash;    

    matrix.assign(friends.size(), vector<int>(friends.size(), 0));
    gift_scores.assign(friends.size(), vector<int>(3, 0));

    for(int i=0;i<friends.size();i++)
    {
        hash.insert(make_pair(friends[i], i));
    }

    for(int i=0;i<gifts.size();i++)
    {
        stringstream ss(gifts.at(i));
        string first, second;
        ss >> first >> second;
        matrix[hash.at(first)][hash.at(second)]++;
        gift_scores[hash[first]][0]++;
        gift_scores[hash[second]][1]++;
    }

    for(int i=0;i<gift_scores.size();i++)
    {
        gift_scores[i][2] = gift_scores[i][0] - gift_scores[i][1];
    }

    for(int i=0;i<friends.size();i++)
    {
        for(int j=i+1;j<friends.size();j++)
        {
            if(matrix[i][j] > matrix[j][i])
            {
                next_gifts[i]++;
            }else if(matrix[i][j] < matrix[j][i])
            {
                next_gifts[j]++;
            }else
            {
                if(gift_scores[i][2] > gift_scores[j][2])
                {
                    next_gifts[i]++;
                }
                else if(gift_scores[i][2] < gift_scores[j][2])
                {
                    next_gifts[j]++;
                }
            }
        }
    }
    
    auto tmp = max_element(next_gifts.begin(), next_gifts.end());
    answer = *tmp;

    return answer;
}

int main()
{
    vector<string> friends = {"muzi", "ryan", "frodo", "neo"};
    vector<string> gifts = {"muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"};

    int result = solution(friends, gifts);

    cout << result << endl;

    return EXIT_SUCCESS;
}