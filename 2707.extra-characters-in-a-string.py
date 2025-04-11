#
# @lc app=leetcode id=2707 lang=python3
#
# [2707] Extra Characters in a String
#
from typing import List

# @lc code=start
class TrieNode:
    def __init__(self):
        self.nodes: List[TrieNode | None] = [None] * 26
        self.eow: bool = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str):  # Complexity = O(n) 
        curr = self.root
        for c in word:
            idx = ord(c) - ord('a')
            if curr.nodes[idx] is None:
                curr.nodes[idx] = TrieNode()
            curr = curr.nodes[idx]
        curr.eow = True

    def search(self, word: str) -> int: # O(n)
        curr = self.root
        dist = 0
        for c in word:
            idx = ord(c) - ord('a')
            if curr.nodes[idx] is None:
                break
            curr = curr.nodes[idx]
            dist += 1
        return dist if curr.eow else 0

class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        trie  = Trie()
        for word in dictionary: # O(mn)
            trie.insert(word)
        i = 0
        missing = 0
        while i < len(s): # O(s)
            dist = trie.search(s[i:])
            if dist == 0:
                missing += 1
                i += 1
            i += dist
        return missing
# @lc code=end
def main():
    s = Solution()
    res = s.minExtraChar(s = "dwmodizxvvbosxxw", dictionary = ["ox","lb","diz","gu","v","ksv","o","nuq","r","txhe","e","wmo","cehy","tskz","ds","kzbu"])
    print(res)

if __name__ == '__main__':
    main()
