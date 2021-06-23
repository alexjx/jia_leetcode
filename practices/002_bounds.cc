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
    int upperBound(vector<int>& nums, int val)
    {
        auto it = upper_bound(nums.begin(), nums.end(), val);
        return distance(nums.begin(), it);
    }

    int lowerBound(vector<int>& nums, int val)
    {
        auto it = lower_bound(nums.begin(), nums.end(), val);
        return distance(nums.begin(), it);
    }
};

#include <gtest/gtest.h>

TEST(t002, bounds)
{
    Solution s;
    //                   0  1  2  3  4  5
    vector<int> nums = {-1, 0, 0, 0, 0, 1};

    ASSERT_EQ(s.upperBound(nums, 0), 5);
    ASSERT_EQ(s.lowerBound(nums, 0), 1);  // lower bound is inclusive
}
