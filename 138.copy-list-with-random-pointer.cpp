/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

#include<bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node* res = new Node(head->val);
        Node* ptr = head->next;
        Node* res_ptr = res;
        unordered_map<Node*, Node*> hm;
        hm[nullptr] = nullptr;
        hm[head] = res_ptr;

        while (ptr != nullptr) {
            res_ptr->next = new Node(ptr->val);
            hm[ptr] = res_ptr->next;
            res_ptr = res_ptr->next;
            ptr = ptr->next;
        }

        ptr = head;
        res_ptr = res;

        while (ptr != nullptr) {
            res_ptr->random = hm[ptr->random];
            res_ptr = res_ptr->next;
            ptr = ptr->next;
        }
        return res;
    }
};
// @lc code=end

