#include <iostream>
#include <vector>
#include <algorithm>

#define EXIT_SUCCESS 0
#define METHOD_NUM 3

namespace my
{
    using namespace std;

    template <typename T>
    class Solution
    {
    private:
        T number;
        using method_ptr = T (Solution<T>::*)(const T n) const;
        static const method_ptr methods[METHOD_NUM];

    public:
        Solution() = default;
        virtual ~Solution() = default;
        virtual void input();
        inline T div_2(const T n) const { return n / 2; }
        inline T div_3(const T n) const { return n / 3; }
        inline T minus_1(const T n) const { return n - 1; }
        void solve() const;
    };

    template <typename T>
    const typename Solution<T>::method_ptr Solution<T>::methods[METHOD_NUM] = {&Solution<T>::div_2, &Solution<T>::div_3, &Solution<T>::minus_1};

    template <typename T>
    void Solution<T>::input()
    {
        cin >> number;

        return;
    }

    template <typename T>
    void Solution<T>::solve() const
    {
        vector<int> dp(number + 1, 0);
        vector<int> path(number + 1, 0);
        for (auto i = 2; i <= number; ++i)
        {
            dp[i] = dp[i - 1] + 1;
            path[i] = i - 1;
            for (int j = 0; j < METHOD_NUM; ++j)
            {
                T result = (this->*methods[j])(i);
                if ((j == 0 && i % 2 == 0) || (j == 1 && i % 3 == 0) || j == 2)
                {
                    if (result > 0 && result <= number && dp[i] > dp[result] + 1)
                    {
                        dp[i] = dp[result] + 1;
                        path[i] = result;
                    }
                }
            }
        }
        cout << dp[number] << endl;

        vector<T> sequence;
        for (auto i = number; i != 0; i = path[i])
        {
            sequence.push_back(i);
        }
        for (const auto &num : sequence)
        {
            cout << num << " ";
        }
        cout << endl;
    }

}

using namespace my;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution<int> sol;
    sol.input();
    sol.solve();

    return EXIT_SUCCESS;
}