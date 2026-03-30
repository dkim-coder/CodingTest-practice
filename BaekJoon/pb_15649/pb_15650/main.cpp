#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int N, M;
static int arr[8];

void combination(const int cnt, const int idx)
{
    if(cnt == M)
    {
        for(int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << '\n';

        return;
    }

    for(int i = idx; i < N; i++)
    {
        arr[cnt] = i + 1;
        combination(cnt + 1, i + 1);
    }

    return;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    combination(0, 0);

    return 0;
}