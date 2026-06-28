WITH meetings_weekly AS (
    SELECT
        employee_id,
        WEEK(meeting_date, 7)   AS week,
        SUM(duration_hours)     AS duration_hours
    FROM
        meetings
    GROUP BY
        employee_id,
        week
),
meetings_weekly_heavy AS (
    SELECT
        employee_id,
        COUNT(week) AS meeting_heavy_weeks
    FROM
        meetings_weekly
    WHERE
        duration_hours > 20
    GROUP BY
        employee_id  
    HAVING
        COUNT(week) >= 2    
),
employees_mettings_heavy AS (
    SELECT
        employee_id,
        employee_name,
        department,
        meeting_heavy_weeks
    FROM
        meetings_weekly_heavy
    LEFT JOIN
        employees USING (employee_id)
)

SELECT
    employee_id,
    employee_name,
    department,
    meeting_heavy_weeks
FROM
    employees_mettings_heavy
ORDER BY
    meeting_heavy_weeks DESC,
    employee_name       ASC