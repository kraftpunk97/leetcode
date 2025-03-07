#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    vector<int> st;
    int n;

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        this->st = vector<int>(4*n);
        build(arr, 0, n-1, 1);
    }

    void build(vector<int>& arr, int L, int R, int idx) {
        if (L == R) { st[idx] = arr[L]; }
        else {
            int mid = (L + R) / 2;
            build(arr, L, mid, 2*idx);
            build(arr, mid+1, R, 2*idx+1);
            st[idx] = st[2*idx] + st[2*idx+1]; // Change this operation       
        }
    }

    int query(int query_l, int query_r) { return query(query_l, query_r, 0, n-1, 1); }
    int query(int query_l, int query_r, int L, int R, int idx) {
        if (query_l > query_r) { return 0; } // Set this 
        if (L==query_l && R==query_r) { return st[idx]; }
        int mid = (L + R) / 2;
        int left_val = query(query_l, min(query_r, mid), L, mid, 2*idx);
        int right_val = query(max(query_l, mid+1), query_r, mid+1, R, 2*idx+1);
        return left_val + right_val; // Change this operation
    }

    void update(int index, int val) { update(index, val, 0, n-1, 1); }
    void update(int index, int val, int L, int R, int idx) {
        if (L==index && R==index) {  st[idx] = val; }
        else {
            int mid = (L + R) / 2;  
            if (index <= mid) { update(index, val, L, mid, 2*idx); }
            else { update(index, val, mid+1, R, 2*idx+1); }
            st[idx] = st[2*idx] + st[2*idx+1]; // Change this operation
        }
    }

    inline int size() { return n; }
};

int main() {
    vector<int> heights{5,3,7,4,4,2};
    SegmentTree st(heights);
    st.update(0, 3);
    cout << st.query(0, 1) << '\n';
    return 0;
}