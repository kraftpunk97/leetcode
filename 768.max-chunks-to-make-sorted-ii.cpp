/*
 * @lc app=leetcode id=768 lang=cpp
 *
 * [768] Max Chunks To Make Sorted II
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = 0;
        stack<int> st;
        for (int num: arr) {
            if (st.empty()) { st.push(num); }
            else {
                if (st.top() < num) { st.push(num); }
                else {
                    int largest_max = st.top();
                    while (!st.empty() && st.top()>num) {
                        st.pop();
                    }
                    st.push(largest_max);
                }
            }
        }
        return st.size();        
    }
};
// @lc code=end

