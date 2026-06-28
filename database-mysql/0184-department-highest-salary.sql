SELECT
    d.name      AS Department,
    e.name      AS Employee,
    e.salary    AS Salary
FROM 
    (   SELECT *,
            RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) = 1 AS salary_rank
        FROM
            Employee 
    ) e
    LEFT JOIN Department d ON e.departmentId = d.id
WHERE 
    e.salary_rank = 1
    