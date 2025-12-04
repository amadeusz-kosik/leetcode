# cat file.txt | tail -n +10 | head -n 1
# awk 'NR == 10' file.txt
sed -n '10 p' file.txt