/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */
#include <iostream>
// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        int T_minus2 = 0;
        int T_minus1 = 1;
        int T = 1;
        int temp;
        switch(n) {
            case 0: return T_minus2;
            break;
            case 1: return T_minus1;
            break;
            case 2: return T;
            break;
        }
        for (int i=3; i<=n; i++) {
            temp = T;
            T = T + T_minus1 + T_minus2;
            T_minus2 = T_minus1;
            T_minus1 = temp;
        }
        return T;
    }
};
// @lc code=end

int main() {

}