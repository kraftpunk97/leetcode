#
# @lc app=leetcode id=84 lang=python3
#
# [84] Largest Rectangle in Histogram
#
from typing import List

# @lc code=start
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        # For every height[i],
        # 1. Find the next smallest bar to the left of heights[i].
        # 2. Find the next smallest bar to the right of heights[i].
        # 3. For each heights[i], the left next smallest and the right 
        # next smallest bar indicies determine the largest rectangle 
        # that can be created that has its width equal to heights[i].

        n = len(heights)
        stack = []

        leftmost = [-1] * n
        for i in range(n):
            while stack and heights[stack[-1]] >= heights[i]:
                stack.pop()
            if stack:
                leftmost[i] = stack[-1]
            stack.append(i)

        stack.clear()
        rightmost = [n] * n
        for i in range(n-1, -1, -1):
            while stack and heights[stack[-1]] >= heights[i]:
                stack.pop()
            if stack:
                rightmost[i] = stack[-1]
            stack.append(i)

        maxArea = 0
        for i in range(n):
            leftBoundary = leftmost[i] + 1
            rightBoundary = rightmost[i] - 1
            length = rightBoundary - leftBoundary + 1
            width = heights[i]
            area = length * width
            maxArea = max(area, maxArea)
        
        return maxArea
# @lc code=end

