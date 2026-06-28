WITH category_sales AS (
    SELECT
        category,
        quantity,
        quantity * price AS revenue,
        CASE
            WHEN(MONTH(sale_date) IN ( 3,  4,  5)) THEN "Spring"
            WHEN(MONTH(sale_date) IN ( 6,  7,  8)) THEN "Summer"
            WHEN(MONTH(sale_date) IN ( 9, 10, 11)) THEN "Fall"
            WHEN(MONTH(sale_date) IN (12,  1,  2)) THEN "Winter"
        END AS season
    FROM
        sales
    LEFT JOIN
        products USING (product_id)
),
category_aggregate AS (
    SELECT
        season,
        category,
        SUM(quantity) AS total_quantity,
        SUM(revenue)  AS total_revenue
    FROM
        category_sales
    GROUP BY
        season,
        category
),
category_season_ranking AS (
    SELECT
        season,
        category,
        total_quantity,
        total_revenue,
        RANK() OVER season_ranking AS ranking_position
    FROM
        category_aggregate
    WINDOW 
        season_ranking AS (PARTITION BY season ORDER BY total_quantity DESC, total_revenue DESC) 
)
SELECT 
    season,
    category,
    total_quantity,
    total_revenue
FROM
    category_season_ranking
WHERE 
    ranking_position = 1
ORDER BY
    season ASC