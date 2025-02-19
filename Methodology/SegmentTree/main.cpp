#include <iostream>
#include <vector>
#include <cmath>

#define SIZE 10
namespace segmenttree
{
    using namespace std;

    vector<int> arr;
    vector<int> seg_tree;

    inline void setting()
    {
        arr.resize(SIZE);
        for (int i = 0; i < SIZE; i++)
            arr[i] = rand() % 100; // Random integer between 0 and 99
        seg_tree.resize(SIZE * 4, 0);

        return;
    }
    /*
    세그먼트 트리 구성
    @param
    start : 배열의 시작 인덱스
    end : 배열의 끝 인덱스
    idx : 세그먼트 트리 인덱스
    */
    int init(const int start, const int end, const int idx) // (구하고자 하는 배열 구간의 시작, 끝, 해당 값이 저장될 세그먼트 트리 인덱스)
    {
        if (start == end)
        {
            seg_tree[idx] = arr[start];
            return seg_tree[idx]; // 세그먼트 트리 부모 노드 값 계산을 위해 반환
        }

        int mid = (start + end) / 2; // 배열 인덱스 쪼갬
        return seg_tree[idx] = init(start, mid, idx * 2) + init(mid + 1, end, idx * 2 + 1);
    }

    /*
    구간합 반환
    @param
    start : 현재 배열 구간의 시작 인덱스
    end : 현재 배열 구간의 끝 인덱스
    idx : 시작 인덱스와 끝 인덱스의 구간합 값이 저장되어 있는 세그먼트 트리 인덱스
    left : 구간합을 구하고자 하는 배열 구간의 왼쪽 인덱스
    right : 구간합을 구하고자 하는 배열 구간의 오른쪽 인덱스
    */
    int interval_sum(const int start, const int end, const int idx, const int left, const int right)
    {
        if (left > end || right < start)
            return 0;

        if (left <= start && end <= right)
            return seg_tree[idx];

        int mid = (start + end) / 2;
        return interval_sum(start, mid, idx * 2, left, right) + interval_sum(mid + 1, end, idx * 2 + 1, left, right);
    }

    /*
    배열의 값이 바뀌면 해당 세그먼트 트리 업데이트 하는 함수
    @param
    start : 현재 보는 배열 시작 인덱스
    end : 현재 보는 배열 끝 인덱스
    idx : 현재 보는 배열의 구간 합 값을 가지고 있는 세그먼트 트리 인덱스
    what : 구간 합을 수정하고자 하는 노드
    value : 수정할 값 -> 얼마만큼 수정할 건지를 넣어주면 된다.
    */
    void update(const int start, const int end, const int idx, const int what, const int value)
    {
        if (what < start || what > end)
            return;

        seg_tree[idx] += value;
        if (start == end)
            return;
        int mid = (start + end) / 2;
        update(start, mid, idx * 2, what, value);
        update(mid + 1, end, idx * 2 + 1, what, value);
    }

}

using namespace segmenttree;

int main()
{
    setting();
    init(0, SIZE - 1, 1);
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    cout << "\n";
    for (int i = 1; i < seg_tree.size(); i++)
        cout << seg_tree[i] << " ";

    return EXIT_SUCCESS;
}