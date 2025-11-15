WITH valid_prices AS (
    SELECT DISTINCT
        product_id,
        change_date,
        new_price
    FROM 
        Products p
    WHERE
        change_date <= '2019-08-16'
),
last_prices AS (
    SELECT DISTINCT
        product_id,
        LAST_VALUE(new_price) OVER (
            PARTITION BY product_id 
            ORDER BY change_date ASC 
            RANGE BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING
        ) AS price
    FROM 
        valid_prices vp
),
all_products AS (
    SELECT DISTINCT
        product_id
    FROM
        Products p
)

SELECT
    product_id,
    IFNULL(price, 10) AS price
FROM 
    all_products ap
LEFT JOIN
    last_prices vp USING (product_id)
