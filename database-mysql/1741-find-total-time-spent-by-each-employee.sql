WITH spent_time AS (
    SELECT
        event_day,
        emp_id,
        out_time - in_time AS  spent_time
    FROM
        Employees
)
SELECT
    event_day       AS "day",
    emp_id,
    SUM(spent_time) AS total_time
FROM
    spent_time
GROUP BY 
    event_day, 
    emp_id