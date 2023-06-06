#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blurred_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int total_red = 0;
            int total_green = 0;
            int total_blue = 0;
            int count = 0;

            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int new_i = i + k;
                    int new_j = j + l;

                    if (new_i >= 0 && new_i < height && new_j >= 0 && new_j < width)
                    {
                        total_red += image[new_i][new_j].rgbtRed;
                        total_green += image[new_i][new_j].rgbtGreen;
                        total_blue += image[new_i][new_j].rgbtBlue;
                        count++;
                    }
                }
            }

            blurred_image[i][j].rgbtRed = round((float)total_red / count);
            blurred_image[i][j].rgbtGreen = round((float)total_green / count);
            blurred_image[i][j].rgbtBlue = round((float)total_blue / count);
        }
    }

    // Copy the blurred image back to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = blurred_image[i][j];
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE edged_image[height][width];

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum_red_x = 0, sum_red_y = 0;
            int sum_green_x = 0, sum_green_y = 0;
            int sum_blue_x = 0, sum_blue_y = 0;

            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int new_i = i + k;
                    int new_j = j + l;

                    if (new_i >= 0 && new_i < height && new_j >= 0 && new_j < width)
                    {
                        sum_red_x += image[new_i][new_j].rgbtRed * Gx[k + 1][l + 1];
                        sum_red_y += image[new_i][new_j].rgbtRed * Gy[k + 1][l + 1];
                        sum_green_x += image[new_i][new_j].rgbtGreen * Gx[k + 1][l + 1];
                        sum_green_y += image[new_i][new_j].rgbtGreen * Gy[k + 1][l + 1];
                        sum_blue_x += image[new_i][new_j].rgbtBlue * Gx[k + 1][l + 1];
                        sum_blue_y += image[new_i][new_j].rgbtBlue * Gy[k + 1][l + 1];
                    }
                }
            }

            int red = round(sqrt(pow(sum_red_x, 2) + pow(sum_red_y, 2)));
            int green = round(sqrt(pow(sum_green_x, 2) + pow(sum_green_y, 2)));
            int blue = round(sqrt(pow(sum_blue_x, 2) + pow(sum_blue_y, 2)));

            edged_image[i][j].rgbtRed = red > 255 ? 255 : red;
            edged_image[i][j].rgbtGreen = green > 255 ? 255 : green;
            edged_image[i][j].rgbtBlue = blue > 255 ? 255 : blue;
        }
    }

    // Copy the edged image back to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = edged_image[i][j];
        }
    }
}
