/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */
//Definition for singly-linked list.
#include <bits/stdc++.h>

using namespace std;

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ahead = head;

        int i = 0;
        while (i<n+1 && ahead!=nullptr) {
            ahead = ahead->next;
            i++;
        }

        if (ahead==nullptr && i<n+1) { head = head->next; } // Remove the first element
        else {
            ListNode* behind = head;
            while (ahead != nullptr) {
                ahead = ahead->next;
                behind = behind->next;
            }
            behind->next = behind->next->next;
        }
        return head;
    }
};
// @lc code=end

