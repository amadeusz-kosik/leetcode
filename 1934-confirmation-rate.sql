WITH confirm_1 AS (
    SELECT
        user_id,
        COUNT(IF(action = 'confirmed', 1, NULL)) AS confirmed,
        COUNT(*) AS total
    FROM
        Confirmations
    GROUP BY
        user_id 
), confirm_2 AS (
    SELECT
        user_id,
        confirmed / total AS rate
    FROM
        confirm_1
)
SELECT
    user_id,
    ROUND(IFNULL(rate, 0), 2) AS confirmation_rate
FROM
    Signups LEFT JOIN confirm_2 USING (user_id)