#include <iostream>
#include <vector>

using namespace std;

long long solution(const vector<int> &a, const int b, const int c)
{
    long long res = 0;
    long long tmp;

    for(const auto &i : a)
    {
        res++;
        tmp = i - b;
        if(tmp > 0)
        {
            res += tmp / c;
            if(tmp % c != 0)
                res++;
        }

    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b, c;
    cin >> b >> c;

    cout << solution(a, b, c) << "\n";

    return EXIT_SUCCESS;
}