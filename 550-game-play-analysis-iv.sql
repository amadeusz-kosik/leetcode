WITH activities AS (
    SELECT 
        player_id, 
        device_id,
        event_date,
        FIRST_VALUE(event_date) OVER win AS first_event_date
    FROM 
        Activity a
    WINDOW 
        win AS (PARTITION BY player_id ORDER BY event_date ASC)
),
activities_seconds AS (
    SELECT 
        *
    FROM 
        activities 
    WHERE 
        event_date = DATE_ADD(first_event_date, INTERVAL 1 DAY)
)

SELECT 
    ROUND((SELECT COUNT(DISTINCT player_id) FROM activities_seconds) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
    