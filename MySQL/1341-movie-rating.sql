(
    SELECT
        u.name AS results
    FROM (
        SELECT
            user_id,
            COUNT(*) AS reviews_count
        FROM
            MovieRating
        GROUP BY 
            user_id
    ) rc
    LEFT JOIN
        Users u USING(user_id)
    ORDER BY 
        rc.reviews_count DESC,
        u.name ASC
    LIMIT 1
)
UNION ALL (
    SELECT
        m.title AS results
    FROM (
        SELECT 
            movie_id,
            AVG(rating) AS average_rating
        FROM
            MovieRating
        WHERE
            YEAR(created_at) = 2020 AND MONTH(created_at) = 2
        GROUP BY 
            movie_id
    ) amr
    LEFT JOIN
        Movies m USING(movie_id)
    ORDER BY
        amr.average_rating DESC,
        m.title ASC
    LIMIT 1
)