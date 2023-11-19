#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
	double average;

	// image stored as image[height][width]
	// iterate through each pixel, sum rgb values and calculate avg in pixel
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			average = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
			
			image[i][j].rgbtRed = average;
			image[i][j].rgbtGreen = average;
			image[i][j].rgbtBlue = average;
		}
	}

	return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
	// calculate sepia values
	// if > 255, value = 255
	// store values
	//   sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
  	//   sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
  	//   sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue


	double sepiaRed, sepiaGreen, sepiaBlue = 0;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			sepiaRed = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
			sepiaGreen = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
			sepiaBlue = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;

			image[i][j].rgbtRed = round(sepiaRed);
			image[i][j].rgbtGreen = round(sepiaGreen);
			image[i][j].rgbtBlue = round(sepiaBlue);

			if (sepiaRed > 255)
			{
				image[i][j].rgbtRed = 255;
			}
			if (sepiaGreen > 255)
			{
				image[i][j].rgbtGreen = 255;
			}
			if (sepiaBlue > 255)
			{
				image[i][j].rgbtBlue = 255;
			}
		}
	}


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
	// iterate through the array, start from last width to first
	// store values in new array to flip horizontally
	
	RGBTRIPLE reflected[height][width];

	for (int i = 0; i < height; i++)
	{
		for (int j = width - 1; j >= 0; j--)
		{
			reflected[i][width-j-1] = image[i][j];
		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			image[i][j] = reflected[i][j];
		}
	}

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
	// take average of pixels in 3x3 box if possible
	// store in new array
	// copy array to image array
	RGBTRIPLE blurred[height][width];
	int up, down, left, right;
	float count;
	int Red, Green, Blue;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			// variables to store color value
			Red = 0;
			Green = 0;
			Blue = 0;

			// pixel location in array
			up = i-1;
			down = i+1;
			left = j-1;
			right = j+1;
			count = 0;
			
			if (up >= 0)
			{
				/*  [ ] [o] [ ]
				 *  [ ] [ ] [ ] 
				 *  [ ] [ ] [ ] */ 
				Red += image[up][j].rgbtRed;
				Green += image[up][j].rgbtGreen;
				Blue += image[up][j].rgbtBlue;
				count++;

				if (left >= 0)
				{
					/*  [o] [ ] [ ]
					 *  [ ] [ ] [ ] 
					 *  [ ] [ ] [ ] */ 
					Red += image[up][left].rgbtRed;
					Green += image[up][left].rgbtGreen;
					Blue += image[up][left].rgbtBlue;
					count++;
				}

				if (right <= width)
				{
					/*  [ ] [ ] [o]
					 *  [ ] [ ] [ ] 
					 *  [ ] [ ] [ ] */ 
					Red += image[up][right].rgbtRed;
					Green += image[up][right].rgbtGreen;
					Blue += image[up][right].rgbtBlue;
					count++;
				}
			}
			if (down <= height)
			{
				/*  [ ] [ ] [ ]
				 *  [ ] [ ] [ ] 
				 *  [ ] [o] [ ] */ 
				Red += image[down][j].rgbtRed;
				Green += image[down][j].rgbtGreen;
				Blue += image[down][j].rgbtBlue;
				count++;

				if (left >= 0)
				{
					/*  [ ] [ ] [ ]
					 *  [ ] [ ] [ ] 
					 *  [o] [ ] [ ] */ 
					Red += image[down][left].rgbtRed;
					Green += image[down][left].rgbtGreen;
					Blue += image[down][left].rgbtBlue;
					count++;
				}

				if (right <= width)
				{
					/*  [ ] [ ] [ ]
					 *  [ ] [ ] [ ] 
					 *  [ ] [ ] [o] */ 
					Red += image[down][right].rgbtRed;
					Green += image[down][right].rgbtGreen;
					Blue += image[down][right].rgbtBlue;
					count++;
				}
			}

			/*  [ ] [ ] [ ]
			 *  [ ] [o] [ ] 
			 *  [ ] [ ] [ ] */ 
			Red += image[i][j].rgbtRed;
			Green += image[i][j].rgbtGreen;
			Blue += image[i][j].rgbtBlue;
			count++;

			if (left >= 0)
			{
				/*  [ ] [ ] [ ]
				 *  [o] [ ] [ ] 
				 *  [ ] [ ] [ ] */ 
				Red += image[i][left].rgbtRed;
				Green += image[i][left].rgbtGreen;
				Blue += image[i][left].rgbtBlue;
				count++;
			}

			if (right <= width)
			{
				/*  [ ] [ ] [ ]
				 *  [ ] [ ] [o] 
				 *  [ ] [ ] [ ] */ 
				Red += image[i][right].rgbtRed;
				Green += image[i][right].rgbtGreen;
				Blue += image[i][right].rgbtBlue;
				count++;
			}

			blurred[i][j].rgbtRed = round(Red / count);
			blurred[i][j].rgbtGreen = round(Green / count);
			blurred[i][j].rgbtBlue = round(Blue / count);
		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			image[i][j] = blurred[i][j];
		}
	}

    return;
}
