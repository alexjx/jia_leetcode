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

int main()
{
    Solution s;

    vector<int> nums = {1, 2, 3, 4};

    cout.precision(6);
    cout << fixed << s.findMedium(nums) << endl;

    return 0;
}
