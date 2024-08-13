#include <cstdio>
#include <vector>

using namespace std;

#define ABS(a, b) (a - b < 0) ? (b - a) : (a - b)

char road[100][100];
char N;
char L;

int solution();

int main()
{
    scanf("%hhd %hhd", &N, &L);

    for (char i = 0; i < N; i++)
    {
        for (char j = 0; j < N; j++)
            scanf("%hhd", &road[i][j]);
    }

    printf("%d\n", solution());

    return 0;
}

int solution()
{
    int res = 0;

    for (char i = 0; i < N; i++)
    {
        vector<bool> ch(N, false);
        char cnt = 1;
        bool check = true;
        for(char j = 1; j < N; j++)
        {
            if(road[i][j - 1] == road[i][j])
                cnt++;
            else if(road[i][j] - road[i][j -1] == 1)
            {
                if(cnt >= L)
                {
                    for(char k = j - 1; k > j - 1 - L; k--){
                        if(!ch[k])
                            ch[k] = true;
                        else{
                            check = false;
                            break;
                        }
                    }
                    cnt = 1;
                }else{
                    check = false;
                    break;
                }
            }else if(road[i][j - 1] - road[i][j] == 1)
            {
                for(char k = j; k < j + L; k++)
                {
                    if(road[i][j] != road[i][k])
                    {
                        check = false;
                        break;
                    }
                    
                    if(!ch[k])
                        ch[k] = true;
                    else
                    {
                        check = false;
                        break;
                    }
                }
                cnt = 1;
            }
            else{
                check = false;
                break;
            }
        }

        if(check)
            res++;
    }

    for (char i = 0; i < N; i++)
    {
        vector<bool> ch(N, false);
        char cnt = 1;
        bool check = true;
        for(char j = 1; j < N; j++)
        {
            if(road[j - 1][i] == road[j][i])
                cnt++;
            else if(road[j][i] - road[j - 1][i] == 1)
            {
                if(cnt >= L)
                {
                    for(char k = j - 1; k > j - 1 - L; k--){
                        if(!ch[k])
                            ch[k] = true;
                        else{
                            check = false;
                            break;
                        }
                    }
                    cnt = 1;
                }else{
                    check = false;
                    break;
                }
            }else if(road[j - 1][i] - road[j][i] == 1)
            {
                for(char k = j; k < j + L; k++)
                {
                    if(road[j][i] != road[k][i])
                    {
                        check = false;
                        break;
                    }
                    
                    if(!ch[k])
                        ch[k] = true;
                    else
                    {
                        check = false;
                        break;
                    }
                }
                cnt = 1;
            }
            else{
                check = false;
                break;
            }
        }

        if(check)
            res++;
    }

    return res;
}