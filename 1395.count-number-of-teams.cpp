/*
 * @lc app=leetcode id=1395 lang=cpp
 *
 * [1395] Count Number of Teams
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int count = 0; 
        int n = rating.size();
        for (int j=0; j<n; j++) {
            int left_less = 0;
            int left_more = 0;
            for (int i=0; i<j; i++) {
                if (rating[i] < rating[j]) { left_less++; }
                if (rating[i] > rating[j]) { left_more++; } 
            }

            int right_more = 0;
            int right_less = 0;
            for (int k=j+1; k<n; k++) {
                if (rating[j] < rating[k]) { right_more++; }
                if (rating[j] > rating[k]) { right_less++; }
            }

            count += left_less*right_more + left_more*right_less;
        }
        return count;
    }
};
// @lc code=end

int main() {
    vector<int> rating{2,5,3,4,1};
    Solution s;
    cout << s.numTeams(rating);
    return 0;
}