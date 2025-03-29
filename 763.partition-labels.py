#
# @lc app=leetcode id=763 lang=python3
#
# [763] Partition Labels
#
from typing import List
from collections import Counter

# @lc code=start
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        res: List[int] = []
        right = Counter(s)
        left: set[chr] = set()
        partStart = 0
        for i in range(len(s)):
            char = s[i]
            right[char] -= 1
            if right[char] != 0:
                left.add(char)
            else:
                left.discard(char)
                if len(left) == 0:
                    res.append(i-partStart+1)
                    partStart = i+1
        return res

# @lc code=end

def main():
    s = Solution()
    res = s.partitionLabels("ababcbacadefegdehijhklij")
    print(len("ababcbacadefegdehijhklij"))
    print(res)
    print(sum(res))

if __name__ == '__main__':
    main()
