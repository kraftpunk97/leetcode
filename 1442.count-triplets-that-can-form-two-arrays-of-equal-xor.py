#
# @lc app=leetcode id=1442 lang=python3
#
# [1442] Count Triplets That Can Form Two Arrays of Equal XOR
#
from typing import List
from collections import Counter

# @lc code=start
class SegmentTree:
    def __init__(self, A: List):
        self.n = len(A)
        while (self.n & (self.n - 1)) != 0:
            self.n += 1
        self.tree = [0] * (2 * self.n)
        self.build(0, 0, self.n-1, A)
    
    def build(self, node: int, start: int, end: int, A: List):
        if start == end:
            if start < len(A):
                self.tree[node] = A[start]
        else:
            mid = (start + end) // 2
            left  = 2*node + 1
            right = 2*node + 2 
            self.build(left, start, mid, A)
            self.build(right, mid+1, end, A)
            self.tree[node] = self.tree[left] ^ self.tree[right] # Change this operation

    def update(self, i: int, val):
        def _update(node, start, end):
            if start == node:
                self.tree[node] = val
            else:
                mid = (start + end) // 2
                left = 2*node + 1
                right = 2*node + 2
                if i <= mid:
                    _update(left, start, mid)
                else:
                    _update(right, mid+1, end)
                self.tree[node] = self.tree[left] ^ self.tree[right]  # Change this operation
        _update(0, 0, self.n-1)
        
    def query(self, l: int, r: int):
        def _query(node: int, start: int, end: int):
            if r < start or l > end:
                return 0  # Change this value
            if l <= start and end <= r:
                return self.tree[node]
            mid = (start + end) // 2
            left = 2 * node + 1
            right = 2 * node + 2
            left_tree = _query(left, start, mid)
            right_tree = _query(right, mid+1, end)
            return left_tree ^ right_tree # Change this operation
        return _query(0, 0, self.n-1)
    
class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        prefixXOR = [0] + arr[:]
        n = len(prefixXOR)
        for i in range(1, n):
            prefixXOR[i] ^= prefixXOR[i-1]
        res = 0
        for i in range(0, n):
            for k in range(i+1, n):
                if prefixXOR[i] == prefixXOR[k]:
                    res += k - i - 1
        return res
    
    def segmentTree(self, arr: List[int]) -> int:
        n = len(arr)
        st = SegmentTree(arr)
        res = 0
        for j in range(1, n):
            left = [st.query(i, j-1) for i in range(0, j)]
            right = [st.query(j, k) for k in range(j, n)]
            left_c = Counter(left)
            right_c = Counter(right)
            left_c, right_c = (left_c, right_c) if len(left_c) < len(right_c) else (right_c, left_c)
            for num in left_c.keys():
                res += left_c[num] * right_c[num]
        return res
# @lc code=end

def main():
    s = Solution()
    arr = [1,1,1,1,1]
    print(s.countTriplets(arr))

if __name__ == '__main__':
    main()