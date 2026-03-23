#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int N, M;
static vector<int> v;

void binary_search(int start, int end, int value){
    if(start > end){
        cout << 0 << "\n"; // endl을 \n으로 변경
        return;
    }
    
    int mid = (start + end) / 2;
    
    if(v[mid] == value){
        cout << 1 << "\n"; // endl을 \n으로 변경
        return;
    }else if(v[mid] < value)
    {
        binary_search(mid + 1, end, value);
    }else{
        binary_search(start, mid - 1, value);
    }

    return;
}

int main(int argc, char *argv[])
{
    // 백준 C++ 필수! 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int input;
        cin >> input;
        binary_search(0, N - 1, input);
    }

    return 0;
}