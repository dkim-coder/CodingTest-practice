#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define CONVERT(str) (stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2)))

/*
    string.substr(시작 인덱스, 자를 길이)
    stoi(string)
    to_string(number)
    string.insert(시작 인덱스, 넣을 문자)
*/

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int min, second, cur_time, op_start_time, op_end_time, video_len_time;

    cur_time = CONVERT(pos);
    op_start_time = CONVERT(op_start);
    op_end_time = CONVERT(op_end);
    video_len_time = CONVERT(video_len);
    if(cur_time >= op_start_time && cur_time <= op_end_time)
        cur_time = op_end_time;
    for(auto com : commands)
    {
        if(com == "next")
            cur_time += 10;
        else  // "prev"
            cur_time -= 10;

        if(cur_time < 0)
            cur_time = 0;
        else if (cur_time > video_len_time)
            cur_time = video_len_time;

        if(cur_time >= op_start_time && cur_time <= op_end_time)
            cur_time = op_end_time;
    }

    answer += to_string(cur_time / 60);
    if(answer.length() == 1)
        answer.insert(0, "0");
    answer += ":";
    answer += to_string(cur_time % 60);
    if(answer.length() == 4)
        answer.insert(3, "0");

    return answer;
}

int main()
{
    string video_len = "10:00";
    string pos = "00:03";
    string op_start = "00:00";
    string op_end = "00:05";
    vector<string> commands = {"prev", "next"};

    cout << solution(video_len, pos, op_start, op_end, commands) << endl;

    return EXIT_SUCCESS;
}