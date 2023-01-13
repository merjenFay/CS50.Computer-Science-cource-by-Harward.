# TODO
from cs50 import get_float
def main():


    cents = get_float("enter the amount of change that is owed: ")
    cents = round(cents * 100)
    while cents < 0:
        print(f"{cents}")

    count = 0




    while cents > 25 or cents == 25:
        cents = cents - 25
        count+=1




    while cents > 10 or cents == 10:
        cents = cents - 10
        count+=1




    while cents > 5 or cents == 5:
        cents = cents - 5
        count+=1




    while cents > 1 or cents == 1:
        cents = cents - 1
        count+=1
    
    print(f"{count}")
main()