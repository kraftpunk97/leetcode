/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        int hash[26]={0};
        int maxFre = 0;
        while(r<n) {
            hash[s[r]-'A']++;
            if(hash[s[r]-'A']>maxFre){
                maxFre = hash[s[r]-'A'];
            }
            while((r-l+1)-maxFre>k) {
                hash[s[l]-'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;      
        }
        return ans;       
    }
};
// @lc code=end

int main() {
    return 0;
}