#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 입력 숫자 값 반환
 *
 * @return const int
 */
inline const int input()
{
    int num = 0;
    cin >> num;

    return num;
}

/**
 * @brief 순열 재귀 구현, 비트 마스킹 사용
 * 
 * @param input_arr 원본 벡터
 * @param v 순열 저장 벡터
 * @param cnt 현재 순열 값 저장 개수 
 * @param flag 비트 마스킹 표현, 비트 값이 1이면 벡터의 해당 인덱스 값을 사용 했음을 의미
 * @return void
 */
void permutation(const vector<int> &input_arr, vector<int> &v, const int cnt, const int flag)
{
    if (cnt == v.size())
    {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < input_arr.size(); i++)
    {
        if (flag & (1 << i))
            continue;
        v[cnt] = input_arr[i];
        permutation(input_arr, v, cnt + 1, flag | (1 << i));
    }

    return;
}

/**
 * @brief 순열 출력
 *
 * @return void
 */
void solution()
{
    int num = input();
    vector<int> input_arr(num);
    vector<int> v(num);
    for (int i = 0; i < num; i++)
        input_arr[i] = i + 1;
    permutation(input_arr, v, 0, 0);

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();

    return 0;
}