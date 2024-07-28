/*
 * @lc app=leetcode id=3227 lang=cpp
 *
 * [3227] Vowels Game in a String
 */
#include <string>
using namespace std;

// @lc code=start
#pragma GCC optimize("O3")

class Solution {
public:
    bool doesAliceWin(string s) {
        int vowel_count = 0;
        for (char c: s) {
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
                vowel_count++;   
            }
        }

        return vowel_count != 0;
    }
};
// @lc code=end

