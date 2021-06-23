#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

/**
 * 1. List are not empty... so there is at least one node
 * 2. Each of them is none-negative integer
 * 3. Each node contain only one digit.
 * 4. They are stored in reversed order.
 *
 * So we need to handle carry
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *r = nullptr, *n = nullptr;
        int carry = 0;

        do {
            auto* p =
                new ListNode((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry);
            if (!r) {
                r = p;
                n = p;
            } else {
                n->next = p;
                n = p;
            }
            carry = 0;

            // since each node contains only one digit
            if (p->val >= 10) {
                p->val -= 10;
                carry = 1;
            }

            // move to next digit
            if (l1) {
                l1 = l1->next;
            }

            if (l2) {
                l2 = l2->next;
            }

        } while (l1 || l2 || carry);

        return r;
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