#include "write.h"

void	write_result(t_info *info, t_word *dict, int *symbols_frequency)
{
	FILE	*fd;

	fd = fopen("result.txt", "w");
	fprintf(fd, "paragraphs: %d\n", info->paragraphs_count);
	fprintf(fd, "sentences: %d\n", info->sentences_count);
	fprintf(fd, "words: %d\n", info->words_count);
	fprintf(fd, "average: %.2f\n", (float)info->words_count / (float)info->sentences_count);

	fprintf(fd, "Частота появления каждого символа.\n");
	char c = 0;
	for (int i = 1; i < 128; ++i)
	{
		if (isalnum(i) || strchr(DELIMETERS, i))
		{
			c++;
			if (i == '\t')
				fprintf(fd, "\\t: %d\t", symbols_frequency[(int)'\t']);
			else if (i == '\n')
				fprintf(fd, "\\n: %d\t", symbols_frequency[(int)'\n']);
			else
				fprintf(fd, "%c: %d\t", i, symbols_frequency[i]);
			if (c % 5 == 0)
				fprintf(fd, "\n");
		}
	}
	fprintf(fd, "\n");

	while (dict)
	{
		fprintf(fd, "%s: %.3f\n", dict->value, (float)dict->repetition / (float)info->words_count);
		dict = dict->next;
	}
}
