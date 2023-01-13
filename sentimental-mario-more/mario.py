# TODO
from cs50 import get_int
height = get_int("enter the height of the pyramid ")
while height < 0 or height > 8:
    print("enter positive integers between 0 and 8")
for rows in range(height):
    for space in range(height - rows - 1):
        print(end=" ")
    for columns in range(rows + 1):
        print("#", end="")
    print(end="  ")
    for columns in range(rows + 1):
        print("#", end="")
    print()
