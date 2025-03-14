#
# @lc app=leetcode id=112 lang=python3
#
# [112] Path Sum
#
from typing import List, Optional

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
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        sumFound: List = []
        self._traversalUtil(root, 0, targetSum, sumFound)
        return len(sumFound) > 0

    def _traversalUtil(self, currNode: TreeNode, currSum: int, targetSum: int, sumFound: List):
        if len(sumFound) > 0: return
        if currNode is None: return

        currSum += currNode.val
        if currNode.left is None and currNode.right is None:
            if currSum == targetSum:
                sumFound.append(None)
        
        self._traversalUtil(currNode.left, currSum, targetSum, sumFound)
        self._traversalUtil(currNode.right, currSum, targetSum, sumFound)

        
        
# @lc code=end

