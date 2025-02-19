#include <iostream>
#include <vector>
#include <cmath>

#define SIZE 10
namespace segmenttree
{
    using namespace std;

    vector<int> arr;      // 세그먼트 트리 구성에 사용될 배열
    vector<int> seg_tree; // 세그먼트 트리 -> 세그먼트 트리는 인덱스 1부터 시작 -> 왜냐하면 이렇게 하면 왼쪽 자식 오른쪽 자식 노드의 인덱스를 계산하기 쉬움
    // 예를 들어, 루트 노드의 인덱스 1, 루트 노드의 왼쪽 자식노드 인덱스 1 * 2, 루트 노드의 오른쪽 자식노드 인덱스 1 * 2 + 1

    /**
     * @brief 세그먼트 트리를 구성에 사용될 배열 값 세팅
     * 
     * @return void
     */
    inline void setting()
    {
        arr.resize(SIZE);
        for (int i = 0; i < SIZE; i++)
            arr[i] = rand() % 100; // 0 ~ 99 까지의 정수형 난수 생성
        seg_tree.resize(SIZE * 4, 0);   // 세그먼트 트리는 넉넉히 4를 곱해서 크기 생성

        return;
    }
    /**
    * @brief 세그먼트 트리 초기화
    * 
    * @param start 세그먼트 트리 구성에 사용될 배열의 시작 인덱스
    * @param end 세그먼트 트리 구서에 사용될 배열 끝 인덱스
    * @param idx 세그먼트 트리 노드 인덱스
    * @return const int 세그먼트 노드 값
    * @note 배열의 시작인덱스와 끝 인덱스 및 세그먼트 트리 시작 인덱스 세팅 주의
    */
    const int init(const int start = 0, const int end, const int idx = 1) 
    {
        if (start == end)
        {
            seg_tree[idx] = arr[start];
            return seg_tree[idx]; // 세그먼트 트리 부모 노드 값 계산을 위해 반환
        }

        int mid = (start + end) / 2; // 배열 분할
        return seg_tree[idx] = init(start, mid, idx * 2) + init(mid + 1, end, idx * 2 + 1); // 왼쪽 자식노드와 오른쪽 자식노드 값을 더해서 세그먼트 트리에 값 대입한다는 뜻
    }

    /**
     * @brief 세그먼트 트리를 사용해서 배열의 구간 합 반환
     * 
     * @param start 배열의 시작 인덱스
     * @param end 배열의 끝 인덱스
     * @param idx 세그먼트 트리 인덱스
     * @param left 배열의 구간합을 구할 왼쪽 인덱스
     * @param right 배열의 구간합을 구한 오른쪽 인덱스
     * @return int
     * @note start, end 그리고 idx 값 초기 설정 주의
     */
    int interval_sum(const int start = 0, const int end, const int idx = 1, const int left, const int right)
    {
        if (left > end || right < start)
            return 0;

        if (left <= start && end <= right)
            return seg_tree[idx];

        int mid = (start + end) / 2;
        return interval_sum(start, mid, idx * 2, left, right) + interval_sum(mid + 1, end, idx * 2 + 1, left, right);
    }

    /**
    * @brief 배열의 값을 수정했을 때 세그먼트 트리 업데이트 함수
    *
    * @param start : 현재 보는 배열 시작 인덱스
    * @param end : 현재 보는 배열 끝 인덱스
    * @param idx : 현재 보는 배열의 구간 합 값을 가지고 있는 세그먼트 트리 인덱스
    * @param what : 구간 합을 수정하고자 하는 노드
    * @return void
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