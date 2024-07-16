/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */
#include <string>

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int vocabulary[30] = {0};
        for (char magazine_char: magazine) {
            vocabulary[magazine_char-'a']++;
        }
        for (char ransomNote_char: ransomNote) {
            vocabulary[ransomNote_char-'a']--;
            if (vocabulary[ransomNote_char-'a']<0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

