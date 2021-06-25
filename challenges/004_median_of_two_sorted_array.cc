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
public:
    using iter_t  = vector<int>::iterator;
    using range_t = tuple<iter_t, iter_t, vector<int>>;

    struct tracker_t {
        iter_t       first;
        iter_t       last;
        vector<int>& nums;

        int front()
        {
            return *first;
        }

        int back()
        {
            return *last;
        }

        int count()
        {
            return std::distance(first, last);
        }

        iter_t medium()
        {
            return first + ((count() - 1) >> 1);
        }

        pair<int, int> offsets()
        {
            return pair(std::distance(nums.begin(), first), std::distance(nums.begin(), last));
        }

        int distance(iter_t i)
        {
            return std::distance(first, i);
        }
    };

    tracker_t make_tracker(vector<int>& nums)
    {
        return tracker_t{nums.begin(), nums.end(), nums};
    }

    double next_value(tracker_t* left, tracker_t* right)
    {
        auto left_begin  = next(left->first);
        auto left_end    = left->nums.end();
        auto right_begin = right->first;
        auto right_end   = right->nums.end();

        if (left_begin == left_end) {
            return (right_begin == right_end) ? 0.0 : *right_begin;
        }
        if (right_begin == right_end) {
            return *left_begin;
        }
        return min(*left_begin, *right_begin);
    }

    auto choose_starts(tracker_t& tracker1, tracker_t& tracker2)
    {
        if (tracker1.count() && !tracker2.count()) {
            return pair(&tracker1, &tracker2);
        } else if (!tracker1.count() && tracker2.count()) {
            return pair(&tracker2, &tracker1);
        }
        if (tracker1.front() < tracker2.front()) {
            return pair(&tracker1, &tracker2);
        }
        return pair(&tracker2, &tracker1);
    };

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        auto total = nums1.size() + nums2.size();
        assert(total > 0);

        // if the total amount is even, so the medium is an element
        auto is_elem = total % 2 == 1;

        // target position
        auto target = (total - 1) / 2;

        //  1. choose the vector with the smaller first element
        //  2. use the value find in 1, partition the other vector
        //  3. calculate the position of the medium (the number of elements smaller than it)
        //  4. choose the partitions according to the target position value.

        int     start       = 0;
        auto    tracker1    = make_tracker(nums1);
        auto    tracker2    = make_tracker(nums2);

        tracker_t* left  = nullptr;
        tracker_t* right = nullptr;

        while (target != start) {
            // find the one with smaller start
            tie(left, right) = choose_starts(tracker1, tracker2);

            // the idea is that, we take the medium of the vector with smallest start
            // then, partition the other vector. so the medium we just find will take
            // the index with start + sum of all elements smaller than the medium.

            // normal case: overlapping
            auto pivot1    = left->medium();
            int  pivot_idx = left->distance(pivot1) + start;
            // partition other vector
            auto pivot2 = lower_bound(right->first, right->last, *pivot1);
            if (pivot2 == right->last) {
                // case 1: all right range are less than pivot value
                pivot_idx += right->count();
            } else {
                // case 2: we have overlapping vectors
                pivot_idx += right->distance(pivot2);
            }

            // now we need to check the target and pivot
            if (target == pivot_idx) {
                left->first  = pivot1;
                right->first = pivot2;
                start        = pivot_idx;
            } else if (target > pivot_idx) {
                // take the greater half
                left->first  = ++pivot1;
                right->first = pivot2;
                start        = ++pivot_idx;
            } else {
                // take the smaller half
                left->last  = pivot1;
                right->last = pivot2;
                // start will not change;
            }
        }

        // now we have to calculate the medium value
        // the hard part is to find "next" value if required
        tie(left, right) = choose_starts(tracker1, tracker2);
        double ret       = *left->first;
        if (!is_elem) {
            // this is a merge source case
            // choosing the next value from both left and right
            ret += next_value(left, right);
            ret /= 2;
        }

        return ret;
    }
};

////////////////////////////
// CUT END
////////////////////////////

#include <gtest/gtest.h>
TEST(c_004_medium_of_two_sorted_array, 1)
{
    Solution    s;
    vector<int> nums1 = {2};
    vector<int> nums2 = {1, 3};

    ASSERT_EQ(s.findMedianSortedArrays(nums1, nums2), 2.0);
}

TEST(c_004_medium_of_two_sorted_array, 2)
{
    Solution    s;
    vector<int> nums1 = {-1, 0, 0, 0, 0, 0, 1};
    vector<int> nums2 = {0, 0, 0, 0, 0};

    ASSERT_EQ(s.findMedianSortedArrays(nums1, nums2), 0.0);
}

TEST(c_004_medium_of_two_sorted_array, 3)
{
    Solution    s;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    ASSERT_EQ(s.findMedianSortedArrays(nums1, nums2), 2.5);
}

TEST(c_004_medium_of_two_sorted_array, 4)
{
    Solution    s;
    vector<int> nums1 = {0, 0};
    vector<int> nums2 = {0, 0};

    ASSERT_EQ(s.findMedianSortedArrays(nums1, nums2), 0);
}

TEST(c_004_medium_of_two_sorted_array, 5)
{
    Solution    s;
    vector<int> nums1 = {};
    vector<int> nums2 = {1};

    ASSERT_EQ(s.findMedianSortedArrays(nums1, nums2), 1);
}

TEST(c_004_medium_of_two_sorted_array, 6)
{
    Solution    s;
    vector<int> nums1 = {1};
    vector<int> nums2 = {};

    ASSERT_EQ(s.findMedianSortedArrays(nums1, nums2), 1);
}

TEST(c_004_medium_of_two_sorted_array, 7)
{
    Solution    s;
    vector<int> nums1 = {};
    vector<int> nums2 = {1, 2, 3, 4};

    ASSERT_EQ(s.findMedianSortedArrays(nums1, nums2), 2.5);
}

TEST(c_004_medium_of_two_sorted_array, 8)
{
    Solution    s;
    vector<int> nums1 = {0, 0, 0, 0, 0};
    vector<int> nums2 = {-1, 0, 0, 0, 0, 0, 1};

    ASSERT_EQ(s.findMedianSortedArrays(nums1, nums2), 0);
}

TEST(c_004_medium_of_two_sorted_array, 9)
{
    Solution    s;
    vector<int> nums1 = {2};
    vector<int> nums2 = {1, 3, 4};

    ASSERT_EQ(s.findMedianSortedArrays(nums1, nums2), 2.5);
}

TEST(c_004_medium_of_two_sorted_array, 10)
{
    Solution    s;
    vector<int> nums1 = {2, 2, 4, 4};
    vector<int> nums2 = {2, 2, 4, 4};

    ASSERT_EQ(s.findMedianSortedArrays(nums1, nums2), 3);
}