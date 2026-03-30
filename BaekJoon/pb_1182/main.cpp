#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int N, S;
static int arr[20];

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int res = 0;
    cin >> N >> S;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    for(int i = 0; i < (1 << N); i++)
    {
        int sum = 0;
        for(int j = 0; j < N; j++)
        {
           if(i & (1 << j))
            sum += arr[j]; 
        }
        if(sum == S)
            res++;
    }
    if(S == 0)
        res--;

    cout << res << endl;

    return 0;
}