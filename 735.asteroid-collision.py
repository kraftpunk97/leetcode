#
# @lc app=leetcode id=735 lang=python3
#
# [735] Asteroid Collision
#

from typing import List

# @lc code=start
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        for rock in asteroids:
            if not stack:
                stack.append(rock)
            else:
                if stack[-1] > 0 and rock < 0:
                    while stack[-1] > 0 and rock < 0:
                        stackRock = stack.pop()
                        if abs(stackRock) > abs(rock):
                            stack.append(stackRock)
                            break
                        elif abs(stackRock) < abs(rock):
                            continue
                        else:
                            break
                else:
                    stack.append(rock)
            print(stack)
        return stack                   
# @lc code=end

def main():
    s = Solution()
    asteroids =  [-2,-2,1,-2]
    print(s.asteroidCollision(asteroids))


if __name__ == '__main__':
    main()