WITH orders AS (
    SELECT 
        *
    FROM
        Orders
    WHERE
        YEAR(order_date) = 2020 AND MONTH(order_date) = 2
),
orders_agg AS (
    SELECT
        product_id,
        SUM(unit) AS units
    FROM
        orders
    GROUP BY
        product_id
)

SELECT 
    product_name,
    units AS unit
FROM
    orders_agg
LEFT JOIN
    Products USING (product_id)
WHERE
    units >= 100