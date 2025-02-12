#include <iostream>

#define SIZE 6

using namespace std;

// Divide and Conquer approach
namespace divide_conquer
{
    int arr[SIZE] = {4, 2, 6, 11, 16, 8};   // 테스트 배열
    int tmp[SIZE];                          // 임시로 저장할 배열

    void merge(int left, int right)
    {
        int mid = (left + right) / 2;
        int i = left;
        int j = mid + 1;
        int k = left;
        while (i <= mid && j <= right)
        {
            if (arr[i] < arr[j])
                tmp[k++] = arr[i++];
            else
                tmp[k++] = arr[j++];
        }

        // 왼쪽 혹은 오른쪽에 되지 않은거 밀어서 저장
        while (j <= right)
            tmp[k++] = arr[j++];
        while (i <= mid)
            tmp[k++] = arr[i++];

        for (k = left; k <= right; k++)
            arr[k] = tmp[k];

        return;
    }

    void merge_sort(int left, int right)
    {
        if (left < right)
        {
            int mid = (left + right) / 2;
            merge_sort(left, mid);              // divide -> 왼쪽
            merge_sort(mid + 1, right);         // divide -> 오른쪽
            merge(left, right);                 // combine -> conquer 이 포함
        }

        return;
    }

}

using namespace divide_conquer;

int main()

{
    merge_sort(0, SIZE - 1);
    for (const auto &i : arr)
        cout << i << " ";
    cout << "\n";

    return EXIT_SUCCESS;
}