/*
 * @lc app=leetcode id=2407 lang=cpp
 *
 * [2407] Longest Increasing Subsequence II
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
struct SegmentTree {
    vector<int> st;  // max_length
    int n;

    SegmentTree(int min, int max) {
        this->n = max - min + 1;
        this->st = vector<int>(4*n, 0);
    }

    int query(int query_l, int query_r) { return query(query_l, query_r, 0, n-1, 1); }
    int query(int query_l, int query_r, int L, int R, int idx) {
        if (query_l > query_r) { return INT_MIN; } // Set this 
        if (L==query_l && R==query_r) { return st[idx]; }
        int mid = (L + R) / 2;
        int left_val = query(query_l, min(query_r, mid), L, mid, 2*idx);
        int right_val = query(max(query_l, mid+1), query_r, mid+1, R, 2*idx+1);
        return max(left_val, right_val); // Change this operation
    }

    void update(int index, int val) { update(index, val, 0, n-1, 1); }
    void update(int index, int val, int L, int R, int idx) {
        if (L==index && R==index) {  st[idx] = val; }
        else {
            int mid = (L + R) / 2;  
            if (index <= mid) { update(index, val, L, mid, 2*idx); }
            else { update(index, val, mid+1, R, 2*idx+1); }
            st[idx] = max(st[2*idx], st[2*idx+1]); // Change this operation
        }
    }
    inline int size() { return n; }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        return DP(nums, k);
    }

    int DP(vector<int>& nums, int k) {
        int n = nums.size();
        auto max_elem = *(max_element(nums.begin(), nums.end()));
        SegmentTree st(0, max_elem);
        int max_len = 0;
        for (int num: nums) {

            int length = st.query(max(0, num-k), num-1) + 1;
            st.update(num, length);
            
            /*
            for (int j=0; j<i; j++) { // TODO: Optimise this from O(n) to O(log n)
            // What does this for loop do?
            // It parses nums[0...i-1],
            // and if the difference between nums[i] and nums[j] fullfills 
            // a certain criteria, then it sets the value of dp[i] to dp[j]+1.
                int diff = nums[i] - nums[j];
                if (0<diff && diff<=k) {
                    dp[i] = max(dp[i], dp[j]+1);
                }

                int max_len = nums[i] - nums[j];

            }
            */
            max_len = max(max_len, length);
        }


        return max_len;
    }
};
// @lc code=end

int main() {
    //vector<int> nums{4, 2, 1, 4, 3, 4, 5, 8, 15};
    //int k = 6;
    vector<int> nums{1,100,500,100000,100000};
    int k = 100000;
    Solution s;
    cout << s.lengthOfLIS(nums, k) << '\n';
    return 0;
}