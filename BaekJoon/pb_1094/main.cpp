#include <iostream>

using namespace std;

int main()
{
    int origin = 64;
    int target;
    int cur;
    int cur_length;
    int res = 0;

    cin >> target;

    if (target == 64)
    {
        cout << 1 << endl;
        return EXIT_SUCCESS;
    }

    cur = origin;
    cur_length = 0;
    while (cur > 0)
    {
        cur = cur >> 1;
        if (cur_length + cur <= target)
        {
            cur_length += cur;
            res++;
            if (cur_length == target)
                break;
        }
    }

    cout << res << endl;

    return EXIT_SUCCESS;
}