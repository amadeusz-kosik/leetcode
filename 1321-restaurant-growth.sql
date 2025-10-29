WITH daily AS (
    SELECT 
        visited_on,
        SUM(amount) AS amount
    FROM
        Customer
    GROUP BY
        visited_on
),
weekly AS (
    SELECT
        visited_on,
        SUM(amount) OVER week_window AS amount,
        AVG(amount) OVER week_window AS average_amount,
        COUNT(*)    OVER week_window AS days_count
    FROM
        daily
    WINDOW week_window AS (
        ORDER BY visited_on 
        ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    )
)
SELECT
    visited_on,
    amount,
    ROUND(average_amount, 2) AS average_amount
FROM 
    weekly
WHERE
    days_count = 7
ORDER BY
    visited_on ASC