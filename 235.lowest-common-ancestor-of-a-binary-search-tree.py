#
# @lc app=leetcode id=235 lang=python3
#
# [235] Lowest Common Ancestor of a Binary Search Tree
#
from typing import List

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        stack: List['TreeNode'] = []
        ancestors: List[List['TreeNode']] = []
        self._traverseTree(root, p, q, 0, ancestors, stack)
        
        assert len(ancestors) == 2

        pAncestors, qAncestors = ancestors

        i = 0
        while i<min(len(pAncestors),len(qAncestors)) and pAncestors[i]==qAncestors[i]:
            i += 1
        return pAncestors[i-1]


    
    def _traverseTree(self, currNode: 'TreeNode', p: 'TreeNode', q: 'TreeNode', numFound: int, ancestors: List[List['TreeNode']], stack: List['TreeNode']):
        if numFound == 2: return
        if currNode is None: return

        stack.append(currNode)
        if currNode.val==p.val or currNode.val==q.val:
            numFound += 1
            ancestors.append(stack.copy())
        
        self._traverseTree(currNode.left, p, q, numFound, ancestors, stack)
        self._traverseTree(currNode.right, p, q, numFound, ancestors, stack)

        stack.pop()


        
# @lc code=end

