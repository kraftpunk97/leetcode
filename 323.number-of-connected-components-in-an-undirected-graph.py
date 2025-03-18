from typing import List

class DSU:
    def __init__(self, n: int):
        self.parents = [i for i in range(n)]
        self.comp = n

    def find(self, node: int) -> int:
        if self.parent[node] != node:
            self.parent[node] = self.find(self.parent[node])
        return self.parent[node]

    def union(self, u: int, v: int):
        pu = self.find(u)
        pv = self.find(v)
        

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        dsu = DSU(n)
        for edge in edges:
