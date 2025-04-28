#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

static int n, s;    // n: 입력 벡터 길이, s: 넘어야 하는 목표 부분합 값
static vector<int> nums;

inline void input()
{
    cin >> n >> s;
    nums.clear();
    nums.resize(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    return;
}


/**
 * @brief s 보다 큰 가장 작은 부분 수열 길이 반환
 * @details 
 * 투 포인터 문제
 * 목표 값보다 작으면 오른쪽 포인터 오른쪽 이동
 * 목표 값보다 작으면 왼족 포인터 오른쪽 이동
 * - 중간 중간 목표 부분합 값보다 작으면 최소 길이 값 업데이트
 * time complexity O(N)
 * @note 만족하는 겂이 없으면 0 반환
 * @return const int
 */
const int solve()
{
    input();
    
    int ans = INT32_MAX;
    int left = 0, right = 0;
    int cur_sum, cur_length;
    
    cur_sum = nums[0];
    cur_length = 1;
    while(true)
    {
        if(cur_sum >= s && cur_length < ans)
            ans = cur_length;
        
        if(cur_sum < s){
            if(right == n - 1)
                break;
            cur_sum += nums[++right];
            cur_length++;
        }
        else{
            cur_sum -= nums[left++];
            cur_length--;
        }

    }

    if(ans == INT32_MAX)
        ans = 0;

    return ans;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve() << endl;

    return EXIT_SUCCESS;
}