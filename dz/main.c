#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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

int	main(void)
{
	char	filename[128];
	int		fd;
	t_info	*info;


	info = malloc(sizeof(t_info));
	info->paragraphs_count = 0;
	info->sentences_count = 0;
	info->words_count = 0;

	printf("Введите путь к файлу:\n");
	scanf("%s", filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Неверный путь к файлу.\n");
		return (0);
	}
	read_file(fd, info);
	close(fd);

	printf("paragraphs: %d\n", info->paragraphs_count);
	printf("sentences: %d\n", info->sentences_count);
	printf("words: %d\n", info->words_count);
	printf("average: %.2f\n", (float)info->words_count / (float)info->sentences_count);
	return (0);
}
