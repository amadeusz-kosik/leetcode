SELECT
    name,
    balance
FROM
    (SELECT account, SUM(amount) AS balance FROM Transactions GROUP BY account) tx
INNER JOIN
    Users u USING(account)
WHERE 
    balance > 10000