from cs50 import get_string

people ={
    "omar":"0-598-929-151",
    "ruba":"0-598-602-292"
}
name =get_string("name: ")
if name in people:
    number =people[name]
    print(f"number: {number}")