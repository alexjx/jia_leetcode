#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

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
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> rr;
        unordered_multimap<int, int> m;
        for (auto i = nums.begin(); i != nums.end(); i++) {
            m.insert(pair<int, int>(*i, i - nums.begin()));
        }

        for (auto i = nums.begin(); i != nums.end(); i++) {
            auto r = target - *i;
            auto x = m.equal_range(r);
            if (x.first != m.end()) {
                for (auto ii = x.first; ii != x.second; ii++) {
                    if (ii->second != i - nums.begin()) {
                        rr.push_back(i - nums.begin());
                        rr.push_back(ii->second);
                        return rr;
                    }
                }
            }
        }
        return rr;
    }
};

int main()
{
    Solution s;
    s.twoSum();
}
