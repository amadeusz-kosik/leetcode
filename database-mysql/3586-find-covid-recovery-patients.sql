WITH first_positive AS (
    SELECT
        patient_id,
        MIN(test_date) AS positive_date
    FROM
        covid_tests
    WHERE
        result = 'Positive'
    GROUP BY
        patient_id
),

first_negative AS (
    SELECT
        ptests.patient_id,
        positive_date,
        MIN(test_date) AS negative_date
    FROM
        first_positive ptests
    INNER JOIN
        covid_tests ntests ON (ptests.patient_id = ntests.patient_id) AND ntests.test_date > positive_date
    WHERE
        ntests.result = 'Negative'
    GROUP BY
        ptests.patient_id,
        ptests.positive_date
)

SELECT 
    patient_id,
    patient_name,
    age,
    DATEDIFF(negative_date, positive_date) AS recovery_time
FROM 
    first_negative
INNER JOIN
    patients USING (patient_id)
ORDER BY
    recovery_time ASC,
    patient_name  ASC