#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int N = 1000000;
static vector<int> v;
static vector<int> dp;

int solution1(){
    int res = 0;

    dp.assign(N, 1);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            if(v[j] < v[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }

    return res;
} 

int solution2(){
    vector<int> res;
    
    for(const auto &i: v){
        if(res.empty() || i > res.back())
            res.push_back(i);
        else{
            int idx = lower_bound(res.begin(), res.end(), i) - res.begin(); // 크거나 같은 첫번째 반환
            res[idx] = i;
        }
    }

    return res.size();
}

int main(int argc, char *argv[]){
    cin >> N;
    int input;
    for(int i = 0; i < N; i++)
    {
        cin >> input;
        v.push_back(input);
    }

    cout << solution2() << endl;

    return 0;
}