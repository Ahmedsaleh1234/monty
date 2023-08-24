#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *buf;
	FILE *f;
	size_t s = 0;
	ssize_t line = 1;
	stack_t *top = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	bus.file = f;
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line > 0)
	{
		buf = NULL;
		line = getline(&buf, &s, f);
		bus.content = buf;
		count++;
		if (line > 0)
		{
			ex_monty(buf, &top, count, f);
		}
		free(buf);
	}
	free(top);
	fclose(f);
return (0);
}
int ex_monty(char *buf, stack_t **top, unsigned int count, FILE *f)
{
	instruction_t opcodes[] = {
				{"push", push},
				{"pall", pall},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *opcode;

	opcode = strtok(buf, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opcodes[i].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{	opcodes[i].f(top, count);
			return (0);
		}
		i++;
	}
	if (opcode && opcodes[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, opcode);
		fclose(f);
		free(buf);
		free(*top);
		exit(EXIT_FAILURE); }
	return (1);
}
