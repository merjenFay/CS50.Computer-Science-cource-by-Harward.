#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h, r, c, s;
    // promt the user to enter the height of their pyramid with a  positive number
    do
    {
        h = get_int(" enter the height of your pyramid: ");
    }
    while (h < 1 || h > 8);

    // make a new row
    for (r = 0; r < h; r++)
    {
        // create space
        for (s = 0; s < h - r - 1; s++)
        {
            printf(" ");
        }
        // make a new column
        for (c = 0; c <= r; c++)
        {
            printf("#");
        }
        // add two spaces between pyramids
        printf("  ");
        // start building left alighned pyramid
        for (c = 0; c <= r; c++)
        {
            printf("#");
        }

        printf("\n");
    }
}

