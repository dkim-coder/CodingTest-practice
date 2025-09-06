#include <iostream>
#include <cstring>

using namespace std;

int R, C, M;
enum class direction{
    up = 1,
    down,
    right,
    left
};

struct shark
{
    bool isShark = false;
    int s;      // 속력
    direction d;      // 진행 방향
    int z;      // 크기

    shark() = default;
    shark(bool isShark, int s, direction d, int z) : isShark(isShark), s(s), d(d), z(z) {};
};

shark sharks[2][100][100];

pair<int, direction> moveVertical(int pos, int speed, direction dir, int maxPos) {
    int newPos = pos;
    direction newDir = dir;
    int remainSpeed = speed;
    
    while (remainSpeed > 0) {
        if (newDir == direction::up) {
            if (newPos >= remainSpeed) {
                newPos -= remainSpeed;
                remainSpeed = 0;
            } else {
                remainSpeed -= newPos;
                newPos = 0;
                newDir = direction::down;
            }
        } else { // down
            if (newPos + remainSpeed < maxPos) {
                newPos += remainSpeed;
                remainSpeed = 0;
            } else {
                remainSpeed -= (maxPos - 1 - newPos);
                newPos = maxPos - 1;
                newDir = direction::up;
            }
        }
    }
    
    return {newPos, newDir};
}

pair<int, direction> moveHorizontal(int pos, int speed, direction dir, int maxPos) {
    int newPos = pos;
    direction newDir = dir;
    int remainSpeed = speed;
    
    while (remainSpeed > 0) {
        if (newDir == direction::left) {
            if (newPos >= remainSpeed) {
                newPos -= remainSpeed;
                remainSpeed = 0;
            } else {
                remainSpeed -= newPos;
                newPos = 0;
                newDir = direction::right;
            }
        } else { // right
            if (newPos + remainSpeed < maxPos) {
                newPos += remainSpeed;
                remainSpeed = 0;
            } else {
                remainSpeed -= (maxPos - 1 - newPos);
                newPos = maxPos - 1;
                newDir = direction::left;
            }
        }
    }
    
    return {newPos, newDir};
}

int main(int argc, char *argv[])
{
    int res = 0;
    cin >> R >> C >> M;
    
    // 초기화
    memset(sharks, 0, sizeof(sharks));
    
    int r, c, s, d, z;
    for(int i = 0; i < M; ++i)
    {
        cin >> r >> c >> s >> d >> z;
        sharks[0][r - 1][c - 1] = shark(true, s, static_cast<direction>(d), z);
    }

    for(int pos = 0; pos < C; ++pos){
        int cur = pos % 2;
        int next = (pos + 1) % 2;
        
        // 다음 턴을 위해 초기화
        memset(sharks[next], 0, sizeof(sharks[next]));
        
        // 가까운 상어 잡기
        for(int r = 0; r < R; ++r)
        {
            if(sharks[cur][r][pos].isShark) {
                res += sharks[cur][r][pos].z;
                sharks[cur][r][pos].isShark = false;
                break;
            }
        }
        
        // 상어 이동
        for(int r = 0; r < R; ++r)
        {
            for(int c = 0; c < C; ++c)
            {
                if(sharks[cur][r][c].isShark)
                {
                    int nr = r, nc = c;
                    direction nd = sharks[cur][r][c].d;
                    
                    switch (sharks[cur][r][c].d)
                    {
                        case direction::up:
                        case direction::down:
                        {
                            auto result = moveVertical(r, sharks[cur][r][c].s, sharks[cur][r][c].d, R);
                            nr = result.first;
                            nd = result.second;
                            nc = c;
                            break;
                        }
                        case direction::right:
                        case direction::left:
                        {
                            auto result = moveHorizontal(c, sharks[cur][r][c].s, sharks[cur][r][c].d, C);
                            nc = result.first;
                            nd = result.second;
                            nr = r;
                            break;
                        }
                    }

                    // 상어 잡아먹기 - 기존 상어가 있다면 크기 비교
                    if(sharks[next][nr][nc].isShark) {
                        if(sharks[next][nr][nc].z < sharks[cur][r][c].z) {
                            sharks[next][nr][nc] = shark(true, sharks[cur][r][c].s, nd, sharks[cur][r][c].z);
                        }
                    } else {
                        sharks[next][nr][nc] = shark(true, sharks[cur][r][c].s, nd, sharks[cur][r][c].z);
                    }
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}