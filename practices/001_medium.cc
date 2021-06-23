#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedium(vector<int>& nums)
    {
        auto size = nums.size();
        if (size == 0) {
            return 0.0;
        }

        if (size % 2 == 1) {
            // medium within ...
            return (double)nums[(size - 1) / 2];
        }

        auto index = (size - 1) / 2;
        return ((double)nums[index] + (double)nums[index + 1]) / 2;
    }
};

// TESTS
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(t001, medium)
{
    Solution s;
    vector<int> v{1, 2, 3, 4, 5, 6};

    ASSERT_EQ(s.findMedium(v), 3.5);
}