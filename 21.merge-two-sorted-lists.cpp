/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

#include <bits/stdc++.h>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* res = nullptr;
        ListNode* res_ptr = nullptr;
        while (ptr1!=nullptr && ptr2!=nullptr) {
            ListNode* ins;
            if (ptr1->val < ptr2->val) {
                ins = ptr1;
                ptr1 = ptr1->next;
                ins->next = nullptr;
            } else {
                ins = ptr2;
                ptr2 = ptr2->next;
                ins->next = nullptr;
            }

            if (res == nullptr) { res = ins; res_ptr = ins; }
            else { res_ptr->next = ins; res_ptr = ins; }
        }

        if (ptr1 != nullptr) { 
            if (res == nullptr) { res = ptr1; }
            else { res_ptr->next = ptr1; }
        }
        if (ptr2 != nullptr) { 
            if (res == nullptr) { res = ptr2; }
            else { res_ptr->next = ptr2; }
        }
        
        return res;
    }
};
// @lc code=end

