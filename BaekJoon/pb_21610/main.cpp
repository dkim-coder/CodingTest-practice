#include <cstdio>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;

// check this mecro
#define CAL_IDX(num, n) ((num) % n) >= 0 ? ((num) % n) : (n + (num) % n)

short A[50][50];
short A_tmp[50][50];    // for calculating rainy increase
short N, M;
vector<pair<short, short>> moving;
// first index is dummy
short dx[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};    
short dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

int solution()
{
    int answer;
    vector<pair<short, short>> cloud;

    // initialize first cloud
    cloud.push_back(make_pair(N - 1, 0));
    cloud.push_back(make_pair(N - 1, 1));
    cloud.push_back(make_pair(N - 2, 0));
    cloud.push_back(make_pair(N - 2, 1));

    for(size_t i = 0; i < moving.size(); i++)
    {
        // calculate moving cloud
        for(size_t j = 0; j < cloud.size(); j++)
        {
            cloud[j].first = CAL_IDX(cloud[j].first + dx[moving[i].first] * moving[i].second, N);
            cloud[j].second = CAL_IDX((cloud[j].second + dy[moving[i].first] * moving[i].second), N);
        }

        // rainy time
        for(size_t j = 0; j < cloud.size(); j++)
            A[cloud[j].first][cloud[j].second] += 1;

        // calculate rainy increase
        memset(A_tmp, 0 ,sizeof(A_tmp));
        for(size_t j = 0; j < cloud.size(); j++)
        {
            short nx, ny;
            for(int k = 1; k <= 4; k++)
            {
                nx = cloud[j].first + dx[2 * k];
                ny = cloud[j].second + dy[2 * k];
                if(nx < 0 || nx >= N || ny < 0 || ny >= N)
                    continue;

                if(A[nx][ny] > 0)
                    A_tmp[cloud[j].first][cloud[j].second]++;
            }
        }
        for(size_t j = 0; j < cloud.size(); j++)
            A[cloud[j].first][cloud[j].second] += A_tmp[cloud[j].first][cloud[j].second];            

        // calculate next cloud
        vector<vector<bool>> check(N, vector<bool>(N, true));
        for(size_t j = 0; j < cloud.size(); j++)
            check[cloud[j].first][cloud[j].second] = false;
        
        cloud.clear();
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
            {
                if(check[j][k] && A[j][k] >=2)
                {
                    cloud.push_back(make_pair(j, k));
                    A[j][k] -= 2;
                }
            }
        }
    }

    // calculate answer
    answer = 0;
    for(short i = 0; i < N; i++)
        for(short j = 0; j < N; j++)
            answer += A[i][j];

    return answer;
}

int main()
{
    scanf("%hd %hd", &N, &M);
    for(short i = 0; i < N; i++)
        for(short j = 0; j < N; j++)
            scanf("%hd", &A[i][j]);

    for(short i = 0; i < M; i++)
    {
        pair<short, short> tmp;
        scanf("%hd %hd", &tmp.first, &tmp.second);
        moving.push_back(tmp);
    }
    
    printf("%d\n", solution());

    return EXIT_SUCCESS;
}