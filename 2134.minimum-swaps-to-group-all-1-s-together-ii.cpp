/*
 * @lc app=leetcode id=2134 lang=cpp
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // Find the minimum number of swaps to concentrate all the 1s.
        // Find the minimum number of swaps to concentrate all the 0s.
        // Return the smaller number of the two.
        int oneSwaps = minSwaps(nums, 1);
        if (oneSwaps == 0) { return 0; }
        int zeroSwaps = minSwaps(nums, 0);

        return min(oneSwaps, zeroSwaps);
    }

    int minSwaps(vector<int>& nums, int groupNum) {
        // This uses SLIDING WINDOW, not TWO-POINTER method.
        // The number of 1's (groupNum) in the array is fixed.
        // That is going to be the size of our window.
        // The number of 0's (inBetween) in that window is the number
        // of swaps we need to make to group all the ones in 
        // that window. We try this for all possible subarrays.
        // Swap the values of the groupNum and inBetween when checking for 0's.
        
        int n = nums.size();
        int inBetween = 1 - groupNum;
        
        // Counting the number of 1's
        
        int numGroupNums = 0;
        for (int i=0; i<n; i++) {
            numGroupNums += (nums[i]==groupNum);
        }
        if (numGroupNums==0 || numGroupNums==n) { return 0; } 
        
        // Count the number of 0's in every window
        
        int windowSize = numGroupNums;
        int numInBetween = 0;
        for (int i=0; i<windowSize; i++) {
            numInBetween += (nums[i]==inBetween);
        }
        int start = 0;
        int end = start + windowSize - 1;
        int minNumInBetween = numInBetween;
        while (end < n-1) {
            // When sliding the window, if the we drop a 0
            // and get a 1, then the num of 0's in the window
            // goes down by 1.
            if (nums[start]==inBetween && nums[end+1]==groupNum) {
                numInBetween--;
            }
            // ...and vice-versa.
            if (nums[start]==groupNum && nums[end+1]==inBetween) {
                numInBetween++;
            }

            minNumInBetween = min(minNumInBetween, numInBetween);
            // Short-circuiting if all the 1's are stacked together, by chance.
            if (minNumInBetween == 0) { return 0; }
            
            start++;
            end++;
        }
        return minNumInBetween;
    }
};
// @lc code=end

int main(int argc, char* argv[]) {
    vector<int> nums{0,1,1,1,0,0,1,1,0};
    Solution s;
    s.minSwaps(nums);
    return 0;
}
