#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    vector<int> st;
    int n;

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        this->st = vector<int>(4*n);
        buildST(arr, 0, n-1, 1);
    }

    void buildST(vector<int>& arr, int L, int R, int idx) {
        if (L == R) { st[idx] = arr[L]; }
        else {
            int mid = (L + R) / 2;
            buildST(arr, L, mid, 2*idx);
            buildST(arr, mid+1, R, 2*idx+1);
            st[idx] = st[2*idx] + st[2*idx+1]; // Change this operation       
        }
    }

    int queryST(int query_l, int query_r) { return queryST(query_l, query_r, 1, n-1, 1); }
    int queryST(int query_l, int query_r, int L, int R, int idx) {
        if (query_l > query_r) { return 0; } // Set this 
        if (L==query_l && R==query_r) { return st[idx]; }
        int mid = (L + R) / 2;
        int left_val = queryST(query_l, min(query_r, mid), L, mid, 2*idx);
        int right_val = queryST(max(query_l, mid+1), query_r, mid+1, R, 2*idx+1);
        return left_val + right_val; // Change this operation
    }

    void updateST(int index, int val) { updateST(index, val, 0, n-1, 1); }
    void updateST(int index, int val, int L, int R, int idx) {
        if (L == R) {  st[index] = val; }
        else {
            int mid = (L + R) / 2;  
            if (index < mid) { updateST(index, val, L, mid+1, 2*idx); }
            else { updateST(index, val, mid+1, R, 2*idx+1); }
            st[idx] = st[2*idx] + st[2*idx+1]; // Change this operation
        }
    }

    inline int size() { return n; }

};

int main() {
    vector<int> heights{5,3,7,4,4,2};
    SegmentTree st(heights);
    for (auto elem: st.st) {
        cout << elem << ' ';
    }
    cout << '\n';
    cout << st.queryST(2, 4) << '\n';
    return 0;
}