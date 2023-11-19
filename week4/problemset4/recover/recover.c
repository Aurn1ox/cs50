#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512 

typedef uint8_t BYTE;

bool isjpeg(BYTE buffer[]);

int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		printf("Usage: './recover <filename>.raw'\n");
		return 1;
	}

	char *infile = argv[1];

	FILE *inptr = fopen(infile, "r");

	if (inptr == NULL)
	{
		printf("Could not open %s\n", infile);
		return 2;
	}
	
	BYTE buffer[512];

	int count = 0;
	char *outfile;
	FILE *outptr;

	while (fread(buffer, 1, BLOCK_SIZE, inptr) == BLOCK_SIZE)
	{
		// check if jpeg
		// if jpeg:
		// 		create new outfile name and malloc
		// 		write as long as buffer is not jpeg
		// 		if buffer is jpeg:
		// 			break
		if (isjpeg(buffer))
		{

			// free previous file and name
			if (count != 0)
			{
				free(outfile);
				fclose(outptr);
			}

			// allocate memory for filename
			outfile = malloc(8);
			if (outfile == NULL)
			{
				printf("Can't allocate memory for %s\n", outfile);
				fclose(inptr);
				return 3;
			}

			// format outfile name
			sprintf(outfile, "%03d.jpg", ++count);

			// open output file
			outptr = fopen(outfile, "w");
			if (outptr == NULL)
			{
				printf("Unable to open %s\n", outfile);
				fclose(inptr);
				free(outfile);
				return 4;
			}

			fwrite(buffer, 1, BLOCK_SIZE, outptr);
		}

		// write to output file if buffer isnt new jpg
		if (count != 0)
		{
			fwrite(buffer, 1, BLOCK_SIZE, outptr);
		}

	}

	fclose(inptr);
	fclose(outptr);
	free(outfile);
}

bool isjpeg(BYTE buffer[])
{
	BYTE jpeg_signature[3] = {0xff, 0xd8, 0xff};

	if (memcmp(buffer, jpeg_signature, 3) == 0 && (buffer[3] >= 0xe0 && buffer[3] <= 0xff))
	{
		return true;
	}

	return false;
}
