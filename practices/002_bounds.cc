#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#include <gtest/gtest.h>

TEST(t_002_bounds, 1)
{
    //                   0  1  2  3  4  5
    vector<int> nums = {-1, 0, 0, 0, 0, 1};

    auto offset = [&nums](vector<int>::iterator it) {
        return distance(nums.begin(), it);
    };

    ASSERT_EQ(offset(upper_bound(nums.begin(), nums.end(), 0)), 5);
    ASSERT_EQ(offset(lower_bound(nums.begin(), nums.end(), 0)), 1);  // lower bound is inclusive
}

TEST(t_002_bounds, 2)
{
    //                     0  1  2  3  4  5
    vector<int> nums   = {-1, 0, 0, 0, 0, 2};
    auto        offset = [&nums](vector<int>::iterator it) {
        return distance(nums.begin(), it);
    };

    auto it    = lower_bound(nums.begin(), nums.end(), 4);
    auto lower = offset(it);

    ASSERT_EQ(lower, 1);
}
