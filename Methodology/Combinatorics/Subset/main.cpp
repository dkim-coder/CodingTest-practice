#include <iostream>
#include <vector>

#define SIZE 3

// 부분 집합 구하는 방법 정리.
namespace subset{
    using namespace std;

    int arr[SIZE] = {1, 2, 3}; // test array
    bool check[SIZE];

    // 재귀 기반 부분집합 구하기 -> DFS
    void sub1(int cnt)   // cnt : 확인한 요소 개수
    {
        if (cnt == SIZE)
        {
            for(int i = 0; i < SIZE; i++)
                if(check[i])    
                    cout << arr[i] << " ";
            cout << endl;
            return;
        }

        // 현재 요소를 포함하지 않는 경우
        check[cnt] = true;
        sub1(cnt + 1);
 
        // 현재 요소를 포함하는 경우
        check[cnt] = false;
        sub1(cnt + 1);

        return;
    }
    
    // 바이너리 카운팅 기반 부분집합 구하기
    void sub2()
    {
        /*
        밑과 같이 표현되는 경우 1번비트에 있는 요소는 선택, 아닌 것은 선택하지 않는 방법
        000
        001    
         ~
        111
        */
        for(int i = 0; i < (1 << SIZE); i++)
        {
            for(int j = 0; j < SIZE; j++)
                if(i & (1 << j))    
                    cout << arr[j] << " ";
            cout << endl;
        }

        return;       
    }

}

using namespace subset;

int main()
{
    sub1(0);
    // sub2();
    
    return EXIT_SUCCESS;
}