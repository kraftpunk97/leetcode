/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<string, int> hashMap;
        if (s.length() < 11) { return result; }
        for (int i=0; i<=s.length()-10; i++) {
            string ss = s.substr(i, 10);
            if (hashMap.find(ss) != hashMap.end()) {
                if (hashMap[ss] == 1) {
                    result.push_back(ss);
                }
                hashMap[ss]++;
            } else {
                hashMap[ss] = 1;
            }
        }

        return result;
    }
};
// @lc code=end

int main() {
    Solution s;

}