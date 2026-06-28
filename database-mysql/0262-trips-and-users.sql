# Write your MySQL query statement below
SELECT 
    request_at AS "Day",
    ROUND(SUM(IF(status <> 'completed', 1, 0)) / COUNT(*), 2) AS "Cancellation Rate"
FROM 
    Trips t
LEFT JOIN 
    Users c ON t.client_id = c.users_id
LEFT JOIN 
    Users d ON t.driver_id = d.users_id
WHERE
    c.banned = 'No' AND 
    d.banned = 'No'AND
    request_at >= '2013-10-01' AND
    request_at <= '2013-10-03'
GROUP BY
    request_at
ORDER BY
    request_at ASC