#include <limits>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
    const static int lookup[100];
public:

    int reverse(int x)
    {
        int sign = x < 0 ? -1 : 1;
        long long _x = static_cast<long long>(x);
        long long _y = 0;

        // let's first ignore the sign
        _x *= sign;

        do {

            // increase the order of existing round.
            auto d = lldiv(_x, 100);

            _x = d.quot;

            // need to consider digits flip
            if (_x) { // internal digit
                _y *= 100;
                if (d.rem < 10) {
                    _y += lookup[d.rem] * 10;
                } else {
                    _y += lookup[d.rem];
                }
            } else {  // last digit
                if (d.rem < 10) {  // last digit, and we have a signle digit remain
                    _y *= 10;
                    _y += lookup[d.rem];
                } else {
                    _y *= 100;
                    _y += lookup[d.rem];
                }
            }

            // need to consider the boundaries.
            if (_y >= numeric_limits<int>::max()) {
                _y = 0;
                break;
            }

        } while (_x);

        // put sign back...
        // weired leetcode's cpp could not handle that with INT_MAX
        _y = sign * _y;

        if (_y <= numeric_limits<int>::min()) {
            _y = 0;
        }

        return static_cast<int>(_y);
    }
};

const int Solution::lookup[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    1, 11, 21, 31, 41, 51, 61, 71, 81, 91,
    2, 12, 22, 32, 42, 52, 62, 72, 82, 92,
    3, 13, 23, 33, 43, 53, 63, 73, 83, 93,
    4, 14, 24, 34, 44, 54, 64, 74, 84, 94,
    5, 15, 25, 35, 45, 55, 65, 75, 85, 95,
    6, 16, 26, 36, 46, 56, 66, 76, 86, 96,
    7, 17, 27, 37, 47, 57, 67, 77, 87, 97,
    8, 18, 28, 38, 48, 58, 68, 78, 88, 98,
    9, 19, 29, 39, 49, 59, 69, 79, 89, 99,
};

int run()
{
    Solution s;
    std::vector<int> v = { 12345, 1534236469, -123, -12312981, 102, 901000, -2147483648 };
    for (auto a: v) {
        cout << "oringinal: " << a << " reverted: " << s.reverse(a) << endl;
    }

    return 0;
}
