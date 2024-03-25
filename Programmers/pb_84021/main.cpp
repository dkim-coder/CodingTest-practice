#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

/*
1. DFS or BFS 를 이용해서 조각 모음들을 좌표로 저장 (사각형 형태로)
2. 사격형 형태의 가공물들을 90도 회전하는 함수
*/

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void showRect(vector<vector<int>> rect)
{
    for (int i = 0; i < rect.size(); i++)
    {
        for (int j = 0; j < rect[i].size(); j++)
        {
            cout << rect[i][j] << " ";
        }
        cout << "\n";
    }
}

// 회전시킨거 좌표 반환 해주는 함수
vector<vector<int>> rotate90(vector<vector<int>> rect)
{
    vector<vector<int>> res(rect[0].size(), vector(rect.size(), 0));

    for (int i = 0; i < rect.size(); i++)
    {
        for (int j = 0; j < rect[0].size(); j++)
            res[j][rect.size() - 1 - i] = rect[i][j];
    }

    return res;
}

// game_board 용으로 가능한걸 1
vector<vector<vector<int>>> returnGPS_1(vector<vector<int>> graph)
{
    vector<vector<vector<int>>> res;

    // 이거는 지금 game_board 쪽의 0 으로 비어있는 공간 확인하는것
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[0].size(); j++)
        {
            if (graph[i][j] == 0)
            {
                stack<pair<int, int>> st;
                vector<pair<int, int>> vec;
                st.push({i, j});
                graph[i][j] = 1;
                vec.push_back({i, j});
                while (!st.empty())
                {
                    int cx = st.top().first;
                    int cy = st.top().second;
                    st.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        if (nx < 0 || nx >= graph.size() || ny < 0 || ny >= graph[0].size())
                            continue;
                        if (graph[nx][ny] == 1)
                            continue;
                        st.push({nx, ny});
                        vec.push_back({nx, ny});
                        graph[nx][ny] = 1;
                    }
                }

                int min_x = 99999;
                int min_y = 99999;
                int max_x = 0;
                int max_y = 0;
                for (int k = 0; k < vec.size(); k++)
                {
                    if (vec[k].first < min_x)
                        min_x = vec[k].first;
                    if (vec[k].first > max_x)
                        max_x = vec[k].first;
                    if (vec[k].second < min_y)
                        min_y = vec[k].second;
                    if (vec[k].second > max_y)
                        max_y = vec[k].second;
                }
                vector<vector<int>> vec_element(max_x - min_x + 1, vector(max_y - min_y + 1, 0));
                for (int k = 0; k < vec.size(); k++)
                {
                    vec_element[vec[k].first - min_x][vec[k].second - min_y] = 1;
                }
                res.push_back(vec_element);
            }
        }
    }

    return res;
}

// table 용으로 가능한걸 1
vector<vector<vector<int>>> returnGPS_2(vector<vector<int>> graph)
{
    vector<vector<vector<int>>> res;

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[0].size(); j++)
        {
            if (graph[i][j] == 1)
            {
                stack<pair<int, int>> st;
                vector<pair<int, int>> vec;
                st.push({i, j});
                graph[i][j] = 0;
                vec.push_back({i, j});
                while (!st.empty())
                {
                    int cx = st.top().first;
                    int cy = st.top().second;
                    st.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        if (nx < 0 || nx >= graph.size() || ny < 0 || ny >= graph[0].size())
                            continue;
                        if (graph[nx][ny] == 0)
                            continue;
                        st.push({nx, ny});
                        vec.push_back({nx, ny});
                        graph[nx][ny] = 0;
                    }
                }

                int min_x = 99999;
                int min_y = 99999;
                int max_x = 0;
                int max_y = 0;
                for (int k = 0; k < vec.size(); k++)
                {
                    if (vec[k].first < min_x)
                        min_x = vec[k].first;
                    if (vec[k].first > max_x)
                        max_x = vec[k].first;
                    if (vec[k].second < min_y)
                        min_y = vec[k].second;
                    if (vec[k].second > max_y)
                        max_y = vec[k].second;
                }
                vector<vector<int>> vec_element(max_x - min_x + 1, vector(max_y - min_y + 1, 0));
                for (int k = 0; k < vec.size(); k++)
                {
                    vec_element[vec[k].first - min_x][vec[k].second - min_y] = 1;
                }
                res.push_back(vec_element);
            }
        }
    }

    return res;
}

int returnCnt(vector<vector<int>> map1, vector<vector<int>> map2)
{
    int cnt = 0;

    if (map1.size() != map2.size() || map1[0].size() != map2[0].size())
        return 0;
    else
    {
        for (int i = 0; i < map1.size(); i++)
        {
            for (int j = 0; j < map1[0].size(); j++)
            {
                if (map1[i][j] != map2[i][j])
                    return 0;
                if (map1[i][j] == 1 && map2[i][j] == 1)
                    cnt++;
            }
        }
    }

    return cnt;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    int answer = 0;

    vector<vector<vector<int>>> board_gps = returnGPS_1(game_board);
    vector<vector<vector<int>>> table_gps = returnGPS_2(table);
    vector<bool> check1(board_gps.size(), false);
    vector<bool> check2(table_gps.size(), false);

    for (int i = 0; i < table_gps.size(); i++)
    {
        vector<vector<int>> tmp = table_gps[i];
        if (!check2[i])
        {
            for (int j = 0; j < 4; j++)
            {
                tmp = rotate90(tmp);
                for (int k = 0; k < board_gps.size(); k++)
                {
                    if (check1[k])
                        continue;
                    int tmp_cnt;
                    tmp_cnt = returnCnt(board_gps[k], tmp);
                    if (tmp_cnt != 0)
                    {
                        answer += tmp_cnt;
                        check1[k] = true;
                        check2[i] = true;
                        break;
                    }
                }
                if(check2[i]) break;
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> game_board = {{1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 0, 1}, {1, 1, 0, 1, 1, 1}, {1, 0, 0, 0, 1, 0}, {0, 1, 1, 1, 0, 0}};
    vector<vector<int>> table = {{1, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 0}, {1, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 0, 0}};

    cout << "Answer : " << solution(game_board, table) << endl;

    return EXIT_SUCCESS;
}