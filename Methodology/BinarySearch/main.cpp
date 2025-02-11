#include <iostream>
#include <algorithm>

#define SIZE 10

// 이분 탐색
namespace binarysearch
{
    using namespace std;

    int arr[SIZE] = {23, 45, 12, 67, 34, 89, 78, 56, 90, 11}; // 테스트 데이터 배열

    // 이분탐색 반복 구현
    int binarysearch_for(int arr[], const int size, const int target)
    {                       // arr : 탐색 배열, size : 배열 크기, target : 찾고자 하는 숫자(타켓)
        int start = 0;      // 탐색 왼편 끝
        int end = size - 1; // 탐색 오른편 끝
        int mid;            // 탐색 중간

        while (start <= end)
        {
            mid = (start + end) / 2; // 중간 탐색
            if (arr[mid] == target)  // 타겟 찾으면 반환
                return mid;
            else if (arr[mid] < target) // 타깃보다 현재가 작으면 오른편에 있다는 뜻이기 때문에 왼쪽 나타내는 인덱스 1 증가
                start = mid + 1;
            else
                end = mid - 1; // 타깃보다 현재가 크면 왼편에 있다는 뜻이기 때문에 오른쪽 나타내는 인덱스 1 감소
        }

        return -1; // 찾지 못하면 -1 반환
    }

    // 이분 탐색 재귀 구현
    int binarysearch_recursive(const int arr[], int start, int end, const int target)
    {
        if (start > end)
            return -1;

        int mid = (start + end) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            binarysearch_recursive(arr, mid + 1, end, target);
        else
            binarysearch_recursive(arr, start, mid - 1, target);
    }
}

using namespace binarysearch;

int main()
{
    sort(arr, arr + 10);    // 이분 탐색을 위해서는 정렬된 상태에서 시작해야 함.
    cout << "=============== 이분 탐색 반복 구현 ===============" << endl;
    cout << binarysearch_for(arr, SIZE, 67) << endl;
    cout << "=============== 이분 탐색 재귀 구현 ===============" << endl;
    cout << binarysearch_recursive(arr, 0, SIZE, 67) << endl;;

    return EXIT_SUCCESS;
}