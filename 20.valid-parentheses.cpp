/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        for (char parenthesis: s) {
            if (parenthesis=='(' || parenthesis=='[' || parenthesis=='{') {
                stck.push(parenthesis);
            } else {
                if (stck.empty()) {
                    return false;
                }
                if (parenthesis==')'&&stck.top()!= '(') {
                    return false;
                } else if (parenthesis==']'&&stck.top()!='[') {
                    return false;
                } else if (parenthesis=='}'&&stck.top()!='{') {
                    return false;
                } else {
                    stck.pop();
                }
            }
        }
        return stck.empty();
    }
};
// @lc code=end

