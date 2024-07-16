/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        // Find the location of all the characters in the string
        map<int, int> last_pos; // Ordered map
        for (int pos=0; pos<s.size(); pos++) {
            int key = s[pos]-'a';
            last_pos[key] = pos;
        }

        vector<int> str_builder;
        unordered_set<int> seen;
        for (int pos=0; pos<s.size(); pos++) {
            int key = s[pos] - 'a';
            if (seen.find(key) == seen.end()) {
                while(!str_builder.empty() && key<str_builder.back() && last_pos[str_builder.back()]>pos) {
                    // If the last char of our result string is greater than the element we are currently looking at
                    // and if we have more of this char later down the road, then we can choose one of them 
                    seen.erase(str_builder.back());
                    str_builder.pop_back();
                }
                str_builder.push_back(key);
                seen.insert(key);
            }
        }

        // Reconstruct the string from str_builder
        string result = "";
        for (int key: str_builder) {
            result += key+'a';
        }

        return result;

    }
};
// @lc code=end

int main() {
    string s = "cbacdcbc";
    Solution sol;
    cout << sol.removeDuplicateLetters(s) << '\n';
    return 0;
}