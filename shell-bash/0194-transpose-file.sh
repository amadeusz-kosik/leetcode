awk '
{
    for (i=1; i<=NF; i++) {
        a[i, NR] = $i               # store field i of line NR
    }
    max_fields = (NF > max_fields) ? NF : max_fields
    max_rows   = NR
}
END {
    for (i=1; i<=max_fields; i++) {
        line = a[i,1]
        for (j=2; j<=max_rows; j++) line = line " " a[i,j]
        print line
    }
}' file.txt