WITH scores_history AS (
    SELECT
        student_id,
        subject,
        FIRST_VALUE(score) OVER w_scores AS first_score,
        LAST_VALUE( score) OVER w_scores AS latest_score
    FROM
        Scores
    WINDOW w_scores AS (
        PARTITION BY student_id, subject
        ORDER BY exam_date ASC
        RANGE BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING
    )
)
SELECT DISTINCT
    *
FROM
    scores_history
WHERE
    latest_score  IS NOT NULL AND
    first_score IS NOT NULL AND
    latest_score > first_score
ORDER BY
    student_id ASC,
    subject    ASC