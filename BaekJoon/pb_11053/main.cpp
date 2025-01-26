#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

template<typename T>
class Solution {
    private:
        int N;
        int answer;
        vector<T> arr;
    public:
        Solution();
        virtual ~Solution();
        virtual void set_answer(const int answer);
        virtual int get_answer() const;
        virtual void input();
        virtual void solution();
};

template<typename T>
Solution<T>::Solution() : N(0), answer(0) {}

template<typename T>
Solution<T>::~Solution() {}

template<typename T>
int Solution<T>::get_answer() const {
    return this->answer;
}

template<typename T>
void Solution<T>::set_answer(const int answer) {
    this->answer = answer;
    return;
}

template<typename T>
void Solution<T>::input()
{
    cin >> this->N;
    this->arr.resize(this->N, 0);
    for(int i = 0; i < this->N; ++i)
        cin >> this->arr[i];

    return;
}

template<typename T>
void Solution<T>::solution()
{
    // 10, 20, 50, 60, 30, 40, 70
    vector<int> dp(this->N, 1);
    for (int i = 1; i < this->N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (this->arr[i] > this->arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    this->set_answer(*max_element(dp.begin(), dp.end()));

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution<int> *s = new Solution<int>();
    s->input();
    s->solution();
    cout << s->get_answer() << endl;
    delete s;

    return 0;
}