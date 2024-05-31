/*
 * @lc app=leetcode id=1089 lang=c
 *
 * [1089] Duplicate Zeros
 */

// @lc code=start
void duplicateZeros(int* arr, int arrSize) {
  for (int i=0; i<arrSize; i++) {
      if (arr[i] == 0) {
          for(int j=arrSize-1; j>i+1; j--) {
              arr[j] = arr[j-1];
          }
          i = i + 1;
          if (i<arrSize) // Edge case test if the array ends with a 0.
           { 
                arr[i] = 0;
           }
      }
          
  }
}
// @lc code=end

