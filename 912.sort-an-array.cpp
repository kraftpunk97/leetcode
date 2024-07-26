/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */
#include <iostream>
#include <vector>

using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Just do a merge sort
        int n = nums.size();
        heapSort(nums);
        return nums;
    }

    void heapify(vector<int> &nums, int pos, int N) {
        int l_child = 2*pos + 1;
        int r_child = 2*pos + 2;
        int largest = pos;

        largest = l_child<N&&nums[pos]<nums[l_child] ? l_child : pos;
        largest = r_child<N&&nums[largest]<nums[r_child] ? r_child : largest;

        if (largest != pos) {
            int temp = nums[pos];
            nums[pos] = nums[largest];
            nums[largest] = temp;

            heapify(nums, largest, N);
        }
    
    }

    void heapSort(vector<int> &nums) {
        int n = nums.size();
        for (int i=n/2; i>=0; i--) {
            heapify(nums, 0, n);
        }

        for (int i=n-1; i>=0; i++) {
            int temp = nums[0];
            nums[0] = nums[i];
            nums[i] = temp;
        
            heapify(nums, 0, i);
        }
    }
};
// @lc code=end

