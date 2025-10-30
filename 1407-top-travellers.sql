WITH rides_aggregated AS (
    SELECT 
        user_id,
        SUM(distance) AS travelled_distance
    FROM
        Rides
    GROUP BY 
        user_id
)

SELECT  
    u.name,
    IFNULL(ra.travelled_distance, 0) AS travelled_distance
FROM
    Users u LEFT JOIN rides_aggregated ra ON u.id = ra.user_id
ORDER BY
    travelled_distance DESC,
    name ASC