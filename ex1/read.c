#include "read.h"

/**
 * Добавляем новый символ в конец нового слова
*/
static void	join(char **word, char new_character)
{
	char	*end_of_word;

	end_of_word = *word;
	while (*end_of_word)
		end_of_word++;
	*end_of_word = new_character;
}

static void	print_text_info(t_text_info *text_info)
{
	printf("=== Text info ===\n");
	printf("characters_count: %d\n", text_info->characters_count);
	printf("words count: %d\n", text_info->words_count);
	printf("paragraph_count: %d\n", text_info->paragraph_count);
	printf("sentences_count: %d\n", text_info->sentences_count);
}

t_dict	*init_dict();
void	add_to_dict(t_dict *dict, char *new_word);

t_dict	*read_data(int fd)
{
	char		bf[1];
	char		word[32];
	t_dict		*dict;
	t_text_info	text_info = {0};
	int			flag;

	dict = init_dict();
	while (read(fd, bf, 1) > 0)
	{
		text_info.characters_count++;
		if (strchr(DELIM, bf[0]) != NULL)
		{
			if (flag == 1)
				text_info.words_count++;
			flag = 0;
			if (bf[0] == '\n')
				text_info.paragraph_count++;
			else if (bf[0] == '.' || bf[0] == '!' || bf[0] == '?')
				text_info.sentences_count++;
			add_to_dict(dict, word);
			bzero(word, 32);
		}
		else
		{
			join(&word, bf[0]);
		}
	}
}
