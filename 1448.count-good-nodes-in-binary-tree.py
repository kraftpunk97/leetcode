#
# @lc app=leetcode id=1448 lang=python3
#
# [1448] Count Good Nodes in Binary Tree
#
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
    def goodNodes(self, root: TreeNode) -> int:
        res = 0
        stack = [root.val]
        
        def dfs(node: TreeNode, res: int):
            if node is None: return res
            if node.val >= stack[-1]:
                res += 1
                stack.append(node.val)
                res = dfs(node.left, res)
                res = dfs(node.right, res)
                stack.pop()
                return res
            else:
                res = dfs(node.left, res)
                res = dfs(node.right, res)
                return res
        
        res = dfs(root, res)
        return res
# @lc code=end