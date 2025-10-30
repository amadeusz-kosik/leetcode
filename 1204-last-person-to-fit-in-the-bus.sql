WITH board_sim AS (
    SELECT
        person_name,
        weight,
        turn,
        SUM(weight) OVER (ORDER BY turn ASC ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) AS sum_weight
    FROM
        Queue
)
SELECT
    person_name
FROM
    board_sim
WHERE
    sum_weight <= 1000
ORDER BY
    turn DESC
LIMIT 1