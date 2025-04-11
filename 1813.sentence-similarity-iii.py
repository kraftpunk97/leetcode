#
# @lc app=leetcode id=1813 lang=python3
#
# [1813] Sentence Similarity III
#

# @lc code=start
class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:       
        if sentence1 == sentence2: return True
        s1 = sentence1.split()
        s2 = sentence2.split()
        if len(s1) == len(s2):
            return False
        s1, s2 = (s1, s2) if len(s1) < len(s2) else (s2, s1)
        s2L = s1L = 0
        s2R = len(s2) - 1
        s1R = len(s1) - 1
        leftMismatch = False
        rightMismatch = False
        while s1L <= s1R and s2L < s2R:
            # print(s1L, s1R, s2L, s2R)
            if not leftMismatch:
                if s1[s1L] == s2[s2L]:
                    s1L += 1
                    s2L += 1
                else:
                    leftMismatch = True
            if not rightMismatch:
                if s1[s1R] == s2[s2R]:
                    s1R -= 1
                    s2R -= 1
                else:
                    rightMismatch = True
            if leftMismatch and rightMismatch:
                # print("break", s1L, s1R)
                break
        return s1L > s1R       
# @lc code=end

def main():
    s = Solution()
    s1 = "Eating"
    s2 = "Eating rihgt now"
    print(s.areSentencesSimilar(s1, s2))

if __name__ == '__main__':
    main()