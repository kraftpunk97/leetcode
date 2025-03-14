#
# @lc app=leetcode id=211 lang=python3
#
# [211] Design Add and Search Words Data Structure
#

# @lc code=start
class TrieNode(object):
    def __init__(self):
        self.children = [None] * 26
        self.endOfWord = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()
     
    def addWord(self, word: str) -> None:
        curr = self.root
        for char in word:
            i = ord(char) - ord('a')
            if curr.children[i] is None:
                curr.children[i] = TrieNode()
            curr = curr.children[i]
        curr.endOfWord = True

    def search(self, word: str) -> bool:
        curr = self.root
        for char in word:
            i = ord(char) - ord('a')
            curr = curr.children[i]
            if curr is None:
                return False
        return curr.endOfWord    

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
# @lc code=end

