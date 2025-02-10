#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 3

// 조합 구하는 방법 정리. nCr = n! / (n-r)!
namespace combination
{
    using namespace std;

    int arr[SIZE] = {1, 2, 3}; // test array
    bool visited[SIZE];        // 방문 여부 표시 배열
    int output[SIZE];          // 조합 저장 배열

    // 중복을 허용하지 않는 조합
    void combi1(int cnt, const int r, const int idx) // cnt : 현재까지 선택한 원소 개수, r : 뽑을 숫자 개수, idx : 현재 요소 뽑은 인덱스 가리킴
    {
        if (cnt == r) // 뽑고자 하는 개수만큼 뽑았다면 출력
        {
            for (int i = 0; i < r; i++)
                cout << output[i] << " ";
            cout << endl;
            return;
        }

        for (int i = idx; i < SIZE; i++)
        {
            output[cnt] = arr[i];
            combi1(cnt + 1, r, i + 1); // 현재 뽑은 인덱스 위부터 시작하도록 해서 밑 인덱스 숫자가 다시 시작되는 일을 방지
        }

        return;
    }

    // 중복을 허용하는 조합
    void combi2(int cnt, const int r, const int idx) // cnt : 현재까지 선택한 원소 개수, r : 뽑을 숫자 개수, idx : 현재 요소 뽑은 인덱스 가리킴
    {
        if (cnt == r) // 뽑고자 하는 개수만큼 뽑았다면 출력
        {
            for (int i = 0; i < r; i++)
                cout << output[i] << " ";
            cout << endl;
            return;
        }

        for (int i = idx; i < SIZE; i++)
        {
            output[cnt] = arr[i];
            combi1(cnt + 1, r, i); // 현재 뽑은 인덱스부터 시작을 가능하게 하지만 밑 인덱스 숫자가 다시 시작되는 일을 방지
        }

        return;
    }

    // c++ STL 사용 방법
    void combi_stl(const int r)
    {
        vector<bool> v(SIZE, true);
        for (int i = 0; i < r; i++)
            v[i] = false;
        do
        {
            for (int i = 0; i < SIZE; i++)
                if (!v[i])
                    cout << arr[i] << " ";
            cout << endl;
        } while (next_permutation(v.begin(), v.end()));

        return;
    }
}

using namespace combination;

int main()
{
    cout << "=========중복선택 허용x===========" << endl;
    combi1(0, 2, 0);
    cout << "=========중복선택 허용o===========" << endl;
    combi2(0, 2, 0);
    cout << "=========c++ stl next_permuation 사용===========" << endl;
    combi_stl(2);

    return EXIT_SUCCESS;
}