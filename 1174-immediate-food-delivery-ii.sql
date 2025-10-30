WITH first_deliveries AS (
    SELECT
        customer_id,
        MIN(order_date) = MIN(customer_pref_delivery_date) AS is_immediate
    FROM
        Delivery
    GROUP BY
        customer_id
) 
SELECT
    ROUND(AVG(is_immediate) * 100, 2) AS immediate_percentage
FROM
    first_deliveries