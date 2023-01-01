#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "structs.h"

#include "read.h"
#include "write.h"

// TODO:
/**
 * Программа должна подсчитывать общее
 * - число абзацев,
 * - количество предложений
 * - количество слов в тексте,
 * - среднее количество слов в предложении.
 */

/**
 * Подсчет частоты символов.
 * Программа должна подсчитывать
 * - частоту каждого символа (включая пробелы и разделители) в тексте.
*/

int	main(void)
{
	char	filename[128];
	int		fd;
	int		*symbols_frequency;
	t_info	*info;


	info = malloc(sizeof(t_info));
	info->paragraphs_count = 0;
	info->sentences_count = 0;
	info->words_count = 0;

	symbols_frequency = calloc(128, sizeof(int));

	printf("Введите путь к файлу:\n");
	scanf("%s", filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Неверный путь к файлу.\n");
		return (0);
	}
	read_file(fd, info, symbols_frequency);
	close(fd);

	printf("paragraphs: %d\n", info->paragraphs_count);
	printf("sentences: %d\n", info->sentences_count);
	printf("words: %d\n", info->words_count);
	printf("average: %.2f\n", (float)info->words_count / (float)info->sentences_count);

	printf("Частота появления каждого символа.\n");
	char c = 0;
	for (int i = 0; i < 128; ++i)
	{
		if (isalnum(i) || strchr(DELIMETERS, i))
		{
			c++;
			printf("%c: %d\t", i, symbols_frequency[i]);
			if (c % 5 == 0)
				printf("\n");
		}
	}
	return (0);
}
