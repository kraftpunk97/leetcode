#
# @lc app=leetcode id=3306 lang=python3
#
# [3306] Count of Substrings Containing Every Vowel and K Consonants II
#

# @lc code=start
class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        
        n = len(word)
        vowels = "aeiou"

        # Find all the consonants
        consonantsIdx = [i for i in range(n-1, -1, -1) if word[i] not in vowels]
        consonantsIdx.append(-1)
        consonantsIdx.reverse()
        consonantsIdx.append(n)

        start = 1
        end = start + k - 1
        res  = 0

        while end < len(consonantsIdx)-1:
            # Find the backmost vowel
            i = consonantsIdx[start] - 1
            vowelSet = set()
            while i > consonantsIdx[start-1]:
                if word[i] in vowels:
                    vowelSet.add(i)
                    if len(vowelSet) == len(vowels):
                        break
                i -= 1
            leftSide = i - consonantsIdx[start-1] if i > consonantsIdx[start-1] else 0
            print(consonantsIdx[start-1], i, consonantsIdx[start], leftSide)
            
            # Find the front most vowel
            j = consonantsIdx[end] + 1
            vowelSet = set()
            while j < consonantsIdx[end+1]:
                if word[j] in vowels:
                    vowelSet.add(j)
                    if len(vowelSet) == len(vowels):
                        break
                j += 1
            rightSide = consonantsIdx[end+1] - j + 1 if j < consonantsIdx[end+1] else 0
            print(consonantsIdx[end], j, consonantsIdx[end+1], rightSide)
            print()

            res += leftSide * rightSide

            start += 1
            end += 1
        return res
# @lc code=end

def main():
    s = Solution()
    word = "ieaouqqieaouqq"
    k = 1
    print(s.countOfSubstrings(word, k))

if __name__ == '__main__':
    main()