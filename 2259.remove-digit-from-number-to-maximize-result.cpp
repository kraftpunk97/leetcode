/*
 * @lc app=leetcode id=2259 lang=cpp
 *
 * [2259] Remove Digit From Number to Maximize Result
 */
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<int> digit_pos;
        for (size_t i=0; i<number.length(); i++) {
            if (number[i]==digit) { 
                digit_pos.push_back(i);
            }
        }
        for (int i: digit_pos) {
            if (i <= static_cast<int>(number.length()-1) && number[i] < number[i+1]) {
                return removeDigitAtPos(number, i);
            }
        }
        return removeDigitAtPos(number, digit_pos.back());
    }

    string removeDigitAtPos(string &number, size_t pos) {
        string result = "";
        for (size_t i=0; i<number.length(); i++) {
            if (i==pos) {
                continue;
            }
            result += number[i];
        }
        return result;
    }
};
// @lc code=end

int main() {
    Solution solution;
    printf("%s", solution.removeDigit("4234", '4').c_str());
    return 0;
}
