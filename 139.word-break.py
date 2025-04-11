#
# @lc app=leetcode id=139 lang=python3
#
# [139] Word Break
#
from typing import List

# @lc code=start
class TrieNode:
    def __init__(self):
        self.nodes = [None] * 26
        self.EOW = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str):
        curr = self.root
        for char in word:
            idx = ord(char) - ord('a')
            if curr.nodes[idx] is None:
                curr.nodes[idx] = TrieNode()
            curr = curr.nodes[idx]
        curr.EOW = True
    
    def search(self, word: str) -> int:
        curr = self.root
        dist = 0
        for char in word:
            idx = ord(char) - ord('a')
            if curr.nodes[idx] is None:
                break
            curr = curr.nodes[idx]
            dist += 1
        return dist if curr.EOW else 0

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        trie = Trie()
        for word in wordDict:
            trie.insert(word)
        i = 0
        while i < len(s):
            dist = trie.search(s[i:])
            if dist == 0:
                return False
            i += dist
        return True
             
# @lc code=end

