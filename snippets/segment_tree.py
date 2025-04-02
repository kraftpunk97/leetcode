from typing import List, Any

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
            self.tree[node] = self.tree[left] + self.tree[right] # Change this operation

    def update(self, i: int, val: Any):
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
                self.tree[node] = self.tree[left] + self.tree[right]  # Change this operation
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
            return left_tree + right_tree # Change this operation
        return _query(0, 0, self.n-1)
