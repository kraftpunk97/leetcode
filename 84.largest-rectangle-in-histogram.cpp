/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
struct SegementTree {
    vector<int> st;
    int n;

    SegementTree(vector<int>& arr) {
        this->n = arr.size();
        this->st = vector<int>(4*n, 0);
        build(arr, 0, n-1, 1);
    }

    void build(vector<int>& arr, int L, int R, int idx) {
        if (L > R) { return; }
        if (L == R) { st[idx] = arr[L]; }
        else {
            int mid = (L + R) / 2;
            build(arr, L, mid, 2*idx);
            build(arr, mid+1, R, 2*idx+1);
            st[idx] = min(st[2*idx], st[2*idx+1]);
        }
    }

    int query(int query_l, int query_r) { return query(query_l, query_r, 0, n-1, 1); }
    int query(int query_l, int query_r, int L, int R, int idx) {
        if (query_l > query_r) { return INT_MAX; }
        if (L==query_l && R==query_r) { return st[idx]; }
        int mid = (L + R) / 2;
        int left_val = query(query_l, min(query_r, mid), L, mid, 2*idx);
        int right_val = query(max(query_l, mid+1), query_r, mid+1, R, 2*idx+1);
        return min(left_val, right_val);
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //return segementTree(heights);
    }

    int segmentTree(vector<int>& heights) { // TLE
        int n = heights.size();
        SegementTree st(heights);
        int max_area = 0;
        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                int min_height = st.query(i, j);
                max_area = max(min_height*(j-i+1), max_area);
            }
        }
        return max_area;
    }

    int stackBased(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        
    }
};
// @lc code=end

