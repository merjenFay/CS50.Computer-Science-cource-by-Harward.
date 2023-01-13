# TODO
from cs50 import get_int
height = get_int("Enter the height of the pyramid: ")
while height < 0 or height > 8:
    print("enter the postive number between 0 to 8")
for row in range(height):
    for space in range(height - row - 1):
            print(end=" ")
    for column in range(row + 1):
            print("#",end="")
    print()