#include "helpers.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float averageNum=0;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            averageNum=round(((float)image[i][j].rgbtRed +(float)image[i][j].rgbtGreen+(float)image[i][j].rgbtBlue)/3);
            image[i][j].rgbtRed=averageNum;
            image[i][j].rgbtGreen=averageNum;
            image[i][j].rgbtBlue=averageNum;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
          int MAX_VALUE =255;
          int a=image[i][j].rgbtRed;
          int b =image[i][j].rgbtGreen;
          int c = image[i][j].rgbtBlue;

          float red = fmin(round((.393 * a) +(.769 * b) + (.189 * c)),255);
          float green =fmin(round((.349 * a) + (.686 * b) + (.168 * c)),255);
          float blue = fmin(round((.272 * a) +(.534 * b) + (.131 *c)),255);
            if(red>MAX_VALUE &&red>0 )
            {
                image[i][j].rgbtRed = MAX_VALUE;
            }
            else if(green>MAX_VALUE&&green>0)
            {
                image[i][j].rgbtGreen = MAX_VALUE;
            }
            else if(blue>MAX_VALUE &&blue>0 )
            {
                image[i][j].rgbtBlue = MAX_VALUE;
            }else
            {
            image[i][j].rgbtRed=red;
            image[i][j].rgbtGreen=green;
            image[i][j].rgbtBlue=blue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width/2;j++)
        {
            tmp[i][j].rgbtRed=image[i][j].rgbtRed;
            tmp[i][j].rgbtGreen=image[i][j].rgbtGreen;
            tmp[i][j].rgbtBlue=image[i][j].rgbtBlue;
            image[i][j].rgbtRed = fmin(image[i][width-j-1].rgbtRed,255);
            image[i][j].rgbtGreen = fmin(image[i][width-j-1].rgbtGreen,255);
            image[i][j].rgbtBlue =fmin(image[i][width-j-1].rgbtBlue,255);

            image[i][width-j-1].rgbtRed=tmp[i][j].rgbtRed;
            image[i][width-j-1].rgbtGreen= tmp[i][j].rgbtGreen;
            image[i][width-j-1].rgbtBlue =tmp[i][j].rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
