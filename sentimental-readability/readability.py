# TODO
from cs50 import get_string,


def main():
    # variables for the coleman formula
    text = get_string("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # calculating variables for the coleman_liau index
    L = (letters * 100) / words
    S = (sentences * 100) / words

    # calculating index
    index = 0.0588 * L - 0.296 * S - 15.8

    # rounding the float numbers to integers
    index_1 = round(index)

    # finding out the grade
    if index_1 <= 0:
        print("Before Grade 1")

    elif index_1 > 16:
        print("Grade 16+")

    else:
        print(f"Grade {index_1}")

# calculate the number of letters in the text


def count_letters(text):
    letters = 0
    for i in range(len(text)):
        if text[i].isalpha() == True:
            letters += 1

    return letters

# calculate the number of words in the text


def count_words(text):
    words = 1
    for i in range(len(text)):
        if text[i] == " ":
            words += 1

    return words

# calculate the number of sentences in the text


def count_sentences(text):
    sentences = 0
    for i in range(len(text)):
        if text[i] == "." or text[i] == "!" or text[i] == "?":
            sentences += 1

    return sentences


main()
