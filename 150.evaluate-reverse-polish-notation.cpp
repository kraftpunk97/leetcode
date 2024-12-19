/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stck;
        for (string token: tokens) {
            if (token.compare("+") == 0) {
                int arg1 = stck.top();
                stck.pop();
                int arg2 = stck.top();
                stck.pop();
                stck.push(arg1 + arg2);
            }
            else if (token.compare("-") == 0) {
                int arg1 = stck.top();
                stck.pop();
                int arg2 = stck.top();
                stck.pop();
                stck.push(arg2 - arg1);
            }
            else if (token.compare("*") == 0) {
                int arg1 = stck.top();
                stck.pop();
                int arg2 = stck.top();
                stck.pop();
                stck.push(arg1 * arg2);
            }
            else if (token.compare("/") == 0) {
                int arg1 = stck.top();
                stck.pop();
                int arg2 = stck.top();
                stck.pop();
                stck.push(arg2 / arg1);
            }
            else {
                stck.push(stoi(token));
            }
        }
        return stck.top();       
    }
};
// @lc code=end

