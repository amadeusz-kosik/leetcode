SELECT 
    e.name
FROM
    (SELECT managerId, COUNT(*) AS reports FROM Employee GROUP BY managerId HAVING reports >= 5) m
    INNER JOIN Employee e ON m.managerId = e.id