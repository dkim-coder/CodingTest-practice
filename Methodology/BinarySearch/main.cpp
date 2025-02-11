#include <iostream>

#define SIZE 10


namespace binarysearch{
    using namespace std;

    int arr[SIZE] = {23, 45, 12, 67, 34, 89, 78, 56, 90, 11};

    // 반복
    template <typename T>
    int binarysearch_for(T arr[], int size, T target){
        int start = 0;
        int end = size - 1;
        int mid;

        while(end >= start){
            mid = (start + end) / 2;
            if(arr[mid] == target)
                return mid;
            else if(arr[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;    
        }

        return -1;
    }

    // 재귀
    template <typename T>
    T binarysearch_recursive(T arr[], int start, int end, T target)
    {
        if(start > end)
            return -1;
        
        int mid = (start + end) / 2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            binarysearch_recursive(arr, mid + 1, end, target);
        else
            binarysearch_recursive(arr, start, mid - 1, target);
    }
}

using namespace binarysearch;

int main()
{

    return EXIT_SUCCESS;
}