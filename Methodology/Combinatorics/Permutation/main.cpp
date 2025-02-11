#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 3

// 순열 구하는 방법 정리. nPr = n! / (n-r)!
namespace permutation
{
    using namespace std;

    int arr[SIZE] = {1, 2, 3}; // test array
    bool visited[SIZE];        // 방문 여부 표시 배열
    int output[SIZE];          // 순열 저장 배열

    // 중복선택을 허용하지 않는 순열, visited 배열 활용
    void permute1(int cnt, const int &r) // cnt : 현재까지 선택한 원소 개수, r : 뽑을 숫자 개수
    {
        if (cnt == r) // 뽑고자 하는 개수만큼 뽑았다면 출력
        {
            for (int i = 0; i < r; i++)
                cout << output[i] << " ";
            cout << endl;
            return;
        }

        for (int i = 0; i < SIZE; i++)
        {
            if (visited[i]) // 이미 방문한 원소라면 건너뛴다.
                continue;
            output[cnt] = arr[i]; // 현재 원소를 뽑아온다.
            visited[i] = true;    // 방문 표시
            permute1(cnt + 1, r); // 다음 원소를 뽑으러 재귀 호출
            visited[i] = false;   // 방문 표시 해제
        }

        return;
    }

    // 중복선택을 허용하지 않는 순열, 비트 마스크 활용
    // 1번 비트 값이 1이면 1번째 원소는 방문했다는 것을 의미
    void permute2(int cnt, const int &r, int flag) // cnt : 현재까지 선택한 원소 개수, r : 뽑을 숫자 개수, flag : 비트로 방문 표시
    {
        if (cnt == r) // 뽑고자 하는 개수만큼 뽑았다면 출력
        {
            for (int i = 0; i < r; i++)
                cout << output[i] << " ";
            cout << endl;
            return;
        }

        for (int i = 0; i < SIZE; i++)
        {
            if (flag & (1 << i)) // 해당 비트가 1이면 방문했다는 의미
                continue;
            output[cnt] = arr[i];                  // 현재 원소를 뽑아온다.
            permute2(cnt + 1, r, flag | (1 << i)); // 다음 원소를 뽑으러 재귀 호출 및 비트 값으로 방문 표시
        }

        return;
    }

    // 중복선택을 허용하는 순열
    void permute3(int cnt, const int &r) // cnt : 현재까지 선택한 원소 개수, r : 뽑을 숫자 개수
    {
        if (cnt == r) // 뽑고자 하는 개수만큼 뽑았다면 출력
        {
            for (int i = 0; i < r; i++)
                cout << output[i] << " ";
            cout << endl;
            return;
        }

        for (int i = 0; i < SIZE; i++)
        {
            output[cnt] = arr[i]; // 현재 원소를 뽑아온다.
            permute3(cnt + 1, r); // 다음 원소를 뽑으러 재귀 호출
        }

        return;
    }

    // c++ STL 사용 방법
    void permute_stl(const int r)
    {
        vector<int> v(arr, arr + SIZE);
        sort(v.begin(), v.end());
        do
        {
            for (int i = 0; i < r; i++)
                cout << v[i] << " ";
            cout << endl;
        } while (next_permutation(v.begin(), v.end()));

        return;
    }
}

using namespace permutation;

int main()
{
    cout << "=========중복선택 허용x===========" << endl;
    permute1(0, 3);
    cout << "=========중복선택 허용x 비트마스크 방법===========" << endl;
    permute2(0, 3, 0);
    // cout << "=========중복선택 허용o===========" << endl;
    // permute3(0, 3);
    cout << "=========c++ stl next_permuation 사용===========" << endl;
    permute_stl(2);

    return EXIT_SUCCESS;
}