SELECT 
    Department.name AS Department,
    Ranking.name    AS Employee,
    Ranking.salary  AS Salary
FROM 
    (
        SELECT 
            departmentId, 
            name, 
            salary, 
            DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS salary_rank
        FROM
            Employee
    ) Ranking
LEFT JOIN 
    Department ON Ranking.departmentId = Department.id
WHERE 
    Ranking.salary_rank <= 3;
    
