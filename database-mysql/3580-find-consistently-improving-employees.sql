WITH valid_employees AS (
    SELECT
        employee_id,
        MAX(review_date) AS last_review_date
    FROM
        performance_reviews
    GROUP BY
        employee_id
    HAVING
        COUNT(*) >= 3
),
reviews AS (
    SELECT 
        employee_id,
        last_review_date,
        review_date,
        NTH_VALUE(rating, 1) OVER reviews AS score_1,
        NTH_VALUE(rating, 2) OVER reviews AS score_2,
        NTH_VALUE(rating, 3) OVER reviews AS score_3
    FROM
        valid_employees 
    INNER JOIN
        performance_reviews USING (employee_id)
    WINDOW reviews AS (
        PARTITION BY employee_id 
        ORDER BY review_date DESC
        ROWS BETWEEN CURRENT ROW AND 2 FOLLOWING
    )
),
valid_reviews AS (
    SELECT
        employee_id,
        score_1 - score_3 AS improvement_score
    FROM
        reviews        
    WHERE 
        score_1 > score_2 AND
        score_2 > score_3 AND         
        review_date = last_review_date         
)

SELECT 
    employee_id,
    name,
    improvement_score
FROM 
    valid_reviews
INNER JOIN 
    employees USING (employee_id)
ORDER BY
    improvement_score DESC,
    name ASC