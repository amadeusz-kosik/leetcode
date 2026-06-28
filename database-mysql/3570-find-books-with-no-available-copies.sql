WITH borrowed_books AS (
    SELECT
        book_id,
        COUNT(*) AS borrowed_copies
    FROM
        borrowing_records
    WHERE
        return_date IS NULL
    GROUP BY 
        book_id
)
SELECT
    book_id,
    title,
    author,
    genre,
    publication_year,
    total_copies AS current_borrowers
FROM
    library_books
INNER JOIN
    borrowed_books USING (book_id)
WHERE
    total_copies = borrowed_copies
ORDER BY
    current_borrowers DESC,
    title ASC 