#
# @lc app=leetcode id=314 lang=python3
#
# [314] Binary Tree Vertical Order Traversal
#
from typing import List, Optional, Tuple, Deque
from collections import defaultdict, deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        memo = defaultdict(list)
        
        q: Deque[Tuple[TreeNode, int]] = deque()
        q.append((root, 0))
        while q:
            n = len(q)
            for i in range(n):
                node, col = q.popleft()
                if node is None:
                    continue
                memo[col].append(node.val)
                q.append((node.left, col-1))
                q.append((node.right, col+1))

        res = [memo[col] for col in sorted(memo.keys())]
        return res
# @lc code=end