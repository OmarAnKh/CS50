import csv
titles={}
with open("/workspaces/109346206/course/week7/first_pro/shows0 (1).csv","r") as file:
    reader=csv.DictReader(file)

    for row in reader:
            primaryTitle=row["primaryTitle"].strip().lower()
            if not primaryTitle in titles:
                titles[primaryTitle]=0
            titles[primaryTitle]+=1




for primaryTitle in sorted(titles, key=lambda primaryTitle: titles[primaryTitle], reverse=True) :
    print(primaryTitle , titles[primaryTitle])
