#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

////////////////////////////
// CUT BEGIN
////////////////////////////

// how to get Leetcode tests to run approximately 10-40% faster, since they do a
// lot of print outs.
static auto x = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    cin.tie(NULL);
    return 0;
}();

class Solution {
    size_t max = 0;
    vector<char> t;

public:
    void checkRepeat(char a)
    {
        // check repeat
        for (auto it = t.begin(); it != t.end(); it++) {
            if (*it == a) {
                it = t.erase(t.begin(), it + 1);
                break;
            }
        }

        t.push_back(a);
        if (max < t.size()) {
            max = t.size();
        }
    }

    int lengthOfLongestSubstring(string s)
    {
        for (auto a : s) {
            checkRepeat(a);
        }

        return max;
    }
};

////////////////////////////
// CUT END
////////////////////////////

int run()
{
    Solution s;
    return 0;
}