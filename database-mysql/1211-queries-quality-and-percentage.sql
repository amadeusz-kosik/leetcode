SELECT
    query_name,
    ROUND(SUM(rating / position)                / COUNT(*), 2) AS quality,
    ROUND(COUNT(IF(rating < 3, 1, NULL)) * 100  / COUNT(*), 2) AS poor_query_percentage
FROM
    Queries
GROUP BY
    query_name