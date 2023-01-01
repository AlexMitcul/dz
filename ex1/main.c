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

/**
 * Подсчёт частоты слов.
 *
 * Программа должна считывать текст и дробить его на «слова»
 * (непрерывная последовательность букв и(или) цифр).
 *
 * Формировать из полученного набора слов словарь, содержащий только
 * уникальные слова (дублирований слов в словаре быть не должно).
 *
 * Словарь должен содержать информацию о частоте встречаемости слова
 * (Частота слова = Количество повторений слова в тексте / Общее число слов).
*/

int	main(void)
{
	char	filename[128];
	int		fd;
	int		*symbols_frequency;
	t_info	*info;
	t_word	*dict = 0;


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
	read_file(fd, info, symbols_frequency, &dict);
	close(fd);

	printf("paragraphs: %d\n", info->paragraphs_count);
	printf("sentences: %d\n", info->sentences_count);
	printf("words: %d\n", info->words_count);
	printf("average: %.2f\n", (float)info->words_count / (float)info->sentences_count);

	printf("Частота появления каждого символа.\n");
	char c = 0;
	for (int i = 1; i < 128; ++i)
	{
		if (isalnum(i) || strchr(DELIMETERS, i))
		{
			c++;
			if (i == '\t')
				printf("\\t: %d\t", symbols_frequency[(int)'\t']);
			else if (i == '\n')
				printf("\\n: %d\t", symbols_frequency[(int)'\n']);
			else
				printf("%c: %d\t", i, symbols_frequency[i]);
			if (c % 5 == 0)
				printf("\n");
		}
	}
	printf("\n");

	while (dict)
	{
		printf("%s: %.3f\n", dict->value, (float)dict->repetition / (float)info->words_count);
		dict = dict->next;
	}


	return (0);
}
