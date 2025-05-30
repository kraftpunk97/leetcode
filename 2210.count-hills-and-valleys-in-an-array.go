/*
 * @lc app=leetcode id=2210 lang=golang
 *
 * [2210] Count Hills and Valleys in an Array
 */
package main

// @lc code=start
func countHillValley(nums []int) int {
	d := []int{nums[0]}
	for i := 1; i < len(nums); i++ {
		if nums[i] != d[len(d)-1] {
			d = append(d, nums[i])
		}
	}

	c := 0
	for i := 1; i < len(d)-1; i++ {
		if d[i-1] < d[i] && d[i] > d[i+1] {
			c += 1
		}
		if d[i-1] > d[i] && d[i] < d[i+1] {
			c += 1
		}
	}

	return c
}

// @lc code=end
