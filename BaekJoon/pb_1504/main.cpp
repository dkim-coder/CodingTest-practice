#include <iostream>
#include <cstring>
#define INF 123456789

using namespace std;

int N, E;
int v1, v2;
int a, b, c;
int graph[801][801];

int solve()
{
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(graph[i][k] != INF && graph[k][j] != INF)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int res = 0;
    res = min(graph[1][v1] + graph[v1][v2] + graph[v2][N], graph[1][v2] + graph[v2][v1] + graph[v1][N]);

    if(res > INF)
        return -1;
    return res;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int res = 0;

    cin >> N >> E;
    memset(&graph[0][0], INF, sizeof(graph));
    for(int i = 1; i <= N; i++)
        graph[i][i] = 0;
    for(int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    cin >> v1 >> v2;
    cout << solve() << endl;

    return EXIT_SUCCESS;
}