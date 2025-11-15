WITH source AS (
    SELECT
        id,
        NTH_VALUE(num, 1) OVER win3 AS num_1,
        NTH_VALUE(num, 2) OVER win3 AS num_2,
        NTH_VALUE(num, 3) OVER win3 AS num_3
    FROM
        Logs
    WINDOW 
        win3 AS (ORDER BY id ASC ROWS BETWEEN CURRENT ROW AND 2 FOLLOWING)
)
SELECT
    DISTINCT num_1 AS ConsecutiveNums
FROM
    source
WHERE
    num_1 = num_2 AND num_2 = num_3