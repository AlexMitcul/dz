#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_horizontal_symbols(unsigned char code, int line)
{
	unsigned char	value;

	if (line == 0)
		value = code >> 6;
	else if (line == 2)
		value = code >> 3 & 0b1;
	else if (line == 4)
		value = code & 0b1;
	if (value)
		write(STDOUT_FILENO, " - ", 3);
	else
		write(STDOUT_FILENO, "   ", 3);
}

void	print_vertical_symbols(unsigned char code, int line)
{
	unsigned char	value;

	if (line == 1)
		value = code >> 4 & 0b11;
	else if (line == 3)
		value = code >> 1 & 0b11;
	if (value == 1)
		write(STDOUT_FILENO, "  |", 3);
	else if (value == 2)
		write(STDOUT_FILENO, "|  ", 3);
	else if (value == 3)
		write(STDOUT_FILENO, "| |", 3);
	else
		write(STDOUT_FILENO, "   ", 3);
}

/**
 * 0b1234567
 *
 * 		1
 * 	2		3
 * 		4
 *	5		6
 * 		7
*/

void	print_digits(char *digits)
{
	unsigned char	index;
	char			*digit;
	unsigned char codes[12] = {
		0b1110111,
		0b0010010,
		0b1011101,
		0b1011011,
		0b0111010,
		0b1101011,
		0b1101111,
		0b1010010,
		0b1111111,
		0b1111011,
		0b0000000,
		0b0001000
	};

	for (int line = 0; line < 5; ++line)
	{
		digit = digits;
		while (*digit)
		{
			if (*digit == ' ')
				index = 10;
			else if (*digit == '-')
				index = 11;
			else
				index = *digit - '0';
			if (line % 2 == 0)
				print_horizontal_symbols(codes[index], line);
			else
				print_vertical_symbols(codes[index], line);
			digit++;
		}
		write(STDOUT_FILENO, "\n", 1);
	}
}

void	add_to_digits(char **digits, int *max, int *index, char digit)
{
	if (*max == *index)
	{
		*digits = realloc(*digits, *max * 2);
		*max *= 2;
	}
	(*digits)[*index] = digit;
	(*index)++;
}

int	main(void)
{
	char	ch;
	int		digits_max_count;
	int		digits_count;
	char	*digits = NULL;
	char	minus;

	digits_max_count = 32;
	digits_count = 0;
	digits = calloc(digits_max_count, sizeof(char));
	minus = 0;

	printf("Ввод:\n");
	scanf("%c", &ch);
	while (ch != '\n')
	{
		if (ch == '-')
			minus = 1;
		else
		{
			if (ch >= '0' && ch <= '9')
			{
				if (minus)
					add_to_digits(&digits, &digits_max_count, &digits_count, '-');
				add_to_digits(&digits, &digits_max_count, &digits_count, ch);
			}
			else if (ch == ' ')
				add_to_digits(&digits, &digits_max_count, &digits_count, ch);
			minus = 0;
		}
		scanf("%c", &ch);
	}
	printf("Вывод:\n");
	print_digits(digits);
	free(digits);
	return (0);
}
