SELECT
    CASE
        WHEN id % 2 = 0 THEN id - 1
        ELSE LEAST(id + 1, (SELECT MAX(id) FROM Seat))
    END AS id,
    student
FROM
    Seat
ORDER BY
    id ASC