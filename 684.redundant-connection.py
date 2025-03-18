#
# @lc app=leetcode id=684 lang=python3
#
# [684] Redundant Connection
#
from typing import List

# @lc code=start
class DSU:
    def __init__(self, n: int):
        self.n = n
        self.parents = [i for i in range(n+1)]
        self.rank = [1] * (n+1)
    
    def find(self, node: int) -> int:
        parent = self.parents[node]
        while parent != self.parents[parent]:
            self.parents[parent] = self.parents[self.parents[parent]]
            parent = self.parents[parent]
        return self.parents[parent]

    def union(self, u: int, v: int) -> bool:
        pu = self.find(u)
        pv = self.find(v)
        if pu == pv: return True
        
        pu, pv = (pu, pv) if self.rank[pu] > self.rank[pv] else (pv, pu)
        self.parents[pv] = pu
        self.rank[pu] += self.rank[pv]
        return False
        
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        dsu = DSU(n)
        for v1, v2 in edges:
            if dsu.union(v1, v2):
                return (v1, v2)

# @lc code=end

