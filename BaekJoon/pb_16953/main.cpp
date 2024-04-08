#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long bfs(long long A, long long B)
{
    int res = -1;

    queue<pair<long long, int>> q;

    q.push({A, 1});
    while (!q.empty())
    {
        long long num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (num == B)
            return cnt;

        if(num > B) continue;

        q.push({num * 10 + 1, cnt + 1});
        q.push({num * 2, cnt + 1});
    }

    return res;
}

int main()
{
    long long A, B;

    cin >> A >> B;

    cout << bfs(A, B);

    return EXIT_SUCCESS;
}