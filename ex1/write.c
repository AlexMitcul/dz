#include "write.h"

/**
 * Программа должна:
 * - количество слов в тексте.
 * - количество предложений.
 * - среднее количество слов в предложении.
 * - подсчитывать общее число абзацев.
*/
void	write_description(int fd, t_text_info *text_info)
{
	fprintf(fd, "Отчет по тексту:\n");
	fprintf(fd, "Количество слов: %d\n", text_info->words_count);
	fprintf(fd, "Количество предложений: %d\n", text_info->sentences_count);
	fprintf(fd, "Среднее количество слов в предложении: %.2f\n",
		(float) text_info->words_count / (float) text_info->sentences_count);
	fprintf(fd, "Количество абзацев: %d\n", text_info->paragraph_count);

}

void	write_to_file(t_text_info *text_info, t_dict *dict)
{
	int	fd;

	fd = open("result.txt", O_RDWR);
	write_description(fd, text_info);
	// write_dict(dict);
}
