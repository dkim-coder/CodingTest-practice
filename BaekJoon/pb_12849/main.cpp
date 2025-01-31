#include <iostream>

#define EXIT_SUCCESS 0

using namespace std;

template <typename T>
class Base
{
    private:
        long long mod;
    public:
        Base(long long mod);
        virtual ~Base();
        virtual void solution() = 0;
};

template <typename T>
Base<T>::Base(long long mod) : mod(mod) {}

template <typename T>
Base<T>::~Base() {}

template <typename T>
class Derived : public Base<T>
{
   private:

   public:
        Derived(long long mod);
        virtual ~Derived(); 
        virtual void solution() override;
};

template <typename T>
Derived<T>::Derived(long long mod) : Base<T>(mod) {}

template <typename T>
Derived<T>::~Derived() {}

template <typename T>
void Derived<T>::solution()
{
    return;    
}

int main()
{
    Base<int> *b = new Derived<int>(1000000007L);

    delete b;

    return EXIT_SUCCESS;
}