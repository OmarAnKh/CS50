import csv
import re
counter=0
with open("/workspaces/109346206/course/week7/first_pro/shows0 (1).csv","r") as file:
    reader=csv.DictReader(file)

    for row in reader:
        primaryTitle=row["primaryTitle"].strip().lower()
        if re.search("(voice|voice.?.?)",primaryTitle):
            counter = counter + 1
print(counter)
