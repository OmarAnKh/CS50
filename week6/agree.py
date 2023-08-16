from cs50 import get_string

s=get_string("Do you agree? ").lower()

if s in ["y","yes"]:
    print("agree")
elif s in ["n","no"]:
    print("disagree")