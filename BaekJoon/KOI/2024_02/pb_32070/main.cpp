#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

using st = short;

#define EMPTY 0

st N;
st A[200000], B[200000];

void Input()
{
    scanf("%hd", N);

    for(short i = 0; i < N; i++)
        scanf("%hd %hd", &A[i], &B[i]);

    return;
}

int Solution()
{
    int answer = 0;

    return answer;
}

int main()
{
    Input();
    printf("%d\n", Solution());

    return EXIT_SUCCESS;
}