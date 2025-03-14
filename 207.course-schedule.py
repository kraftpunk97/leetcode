#
# @lc app=leetcode id=207 lang=python3
#
# [207] Course Schedule
#
from typing import List
from collections import deque

# @lc code=start
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if not prerequisites: return True
        inDegrees = {course: 0 for dep in prerequisites for course in dep}
        edges = {course: [] for dep in prerequisites for course in dep}
        for (l, r) in prerequisites:
            inDegrees[l] += 1
            edges[r].append(l)
        q = deque()
        remainingDeps = len(prerequisites)
        while numCourses:
            for k, v in inDegrees.items():
                if not v:
                    q.append(k)
                    inDegrees[k] = -1
            if not q:
                # Either you have a cycle, or all courses with dependencies have been handled
                return not remainingDeps
            while q:
                prereqCourse = q.popleft()
                for course in edges[prereqCourse]:
                    inDegrees[course] -= 1
                    remainingDeps -= 1
                numCourses -= 1
        return True
# @lc code=end

