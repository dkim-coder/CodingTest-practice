#include <iostream>

#define EXIT_SUCCESS 0

namespace my
{
    using namespace std;
    
    template <typename T>
    class Solution
    {
        // 비정적 멤버 함수 포인터는 객체를 생성해야만 사용가능
        private:
            int N, K;
            T* W;
            T* V;
            T** dp;
        public:
            Solution();
            virtual ~Solution();
            virtual void input();
            virtual void solve();
            virtual T get_answer() const;
    };    

    template <typename T>
    Solution<T>::Solution(){
        this->W = new T[101];
        this->V = new T[101];
        this->dp = new T*[101];
        for(int i = 0; i < 101; i++)
            this->dp[i] = new T[100001];
    }

    template <typename T>
    Solution<T>::~Solution(){
        if(this->W != nullptr)
            delete[] this->W;
        if(this->V != nullptr)
            delete[] this->V;
        if(this->dp != nullptr)
            for(int i = 0 ; i < 101; i++)
                delete[] this->dp[i];
        delete[] this->dp;
    }

    template <typename T>
    void Solution<T>::input()
    {
        cin >> this->N >> this->K;
        for(int i = 1; i <= this->N; i++)
            cin >> this->W[i] >> this->V[i];
    }

    template <typename T>
    void Solution<T>::solve()
    {
        fill(this->dp[0], this->dp[0] + this->K + 1, 0);
        for(int i = 1 ; i <= this->N; i++)
        {
            for(int j = 1; j <= this->K; j++)
            {
                if(j < this->W[i])
                    this->dp[i][j] = this->dp[i-1][j];
                else
                    this->dp[i][j] = max(this->dp[i-1][j], this->dp[i-1][j-this->W[i]] + this->V[i]);
            }
        }

        return;
    }

    template <typename T>
    T Solution<T>::get_answer() const
    {
        return this->dp[this->N][this->K];
    }
}

using namespace my;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution<int> *s = new Solution<int>();
    s->input();
    s->solve();
    cout << s->get_answer() << endl;
    delete s;

    return EXIT_SUCCESS;
}