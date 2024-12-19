/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        //return monotonicStack(arr);
        return prefixSum(arr);
    }

    int prefixSum(vector<int>& arr) {
        int n = arr.size();
        int num_chunks = 0;
        int prefix_sum = 0;
        int running_sum = 0;

        for (int i=0; i<n; i++) {
            prefix_sum += i;
            running_sum += arr[i];
            if (prefix_sum == running_sum) { num_chunks++; }
        }

        return num_chunks;

    }

    int monotonicStack(vector<int>& arr) {
        stack<int> st;
        for (int num: arr) {
            if (st.empty()) { st.push(num); }
            else {
                if (st.top() < num) { 
                    st.push(num); }
                else {
                    int last_max = st.top();
                    while (!st.empty() && num<st.top()) {  
                        st.pop();
                    }
                    st.push(last_max);
                }
            }
        }
        return st.size();
    }

};
// @lc code=end

int main() {
    vector<int> arr{1,2,0,3,4};
    Solution s;
    cout << s.maxChunksToSorted(arr) << '\n';
    return 0;
}