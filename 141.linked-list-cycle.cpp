/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */
#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) { return false; }
        if (head->next == head) { return true; }
        if (head->next!=nullptr && head->next->next==head) { return true; }
        
        ListNode* fast_ptr = head;
        ListNode* slow_ptr = head;
        while (true) {
            if (slow_ptr==nullptr || fast_ptr==nullptr) { return false; }
            if (slow_ptr->next==nullptr || fast_ptr->next==nullptr) { return false; }
            if (fast_ptr->next->next == nullptr) { return false; }
            
            if (fast_ptr==slow_ptr && fast_ptr!=head) { return true; }

            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
    }
};
// @lc code=end

