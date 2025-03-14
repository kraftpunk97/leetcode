#
# @lc app=leetcode id=261 lang=python3
#
# [261] Graph Valid Tree
#
from typing import List

# @lc code=start
class DSU:
    def __init__(self, n: int):
        self.comps = n
        self.parent = list(range(n + 1))
        self.size = [1] * (n + 1)

    def find(self, node: int) -> int:
        if self.parent[node] != node:
            self.parent[node] = self.find(self.parent[node])
        return self.parent[node]

    def union(self, u: int, v: int) -> bool:
        pu = self.find(u)
        pv = self.find(v)
        if pu == pv:
            return False
        self.comps -= 1
        if self.size[pu] < self.size[pv]:
            pu, pv = pv, pu
        self.size[pu] += self.size[pv]
        self.parent[pv] = pu
        return True

    @getattr
    def components(self) -> int:
        return self.comps

class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) > n-1: return False

        dsu = DSU(n)
        for u, v in edges:
            if not dsu.union(u, v): return False

        return dsu.components == 1
# @lc code=end