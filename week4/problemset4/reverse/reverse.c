#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

#define HEADER_SIZE 44

bool check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
	if (argc != 3)
	{
		printf("Usage: ./reverse <input.wav> <output.wav>");
		return 1;
	}

    // Open input file for reading
    // TODO #2
	char *infile = argv[1];
	FILE *inptr = fopen(infile, "r");
	if (inptr == NULL)
	{
		printf("Unable to open %s\n", infile);
		return 1;
	}

    // Read header
    // TODO #3
	WAVHEADER header;
	fread(&header, 1, sizeof(WAVHEADER), inptr);

    // Use check_format to ensure WAV format
    // TODO #4
	if (!check_format(header))
	{
		fclose(inptr);
		printf("Invalid file format!\n");
		return 1;
	}
	

    // Open output file for writing
    // TODO #5
	char *outfile = argv[2];
	FILE *outptr = fopen(outfile, "w");
	if (outptr == NULL)
	{
		fclose(inptr);
		printf("Could not create %s\n", outfile);
		return 1;
	}

    // Write header to file
    // TODO #6
	fwrite(&header, 1, sizeof(WAVHEADER), outptr);

    // Use get_block_size to calculate size of block
    // TODO #7
	int block_size = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
	
	// calculate number of bytes of data
	fseek(inptr, 0, SEEK_END);
	long data_size = ftell(inptr) - HEADER_SIZE;

	// inititalize a buffer to store the data
	uint8_t *buffer;
	buffer = malloc(data_size);

	// seek to one block before the end to be read
	fseek(inptr, 0 - block_size, SEEK_END);

	// calculate total blocks of data in file
	int blocks = data_size / block_size;

	// loop through each block, read in reverse and write
	for (int i = 0; i < blocks; i++)
	{
		fread(buffer, 1, block_size, inptr);
		fseek(inptr, -2 * block_size, SEEK_CUR);
		fwrite(buffer, 1, block_size, outptr);
	}

	free(buffer);
	fclose(inptr);
	fclose(outptr);
}

bool check_format(WAVHEADER header)
{
    // TODO #4
	char *format = "WAVE";

	// returns 0 if wav format
	if (memcmp(format, header.format, 4) == 0)
	{
		return true;
	}

    return false;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
	// size is channels * bytes per sample
	int block_size = header.numChannels * header.bitsPerSample/8;
    return block_size;
}
