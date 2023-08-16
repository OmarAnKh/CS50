import sys

number = [4,6,8,2,7,5,0]

if 0 in number:
     print("found")
     sys.exit(0)
print("not found")
sys.exit(1)