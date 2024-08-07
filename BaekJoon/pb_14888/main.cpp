#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// +, -, *, /

pair<long long, long long> solution(const char n, char a[], char op[])
{
    long long max_res = -9999999999;
    long long min_res = 9999999999;

    vector<char> v;
    for(char i = 0; i < 4; i++)
    {
        for(char j = 0; j < op[i]; j++)
            v.push_back(i);
    }

    do
    {
        long long tmp = a[0];
        for(char i = 0; i < n - 1; i++)
        {
            if(v[i] == 0)
                tmp += a[i + 1];
            else if(v[i] == 1)
                tmp -= a[i + 1];
            else if(v[i] == 2)
                tmp *= a[i + 1];
            else
                tmp /= a[i + 1];
        }
        if(tmp < min_res)
            min_res = tmp;
        
        if(tmp > max_res)
            max_res = tmp;
    }while(next_permutation(v.begin(), v.end()));

    return make_pair(max_res, min_res);
}

int main()
{
    char n;
    char a[11];
    char op[4];

    scanf("%hhd", &n);
    for(char i = 0; i < n; i++)
        scanf("%hhd", &a[i]);
    
    for(char i = 0; i < 4; i++)
        scanf("%hhd", &op[i]);

    pair<long long, long long> res = solution(n, a, op);
    printf("%lld\n%lld\n", res.first, res.second);

    return 0;
}