/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string st = "";
        dfs(n, n, st, result);
        return result;
    }

    void dfs(int num_open, int num_closed, string& st, vector<string>& result) {
        if (num_open==num_closed && num_open==0) {
            result.push_back(st);
            return;
        }
        
        /*
        When can you open?
        1. num_open != 0
        */
        if (num_open != 0) {
            st.push_back('(');
            dfs(num_open-1, num_closed, st, result);
            st.pop_back();
        }

        /*
        When can you close?
        1. num_closed > num_open
        */
        if (num_closed > num_open) {
            st.push_back(')');
            dfs(num_open, num_closed-1, st, result);
            st.pop_back();
        }
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<string> result = sol.generateParenthesis(3);
    for (auto str: result) {
        cout << str << '\n';
    }
    return 0;
}