#include <iostream>
#include <algorithm>
#include <vector>

#define endl "\n"

using namespace std;

static int N;
static vector<int> v;

bool comp(const int &a, const int &b){
    return a < b;
}

int main(int argc, char *argv[])
{
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), comp);
    for(const auto &i : v)
        cout << i << endl;

    return 0;
}