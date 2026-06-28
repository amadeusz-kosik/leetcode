WITH product_pairs AS (
    SELECT 
        p1.product_id AS product1_id,
        p2.product_id AS product2_id,
        COUNT(p1.user_id) AS customer_count
    FROM
        ProductPurchases p1
    INNER JOIN
        ProductPurchases p2
    ON 
        p1.user_id = p2.user_id AND p1.product_id < p2.product_id
    GROUP BY
        p1.product_id, p2.product_id
),
valid_pairs AS (
    SELECT
        product1_id,
        product2_id,
        customer_count
    FROM
        product_pairs
    WHERE 
        customer_count >= 3
),
valid_pairs_with_category AS (
    SELECT
        product1_id,
        product2_id,
        pi1.category AS product1_category,
        pi2.category AS product2_category,
        customer_count
    FROM
        valid_pairs
    LEFT JOIN
        ProductInfo pi1 
    ON 
        product1_id = pi1.product_id
    LEFT JOIN
        ProductInfo pi2
    ON 
        product2_id = pi2.product_id
)

SELECT 
    product1_id,
    product2_id,
    product1_category,
    product2_category,
    customer_count
FROM
    valid_pairs_with_category
ORDER BY
    customer_count DESC,
    product1_id ASC,
    product2_id ASC