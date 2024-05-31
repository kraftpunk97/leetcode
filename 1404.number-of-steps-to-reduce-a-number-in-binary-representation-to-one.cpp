/*
 * @lc app=leetcode id=1404 lang=cpp
 *
 * [1404] Number of Steps to Reduce a Number in Binary Representation to One
 */
#include <cstdio>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        for (int i=s.length()-1; i>0; i--) {
            char current_bit = s[i];
            if ((current_bit-'0')+carry == 1) {
                steps += 2;
                carry = 1;
            } else {
                steps += 1;
            }
        }
        steps += carry;
        return steps;
    }
};
// @lc code=end

int main() {
    string s = "1011001";
    Solution solution;
    printf("%d\n", solution.numSteps(s));
    return 0;
}