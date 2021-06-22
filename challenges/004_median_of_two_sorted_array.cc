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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {}
};

////////////////////////////
// CUT END
////////////////////////////

int main()
{
    Solution    s;
    vector<int> num1 = {1, 3};
    vector<int> num2 = {2};

    cout << s.findMedianSortedArrays(num1, num2) << endl;
    return 0;
}
