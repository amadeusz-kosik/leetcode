WITH _users AS (
    SELECT
        user_id AS buyer_id,
        join_date
    FROM
        Users
),
_orders_aggregated AS (
    SELECT
        buyer_id,
        COUNT(*) AS orders_in_2019
    FROM
        Orders
    WHERE 
        YEAR(order_date) = 2019
    GROUP BY
        buyer_id
)

SELECT
    buyer_id,
    join_date,
    IFNULL(orders_in_2019, 0) AS orders_in_2019
FROM
    _users
LEFT JOIN
    _orders_aggregated USING (buyer_id)
