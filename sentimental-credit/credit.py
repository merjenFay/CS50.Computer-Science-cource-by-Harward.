# TODO
from cs50 import get_int

# get the user input
while True:
    creditcard_number = get_int("enter your card number: ")
    if creditcard_number > 0:
        break

# identifying odd and even numberss and making the sum of them by luhn formula
def luhn_checksum(card_number):
    def digits_of(n):
        return [int(d) for d in str(n)]
    digits = digits_of(card_number)
    odd_digits = digits[-1::-2]
    even_digits = digits[-2::-2]
    checksum = 0
    checksum += sum(odd_digits)
    for d in even_digits:
        checksum += sum(digits_of(d*2))
    return checksum % 10

# cehcking the length of the card number
def card_len(n):
    if len(str(n)) == 13 or len(str(n))== 15 or len(str(n))== 16:
        return True
    else:
        return False

# checking for visa card
def check_visa(n):
    if (n[0] == '4'):
        return True
    else:
        return False

#checking for mastercard
def check_master(n):
    if (n[:2] == '51') or  (n[:2] == '52') or (n[:2] == '53') or (n[:2] == '54') or (n[:2] == '55'):
        return True
    else:
        return False

#checking for amex
def check_americanexpress(n):
    if (n[:2] == '34') or (n[:2] == '37'):
        return True
    else:
        return False

# create a function for printng the brand of the card
def print_brand(n):
    if check_visa(n):
        print("VISA")
    if check_master(n):
         print("MASTERCARD")
    if check_americanexpress(n):
        print("AMEX")



# print the end result
if luhn_checksum(creditcard_number) == 0 and card_len(creditcard_number) == True:
    print_brand(str(creditcard_number))
else:
    print("INVALID")
