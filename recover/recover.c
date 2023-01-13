#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    // check for one command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    if (argv[1] == NULL)
    {
        printf("file does not exist\n");
        return 2;
    }
    // create a buffer of size 512 bytes
    unsigned char *buffer = malloc(512 * sizeof(unsigned char));

    // create a counter to keep track of recovered images
    int counter = 0;

    // create a file pointer for recovered images
    FILE *output = NULL;

    // create a space in the memory for the size of the filename
    char *filename = malloc(8 * sizeof(char));

    // read the blocks of 512 bytes
    while (fread(buffer, sizeof(char), 512, input))
    {
        // check if there is start of jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0 )
        {
            // if there is jpeg file then create new filename for it
            sprintf(filename, "%03i.jpg", counter);
            // open that output file to write in it
            output = fopen(filename, "w");
            // track the number of recovered images
            counter++;

        }

        // check if that opened files don't return NULL value
            if(output != NULL)
            {   // write the new gpeg file here
                fwrite(buffer, sizeof(char), 512, output);
            }
    }


    free(filename);
    free(buffer);
    fclose(input);
    fclose(output);


    return 0;
}