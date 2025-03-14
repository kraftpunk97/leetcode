#
# @lc app=leetcode id=133 lang=python3
#
# [133] Clone Graph
#

class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional, Dict, Set

class Solution:
    hm: Dict['Node', 'Node'] = {}

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None:
            return None
        if Solution.hm.get(node, None) is None:
            temp = Node(node.val)
            Solution.hm[node] = temp
            temp.neighbors = [self.cloneGraph(neighbor) for neighbor in node.neighbors]
        return Solution.hm[node]
# @lc code=end

