import csv
from cs50 import SQL

test = SQL("sqlite:////workspaces/109346206/course/week7/first_pro/DBS.db")

title = input("Title: ").strip()

rows = test.execute("SELECT COUNT(*) AS counter FROM DBS WHERE primaryTitle LIKE ?",title)
row =rows[0]

print (row["counter"])