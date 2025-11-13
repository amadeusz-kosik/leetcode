SELECT
    user_id,
    email    
FROM
    Users
WHERE
    REGEXP_LIKE(LOWER(email), '^[a-z0-9_]+@[a-z]+\\.com$')
ORDER BY
    user_id ASC