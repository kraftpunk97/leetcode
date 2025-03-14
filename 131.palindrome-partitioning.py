#
# @lc app=leetcode id=131 lang=python3
#
# [131] Palindrome Partitioning
#
from typing import List, Dict, Set, Tuple

# @lc code=start
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        hm: Dict[str: List[str]] = {}

        def isPalindrome(s: str) -> bool:
            for i in range(len(s)//2):
                if s[i] != s[len(s)-i-1]:
                    return False
            return True

        def allPartitions(s: str) -> List[List[str]]:
            if hm.get(s, None) is not None:
                return hm[s]
            if len(s) == 1:
                hm[s] = [[s]]
                return hm[s]
            temp: Set[Tuple[str]] = set()
            if isPalindrome(s):
                temp.add((s,))
            i = 0
            for i in range(1, len(s)):
                # Partition the string into s[0:i-1] and s[i:]
                leftPartitions = allPartitions(s[0:i])
                rightPartitions = allPartitions(s[i:])
                for l in leftPartitions:
                    for r in rightPartitions:
                        temp.add(tuple(l + r))
            temp = [[string for string in partition] for partition in temp]
            hm[s] = temp
            return hm[s]
        
        return allPartitions(s)
# @lc code=end

def main():
    s = Solution()
    print(s.partition("aab"))

if __name__ == '__main__':
    main()