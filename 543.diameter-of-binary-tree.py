#
# @lc app=leetcode id=543 lang=python3
#
# [543] Diameter of Binary Tree
#

from typing import Optional

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
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        minn = 0
        maxx = 0

        def traverse(node: TreeNode, col: int):
            nonlocal minn, maxx
            if node is None:
                return
            minn = min(col, minn)
            maxx = max(col, maxx)
            traverse(node.left, col-1)
            traverse(node.right, col+1)
        
        traverse(root, 0)
        return maxx - minn + 1
# @lc code=end

