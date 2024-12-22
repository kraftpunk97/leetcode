/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //return bruteForce(temperatures);
        return stackBased(temperatures);
    }

    vector<int> bruteForce(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        for (int i=0; i<n; i++) {
            int j = i+1;
            while (j<n && temperatures[i]>=temperatures[j]) { j++; }
            result[i] = j<n ? j-i : 0;
        }
        return result;
    }

    vector<int> stackBased(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st;
        st.push(0);
        for (int i=1; i<n; i++) {
            if (temperatures[i]>temperatures[st.top()]) {
                while (!st.empty() && temperatures[i]>temperatures[st.top()]) {
                    int pop_idx = st.top();
                    result[pop_idx] = i - pop_idx;
                    st.pop();
                }
            }
            st.push(i);
        }
        return result;
    }
};
// @lc code=end
