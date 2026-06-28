WITH avg_activity AS (
    SELECT
        user_id,
        activity_type,
        ROUND(AVG(IF(activity_type = 'free_trial', activity_duration, NULL)), 2) AS trial_avg_duration,
        ROUND(AVG(IF(activity_type = 'paid',       activity_duration, NULL)), 2) AS paid_avg_duration
    FROM
        UserActivity
    GROUP BY
        user_id
)

SELECT 
    user_id, 
    trial_avg_duration,
    paid_avg_duration
FROM
    avg_activity 
WHERE
    paid_avg_duration IS NOT NULL
ORDER BY
    user_id ASC