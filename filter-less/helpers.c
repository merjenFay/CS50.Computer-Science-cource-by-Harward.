#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // loop through the rows of the image
    for (int i = 0; i < height; i++)
    {
        // loop through the columns of the image
        for (int j = 0; j < width; j++)
        {
            // calculate the average pixel value
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;
            int average = round((blue + green + red) / 3);

            // set each color value to the average value
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // loop through each pixel of the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            // calculate each new color value by sepia formula
            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            // set the new value to the image pixel
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // loop through every row of the image
    for (int i = 0; i < height; i++)
    {
        // loop through the half of the columns of the image to not get the original image again
        for (int j = 0; j < width / 2; j++)

        {
            // do the swap
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{ // make a temporary copy of the real image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red, green, blue;
            int counter;
            red = green = blue = 0;
            counter = 0;
            // find neeighbouring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;
                    // check the validity of the neighbour pixel
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }
                    // set the image value
                    red += image[currentX][currentY].rgbtRed;
                    green += image[currentX][currentY].rgbtGreen;
                    blue += image[currentX][currentY].rgbtBlue;

                    counter++;
                }
                // average of neighbour pixels
                temp[i][j].rgbtRed = round(red / counter);
                temp[i][j].rgbtGreen = round(green / counter);
                temp[i][j].rgbtBlue = round(blue / counter);
            }
        }
    }
    // copy the blurred pixels into the original ones
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
