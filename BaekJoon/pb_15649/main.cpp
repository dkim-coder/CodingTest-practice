#include <iostream>
#include <vector>

using namespace std;

static int N, M;
static vector<int> ans;

void permutation(const int cnt, const int flag)
{
    if(cnt == M){
        for(int i = 0; i < M; i++)
            cout << ans[i] << " ";
        cout << '\n';
        return;
    }

    for(int i = 0; i < N; i++)
    {
        if(flag & (1 << i))
            continue;
        
        ans[cnt] = i + 1;
        permutation(cnt + 1, flag | (1 << i));
    }

    return;
}

int main(int argc, char *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    ans.resize(M);

    permutation(0, 0);

    return 0;
}