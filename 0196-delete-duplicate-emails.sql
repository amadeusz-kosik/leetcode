WITH people_numbered AS (
    SELECT 
        id,
        email,
        ROW_NUMBER() OVER (PARTITION BY email ORDER BY id ASC) row_no
    FROM
        Person
)

DELETE FROM
    Person
WHERE
    id IN (SELECT id FROM people_numbered WHERE row_no > 1)