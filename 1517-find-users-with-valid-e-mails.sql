SELECT
    *
FROM
    Users
WHERE
    REGEXP_LIKE(mail, '^[a-zA-Z][0-9a-zA-Z_.-]*@leetcode\\.com$', 'c')