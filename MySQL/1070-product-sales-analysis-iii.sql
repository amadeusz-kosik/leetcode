WITH first_sales AS (
    SELECT
        product_id,
        MIN(year) AS year
    FROM
        Sales
    GROUP BY
        product_id
)
SELECT
    product_id,
    year            AS first_year,
    quantity,
    price
FROM
    Sales
INNER JOIN
    first_sales USING (product_id, year)
