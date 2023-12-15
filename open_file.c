#include "monty.h"

/**
 * open_file - a function that reads a given
 * bytecode file.
 * @filename: bytecode filename
 *
 * Return: nothing
 */
void open_file(char *filename)
{
	FILE *fp;
	char *opcode, *data;
	const char *delim = "\n ";
	unsigned int line_number = 0;
	char *buffer = NULL;
	size_t len = 0;

	fp = fopen(filename, "r");
	if (!fp || !filename)
		print_err(2, filename);

	while (getline(&buffer, &len, fp) != -1)
	{
		line_number++;
		if (!buffer)
			print_err(4);

		opcode = strtok(buffer, delim);
		data = strtok(NULL, delim);

		if (!opcode)
			continue;

		op_handler(opcode, data, line_number);
	}
	fclose(fp);
	free(buffer);
}
