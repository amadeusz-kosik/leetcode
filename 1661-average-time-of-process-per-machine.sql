WITH processes AS (
    SELECT
        machine_id,
        process_id,
        start.timestamp AS timestamp_start,
        end.timestamp   AS timestamp_end,
        end.timestamp - start.timestamp AS processing_time
    FROM
        (SELECT * FROM Activity WHERE activity_type = 'start') start
    INNER JOIN
        (SELECT * FROM Activity WHERE activity_type = 'end')   end 
    USING (machine_id, process_id)
)

SELECT 
    machine_id,
    ROUND(AVG(processing_time), 3) AS processing_time
FROM
    processes
GROUP BY 
    machine_id