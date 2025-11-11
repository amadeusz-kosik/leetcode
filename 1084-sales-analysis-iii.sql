WITH matching_sales AS (
    SELECT
        product_id
    FROM
        Sales
    GROUP BY
        product_id
    HAVING
        MIN(sale_date) >= '2019-01-01' AND MAX(sale_date) <= '2019-03-31'
)

SELECT
    product_id, product_name
FROM
    matching_sales 
INNER JOIN 
    Product USING (product_id)