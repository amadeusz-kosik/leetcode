WITH insurance_windowed AS (
    SELECT
        pid,
        tiv_2015,
        tiv_2016,
        lat,
        lon,
        COUNT(*) OVER (PARTITION BY lat, lon) AS count_latlon,
        COUNT(*) OVER (PARTITION BY tiv_2015) AS count_tiv_2015
    FROM
        Insurance
)
SELECT 
    ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM 
    insurance_windowed
WHERE
    count_latlon = 1 AND count_tiv_2015 > 1