SELECT 
    email AS Email
FROM
    Person
WHERE
    email IS NOT NULL
GROUP BY
    email
HAVING
    COUNT(id) > 1 