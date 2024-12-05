/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class NumArray {
private:
    int n;
    vector<int> fenwick;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        fenwick = vector<int>(4*n, 0);
        build_util(nums, 1, 0, n-1);
    }

    void build_util(vector<int>& nums, int node, int L, int R) {
        if (L == R) {
            fenwick[node] = nums[L];
        } else {
            int mid = (L+R) / 2;
            build_util(nums, 2*node, L, mid);
            build_util(nums, 2*node+1, mid+1, R);
            
            fenwick[node] = fenwick[2*node] + fenwick[2*node+1];
        }
    }
    
    void update(int index, int val) {
        update_util(1, 0, n-1, index, val);
    }

    void update_util(int node, int L, int R, int index, int val) {
        if (L == R) {
            fenwick[node] = val;
        } else {
            int mid = (L+R) / 2;
            if (L<=index && index<=mid) { update_util(2*node, L, mid, index, val); } 
            else { update_util(2*node+1, mid+1, R, index, val); }

            fenwick[node] = fenwick[2*node] + fenwick[2*node+1];
        }
    }
    
    int sumRange(int left, int right) {
        return query_util(1, 0, n-1, left, right);
    }

    int query_util(int node, int L, int R, int left, int right) {
        if (left > right) { return 0; }
        
        if (L==left && R==right) { return fenwick[node]; }
        
        int mid = (L+R) / 2;
        return query_util(2*node, L, mid, left, min(right, mid)) 
                + query_util(2*node+1, mid+1, R, max(mid+1, left), right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

int main() {
    vector<int> nums({1, 3, 5});
    NumArray* obj = new NumArray(nums);
    obj->printFenwick();
    delete obj;
    return 0;
}