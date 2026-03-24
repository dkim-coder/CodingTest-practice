#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

static int N, M;
static vector<int> v;
// static vector<bool> visited;
static vector<int> ans;

bool comp(const int &a, const int &b){
    return a < b;
}

void permutation(const int &idx, const int &cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++)
            cout << ans[i] << " ";
        cout << endl;
        return;
    }

    for(int i = idx; i < N; i++)
    {
        // if(visited[i])
        //     continue;
        
        // visited[i] = true;
        ans[cnt] = v[i];
        permutation(idx, cnt + 1);
        // visited[i] = false;
    }
    
    return;
}

int main(int argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;

    v.resize(N);
    ans.resize(M);
    // visited.assign(N, false);
    for(int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), comp);
    permutation(0, 0);

    return 0;
}