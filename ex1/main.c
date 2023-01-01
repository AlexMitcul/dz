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

/**
 * Сохранение результатов в файл.
 * Всю собранную информацию программа должна сохранять в файл-результат.
*/

void	free_dict(t_word *dict);

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

	do
	{
		printf("Введите путь к файлу: [Для выхода введите 'выход']\n");
		scanf("%s", filename);
		if (strcmp(filename, "выход") == 0)
			break;
		fd = open(filename, O_RDONLY);
		if (fd < 0)
			printf("Неверный путь к файлу.\n");
		else
		{
			read_file(fd, info, symbols_frequency, &dict);
			close(fd);
		}
		bzero(filename, 128);
	} while (1);
	write_result(info, dict, symbols_frequency);
	free_dict(dict);
	free(info);
	free(symbols_frequency);
	return (0);
}
