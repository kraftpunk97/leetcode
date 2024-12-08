/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        // Removing non-alphanumeric characters;
        s.erase(remove_if(s.begin(), s.end(), not_fn(function((int(*)(int))isalnum))), s.end());
        
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { // Lowercase
            return tolower(c);
        });

        int n = s.length();
        for (int pos=0; pos<n/2; pos++) {
            if (s[pos] != s[n-pos-1]) { return false; }
        }
        return true;
    }
};
// @lc code=end

int main() {
    string s = "A man, a plan, a canal: Panama12";
    Solution sol;
    sol.isPalindrome(s);
}
