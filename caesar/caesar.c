#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char p, int n);

int main(int argc, string argv[])
{ // be sure the command line includes only 2 arguments
    if ((argc != 2) || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int k, i;
        k = atoi(argv[1]);

        string plain = get_string("plaintext: ");

        printf("ciphertext:");
        for (i = 0; i < strlen(plain); i++)
        {
            printf("%c", rotate(plain[i], k));
        }
        printf("\n");
    }
}
// create a function to find out if the second variable is a digit or not
bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)

        if (!isdigit(s[i]))
        {
            printf("Usage: ./caesar key\n");
            return 0;
        }
    return 1;
}

char rotate(char p, int n)
{
    char c;
    if (isupper(p))
    {
        c = (p - 'A' + n) % 26 + 'A';
    }
    else if (islower(p))
    {
        c = (p - 'a' + n) % 26 + 'a';
    }
    else
    {
        c = p;
    }
    return c;
}
