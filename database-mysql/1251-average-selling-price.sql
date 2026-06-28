SELECT
    product_id,
    ROUND(IFNULL(SUM(cost) / SUM(units), 0), 2) AS average_price
FROM (
    SELECT 
        p.product_id,
        p.price,
        us.units,
        p.price * us.units AS cost
    FROM
        Prices p
    LEFT JOIN
        UnitsSold us ON 
            p.product_id = us.product_id AND 
            us.purchase_date BETWEEN p.start_date AND p.end_date
) tx
GROUP BY
    product_id