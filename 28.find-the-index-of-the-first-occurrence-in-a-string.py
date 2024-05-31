#
# @lc app=leetcode id=28 lang=python3
#
# [28] Find the Index of the First Occurrence in a String
#

# @lc code=start
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        lfs = Solution.generateLPS_(needle)
        hystck_ptr = 0
        needle_ptr = 0
        while hystck_ptr < len(haystack):
            if haystack[hystck_ptr] == needle[needle_ptr]:
                needle_ptr += 1
                hystck_ptr += 1
            else:
                if needle_ptr > 0:
                    needle_ptr = lfs[needle_ptr-1]
                else:
                    hystck_ptr += 1
            if (needle_ptr == len(needle)):
                    return hystck_ptr - len(needle)

        return -1

    def generateLPS_(needle: str) -> list:
        lfs_len = [0,]  # An array to store the lengths of the longest prefixes that are also
                        # the suffixes of the substrings of the needle up till that index,
                        # such that the prefix is not entire string (which explains the zero at
                        # the begining.)
        current_char_ptr = 1
        lfs_ptr = 0  # lfs_ptr always points towards the last character of the tentative LFS
                     # for a substring.
        while current_char_ptr < len(needle): 
            if needle[current_char_ptr] == needle[lfs_ptr]: # if the character after lfs_ptr matches our current char
                                                            # then that means that these two characters are also part
                                                            # for that substring.
                lfs_len.append(lfs_ptr+1)
                lfs_ptr += 1
            else:
                # If they do not match, then we check for the last lfs_ptr, and keep doing that
                # until we either get a match, or lfs_ptr, goes to the beginning of the needle,
                # in which case, just length of lfs would be zero, and we append that.
                while lfs_ptr >= 0 and needle[current_char_ptr] != needle[lfs_ptr]:
                    lfs_ptr -= 1
                if lfs_ptr == -1:  # If lfs_ptr couldn't find a single match
                    lfs_ptr = 0
                    lfs_len.append(0)
                else:  # the only other case if we are out of the while loop would mean that a
                       # match was found.
                    lfs_len.append(lfs_ptr+1)
                    lfs_ptr += 1
            current_char_ptr += 1
        return lfs_len
# @lc code=end

def main():
    sol = Solution()
    #print(sol.strStr("ababcaababcaabc", "ababcaabc"))
    print(Solution.generateLPS_("adcadde"))

if __name__ == '__main__':
    main()