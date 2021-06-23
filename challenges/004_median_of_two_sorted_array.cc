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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        auto total = nums1.size() + nums2.size();
        if (total == 0) {
            return 0.0;
        }

        // if the total amount is even, so the medium is an element
        auto has_medium_elem = total % 2 == 1;

        // target position
        auto target_position = (total - 1) / 2;

        // normal case: the two vectors are overlapping
        //  1. choose any vector, find the medium of it.
        //  2. use the value find in 1, partition the other vector
        //  3. calculate the position of the medium (the number of elements smaller than it)
        //  4. choose the partitions according to the target position value.
        pair<int, int> range(0, total - 1);
        using iter_t      = vector<int>::iterator;
        using vec_range_t = pair<iter_t, iter_t>;
        vec_range_t nums1_range(nums1.begin(), nums1.end());
        vec_range_t nums2_range(nums2.begin(), nums2.end());
        // medium_of_range get the medium of iterator of the range
        auto medium_of_range = [](vec_range_t& t) {
            auto half = distance(t.first, t.second) >> 1;
            return t.first + half;
        };
        auto medium_val_of_vec = [has_medium_elem, target_position, &range](vec_range_t& r) -> double {
            if (has_medium_elem) {
                return (double)(*(r.first + (target_position - range.first)));
            }
            l = (double)(*(r.first + (range.first - target_position)));
            r = (double)(*(r.first + (range.first - target_position)));
            return ((double)nums[target_position] + (double)nums[target_position]) / 2.0;
        };
        while (target_position > range.first && target_position < range.second) {
            // special case: either one is emtpy
            if (nums1_range.first == nums1_range.second) {
            } else if (nums2_range.first == nums2_range.second) {
            }

            auto num1_medium_it   = medium_of_range(nums1_range);
            auto [num2_l, num2_h] = equal_range(nums2_range.first, nums2_range.second, *num1_medium_it);
        }
    }
};

////////////////////////////
// CUT END
////////////////////////////

int run()
{
    Solution    s;
    vector<int> num1 = {0, 0, 0, 0, 0};
    vector<int> num2 = {-1, 0, 0, 0, 0, 0, 1};

    cout.precision(6);
    cout << fixed << s.findMedianSortedArrays(num1, num2) << endl;
    return 0;
}
