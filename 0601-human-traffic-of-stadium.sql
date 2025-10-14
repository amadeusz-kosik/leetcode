SELECT 
    id, visit_date, people
FROM (
    SELECT *,
        (MIN(people)    OVER (ORDER BY id ASC ROWS BETWEEN 2 PRECEDING AND 0 FOLLOWING)) AS window_min_ppl,
        (MIN(id)        OVER (ORDER BY id ASC ROWS BETWEEN 2 PRECEDING AND 0 FOLLOWING)) AS window_min_id,
        (MIN(people)    OVER (ORDER BY id ASC ROWS BETWEEN 1 PRECEDING AND 1 FOLLOWING)) AS window_mid_ppl,
        (MIN(id)        OVER (ORDER BY id ASC ROWS BETWEEN 1 PRECEDING AND 1 FOLLOWING)) AS window_mid_id_min,
        (MAX(id)        OVER (ORDER BY id ASC ROWS BETWEEN 1 PRECEDING AND 1 FOLLOWING)) AS window_mid_id_max,
        (MIN(people)    OVER (ORDER BY id ASC ROWS BETWEEN 0 PRECEDING AND 2 FOLLOWING)) AS window_max_ppl,
        (MAX(id)        OVER (ORDER BY id ASC ROWS BETWEEN 0 PRECEDING AND 2 FOLLOWING)) AS window_max_id
    FROM 
        Stadium 
    
) s
WHERE 
    (s.window_min_ppl > 99 AND s.id = s.window_min_id + 2) OR
    (s.window_max_ppl > 99 AND s.id = s.window_max_id - 2) OR
    (s.window_mid_ppl > 99 AND s.id = s.window_mid_id_min + 1 AND s.id = s.window_mid_id_max - 1) 