SELECT 
    p.name 
FROM
    SalesPerson p
WHERE
    sales_id NOT IN (
        SELECT 
            o.sales_id
        FROM 
            Company c 
            INNER JOIN Orders o ON c.com_id = o.com_id
            INNER JOIN SalesPerson p ON p.sales_id = o.sales_id
        WHERE 
            c.name = 'RED'
    )