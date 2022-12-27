#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void decimalToBinary(unsigned char num)
{
	int binaryNum[9] = {0}; // Assuming 8 bit integer.
	int i=0;
	for ( ;num > 0; ){
		binaryNum[i++] = num % 2;
		num /= 2;
	}
	for (int i = 7; i >= 0; --i)
		printf("%d", binaryNum[i]);
	printf("\n");
}

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

void	print_digits(char *digits)
{
	unsigned char	index;
	char			*digit;
	unsigned char codes[11] = {
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
		0b0000000
	};

	for (int line = 0; line < 5; ++line)
	{
		digit = digits;
		while (*digit)
		{
			if (*digit == ' ')
				index = 10;
			else
				index = *digit - '0';
			// printf("%d\n", index);
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
	char	*tmp;

	if (*max == *index)
	{
		tmp = realloc(*digits, *max * 2);
		if (!tmp)
			return ;
		free(*digits);
		*digits = tmp;
		*max *= 2;
	}
	(*digits)[*index] = digit;
	(*index)++;
}

void	debug_print(char *digits)
{
	while (*digits)
	{
		printf("%c", *digits);
		digits++;
	}
	printf("\n");
}

int	main(void)
{
	char	ch;
	int		digits_max_count;
	int		digits_count;
	char	*digits;

	digits_max_count = 10;
	digits_count = 0;
	digits = calloc(digits_max_count, sizeof(char));
	if (!digits)
		return (0);

	printf("Ввод:\n");
	scanf("%c", &ch);
	while (ch != '\n')
	{
		if (ch >= '0' && ch <= '9')
			add_to_digits(&digits, &digits_max_count, &digits_count, ch);
		else if (ch == ' ')
			add_to_digits(&digits, &digits_max_count, &digits_count, ch);
		scanf("%c", &ch);
	}
	printf("Вывод:\n");
	// debug_print(digits);
	print_digits(digits);
	free(digits);
	return (0);
}
