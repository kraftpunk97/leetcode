#
# @lc app=leetcode id=2071 lang=python3
#
# [2071] Maximum Number of Tasks You Can Assign
#
from typing import List
import heapq
from sortedcontainers import SortedList

# @lc code=start
class Solution:
    def maxTaskAssign(self, tasks: List[int], workers: List[int], pills: int, strength: int) -> int:
        heapq.heapify(tasks)
        heapq.heapify(workers)

        res = 0
        while tasks and workers:
            task = heapq.heappop(tasks)
            while workers:
                worker = heapq.heappop(workers)
                if worker >= task:
                    res += 1
                    break
                else:
                    if pills and worker + strength >= task:
                        pills -= 1
                        res += 1
                        break
        return res
# @lc code=end

def main():
    s = Solution()
    tasks = [10,15,30]
    workers = [0,10,10,10,10]
    pills = 3
    strength = 10
    print(s.maxTaskAssign(tasks, workers, pills, strength))

if __name__ == '__main__':
    main()