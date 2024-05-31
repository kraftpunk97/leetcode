/*
 * @lc app=leetcode id=206 lang=c
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
     if(head==NULL) { // If the linked list is empty, just return a nullptr 
        return NULL;
    }
    if (head!=NULL && head->next==NULL) { // If the linked list has only one element, return that.
        return head;
    }

    struct ListNode* temp = NULL;
    struct ListNode* newHead;
    struct ListNode* ptr1 = head;
    struct ListNode* ptr2 = head->next; 

    temp = NULL;

    while(ptr2->next != NULL) {
         temp = ptr2->next;
         ptr2->next = ptr1;
         ptr1 = ptr2;
         ptr2 = temp;
    }
    head->next = NULL;
    newHead = ptr2;
    ptr2->next = ptr1;

    return newHead;
// @lc code=end

