--
-- @lc app=leetcode id=1075 lang=postgresql
--
-- [1075] Project Employees I
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    *
FROM
    Project p
FULL JOIN
    Employee e
ON
    p.employee_id = e.employee_id;

-- @lc code=end

