SELECT 
    id AS Id
FROM (
    SELECT 
        id,
        recordDate,
        temperature,
        DATE_SUB(recordDate, INTERVAL 1 DAY)    AS previousRecordDate,
        FIRST_VALUE(recordDate)  OVER yesterday AS yesterday_recordDate,
        FIRST_VALUE(temperature) OVER yesterday AS yesterday_temperature
    FROM
        Weather
    WINDOW yesterday AS (
        ORDER BY recordDate 
        ROWS BETWEEN 1 PRECEDING AND CURRENT ROW
    )
) source
WHERE
    yesterday_recordDate = previousRecordDate AND
    temperature > yesterday_temperature