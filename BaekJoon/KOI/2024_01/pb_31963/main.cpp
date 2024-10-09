#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define endl "\n"

int N;
vector<int> A;

long long solution()
{
    long long answer = 0;
    
    vector<int> multiply_cnt(A.size(), 0);
    
    for (int i = 1 ; i < A.size() ; ++i) {
        multiply_cnt[i] = max((int)ceil(log2((double)A[i - 1]/ (double)A[i]) + (double)multiply_cnt[i - 1]), 0);
        
        answer += multiply_cnt[i];
    }
    
    return answer;
}

void Input()
{
    int num;
    
    cin >> N;
    
    A.clear();
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        A.push_back(num);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    cout << solution() << endl;

    return 0;
}