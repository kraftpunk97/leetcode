/*
@lc app=leetcode id=2 lang=cpp
 *
[2] Add Two Numbers
 */
#include<bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = nullptr;
        ListNode* res_ptr;
        ListNode* l1_ptr = l1;
        ListNode* l2_ptr = l2;

        bool carry = false;

        while (l1_ptr!=nullptr || l2_ptr!=nullptr) {
            int l1_val = l1_ptr!=nullptr ? l1_ptr->val : 0;
            int l2_val = l2_ptr!=nullptr ? l2_ptr->val : 0;
            int digit_sum = l1_val + l2_val;
            if (carry) { digit_sum++; }
            if (digit_sum > 9) {
                carry = true;
                digit_sum = digit_sum - 10;
            } else { carry = false; }

            ListNode* temp = new ListNode(digit_sum);
            if (res == nullptr) { res = temp; }
            else { res_ptr->next = temp; }
            res_ptr = temp;

            l1_ptr = l1_ptr!=nullptr ? l1_ptr->next : nullptr; 
            l2_ptr = l2_ptr!=nullptr ? l2_ptr->next : nullptr;
        }

        if (carry) {
            ListNode* temp = new ListNode(1);
            if (res == nullptr) { res = temp; }
            else { res_ptr->next = temp; }
            res_ptr = temp;    
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution s;
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    ListNode* res = s.addTwoNumbers(l1, l2);
}