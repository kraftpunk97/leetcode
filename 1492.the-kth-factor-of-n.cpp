/*
 * @lc app=leetcode id=1492 lang=cpp
 *
 * [1492] The kth Factor of n
 */

#include <cmath>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;

        for (int i=1; i<=(int)sqrt(n); i++) {
            if (n%i == 0) { 
                factors.push_back(i);
                if (factors.size() == k) {
                    return i;
                }
            }
        }
        
        // Kth factor is larger than the square root of n.
        int list_largest_factor = factors.back();
        int m;
        if (n/list_largest_factor == list_largest_factor) { // Square, # of factors = 2*len(factors) - 1
            m = 2*factors.size() - 1;
        } else {
            m = 2*factors.size();
        }

        if (k > m) { return -1; }

        return n/factors[m-k];
    }
};
// @lc code=end

