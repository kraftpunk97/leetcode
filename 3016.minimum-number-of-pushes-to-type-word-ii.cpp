/*
 * @lc app=leetcode id=3016 lang=cpp
 *
 * [3016] Minimum Number of Pushes to Type Word II
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26, 0);

        for (char c: word) {
            count[c-'a'] += 1;
        }

        sort(count.begin(), count.end(), [](int a, int b) {
            return a > b;
        });

        int presses = 0;
        for (int i=0; i<26; i++) {
            presses += count[i] * ((i/8)+1);
        }

        return presses;
    }
};
// @lc code=end

