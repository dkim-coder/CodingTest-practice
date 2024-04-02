#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
킹의 위치, 돌의 위치, 움직이는 횟수 N
*/

pair<int, int> Movement(string str)
{
    pair<int, int> res = {0, 0};

    for (char c : str)
    {
        switch (c)
        {
        case 'R':
            res.second = 1;
            break;
        case 'L':
            res.second = -1;
            break;
        case 'B':
            res.first = 1;
            break;
        case 'T':
            res.first = -1;
            break;
        }
    }

    return res;
}

#define S 8

int main()
{
    string king;
    string stone;
    int n;
    vector<string> move;

    cin >> king >> stone >> n;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        move.push_back(tmp);
    }
    // 입력 끝
    pair<int, int> king_loc; // x, y
    pair<int, int> stone_loc;
    king_loc.first = abs(king[1] - '0' - S);
    king_loc.second = king[0] - 'A';
    stone_loc.first = abs(stone[1] - '0' - S);
    stone_loc.second = stone[0] - 'A';

    for (int i = 0; i < n; i++)
    {
        pair<int, int> m = Movement(move[i]);
        if (king_loc.first + m.first < 0 || king_loc.first + m.first >= S || king_loc.second + m.second < 0 || king_loc.second + m.second >= S)
            continue;
        king_loc.first += m.first;
        king_loc.second += m.second;
        if (king_loc.first == stone_loc.first && king_loc.second == stone_loc.second)
        {
            if (stone_loc.first + m.first < 0 || stone_loc.first + m.first >= S || stone_loc.second + m.second < 0 || stone_loc.second + m.second >= S)
            {
                king_loc.first -= m.first;
                king_loc.second -= m.second;
                continue;
            }
            stone_loc.first += m.first;
            stone_loc.second += m.second;
        }
    }

    cout << char(king_loc.second + 'A') << abs(king_loc.first - 8) << endl;
    cout << char(stone_loc.second + 'A') << abs(stone_loc.first - 8) << endl;

    // cout << king_loc.first << " " << king_loc.second << endl;
    // cout << stone_loc.first << " " << stone_loc.second << endl;

    return EXIT_SUCCESS;
}