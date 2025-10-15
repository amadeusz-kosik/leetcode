SELECT name AS Customers FROM customers
    LEFT JOIN orders ON customers.id = orders.customerId
    WHERE orders.customerId IS NULL;

SELECT name AS Customers FROM customers
    WHERE id NOT IN (SELECT customerId FROM orders);
    
SELECT name AS Customers FROM customers
    WHERE id NOT IN (SELECT DISTINCT customerId FROM orders);