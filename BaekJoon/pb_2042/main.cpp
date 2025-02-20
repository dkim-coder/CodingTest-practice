#include <iostream>
#include <vector>

#define UPDATE 1
#define INTERVAL_SUM 2

using namespace std;
using ll = long long;

int N, M, K;
vector<ll> arr;     // input array
vector<ll> tree;    // segment tree
vector<pair<int, pair<int, ll>>> query; // {1: UPDATE, 2: INTERAL_SUM}, {a, b}

/**
 * @brief input N, M, K, arr, query
 * 
 * @return void
 */
inline void input()
{
    cin >> N >> M >> K;

    arr.resize(N);
    tree.resize(N * 4);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int a, b;
    ll c;
    for (int i = 0; i < M + K; i++)
    {
        cin >> a >> b >> c;
        query.push_back({a, {b, c}});
    }

    return;
}

/**
 * @brief 세그먼트 트리 초기화
 * 
 * @param start 배열 시작 인덱스
 * @param end 배열 끝 인덱스
 * @param idx 세그먼트 트리 인덱스
 * @return const long long 
 */
const ll initialize(const int start, const int end, const int idx)
{
    if (start == end)
    {
        tree[idx] = arr[start];
        return tree[idx];
    }

    int mid = (start + end) / 2;
    return tree[idx] = initialize(start, mid, idx * 2) + initialize(mid + 1, end, idx * 2 + 1);
}

/**
 * @brief 세그먼트 트리 업데이트
 * 
 * @param start 배열 시작 인덱스
 * @param end 배열 끝 인덱스
 * @param idx 세그먼트 트리 인덱스
 * @param target 배열의 업데이트 할 인덱스
 * @param diff 이전 배열 값과 업데이트 되는 값의 차이
 * @return void
 */
void update(const int start, const int end, const int idx, const int target, const ll diff)
{
    if (target < start || target > end) // target이 범위 밖이면
        return;

    tree[idx] += diff;

    if (start == end)
        return;

    int mid = (start + end) / 2;
    update(start, mid, idx * 2, target, diff);
    update(mid + 1, end, idx * 2 + 1, target, diff);

    return;
}

/**
 * @brief 배열의 부분합 구하기
 * 
 * @param start 배열의 시작 인덱스
 * @param end 배열의 끝 인덱스
 * @param idx 세그먼트 트리 인덱스
 * @param left 부분 합 구할 왼쪽 인덱스
 * @param right 부분 합 구할 오른쪽 인덱스
 * @return const long long 
 */
const ll interval_sum(const int start, const int end, const int idx, const int left, const int right)
{
    if (left > end || right < start)
        return 0;

    if (left <= start && end <= right)
        return tree[idx];

    int mid = (start + end) / 2;
    return interval_sum(start, mid, idx * 2, left, right) + interval_sum(mid + 1, end, idx * 2 + 1, left, right);
}

void solution()
{
    input();
    initialize(0, N - 1, 1); // make segment tree
    for (const auto &q : query)
    {
        if (q.first == UPDATE)
        {
            int target = q.second.first - 1;
            ll diff = q.second.second - arr[q.second.first - 1];
            arr[q.second.first - 1] = q.second.second;
            update(0, N - 1, 1, target, diff);
        }
        else
        { // INTERVAL_SUM
            cout << interval_sum(0, N - 1, 1, q.second.first - 1, q.second.second - 1) << "\n";
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();

    return 0;
}