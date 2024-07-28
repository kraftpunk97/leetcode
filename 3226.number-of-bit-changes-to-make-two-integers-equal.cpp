/*
 * @lc app=leetcode id=3226 lang=cpp
 *
 * [3226] Number of Bit Changes to Make Two Integers Equal
 */
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int minChanges(int n, int k) {
        int counter = 0;
        while (n!=0 && k!=0) {
            if (((n&0b1)==1) == ((k&0b1)==1)) {
                // Both bits are equal. Do nothing.
            } else if (((n&0b1)==1) && ((k&0b1)==0)) {
                // Conversion possible.
                counter++;
            } else { // n&0b1==0 && k&0b1==1
                // Impossible
                return -1;
            }
            n = n >> 1;
            k = k >> 1;
        }

        if (k!=0 && n==0) { return -1; }
        else if (n!=0 && k==0) {
            while (n!=0) {
                if ((n&0b1) == 1) {
                    counter++;
                }
                n = n >> 1;
            }
            
        }
        return counter;
    }
};
// @lc code=end

int main() {
    Solution s;
    s.minChanges(13, 4);
    return 0;
}
