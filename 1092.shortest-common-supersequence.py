#
# @lc app=leetcode id=1092 lang=python3
#
# [1092] Shortest Common Supersequence 
#

# @lc code=start
class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        str1, str2 = (str1, str2) if len(str1) < len(str2) else (str2, str1)
        
        maxPrefixSuffix = -1
        whosePrefix = 0
        for i in range(len(str1)):
            str1Suffix = str1[len(str1)-1-i:]
            str2Suffix = str2[len(str2)-1-i:]
            str1Prefix = str1[:i+1]
            str2Prefix = str2[:i+1]
            if str1Suffix == str2Prefix:
                maxPrefixSuffix = i
                whosePrefix = 2
            if str1Prefix == str2Suffix:
                maxPrefixSuffix = i
                whosePrefix = 1
        # print(maxPrefixSuffix, whosePrefix)
        
        if maxPrefixSuffix == -1:
            return str1+str2
        
        if whosePrefix == 1: 
            # 1's prefix is equal to 2's suffix
            # So take 2's prefix and add it to 1
            return str2[:len(str2)-maxPrefixSuffix-1] + str1
        else:
            return str1[:len(str1)-maxPrefixSuffix-1] + str2    

# @lc code=end

if __name__ == '__main__':
    s = Solution()
    print(s.shortestCommonSupersequence("aaaaaaaa", "aaaaaaaa"))