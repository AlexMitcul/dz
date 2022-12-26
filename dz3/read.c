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

void	read_data(int fd, t_dict *dict)
{
	int			character_frequency[128] = {0};
	char		bf[BF_SIZE];
	char		*word;
	int			flag;
	t_text_info	text_info = {0};

	word = (char *)calloc(WORD_LEN, sizeof(char));
	// Ошибка выделения памяти
	if (word == NULL)
		return ;
	// Считываем посимволь весь файл
	flag = 0;
	while (read(fd, bf, BF_SIZE) > 0)
	{
		text_info.characters_count++;
		character_frequency[bf[0]]++;
		// Нашли знак препинания
		if (strchr(DELIM, bf[0]) != NULL)
		{
			if (flag == 1)
				text_info.words_count++;
			flag = 0;
			if (bf[0] == '\n')
				text_info.paragraph_count++;
			else if (bf[0] == '.' || bf[0] == '!' || bf[0] == '?')
				text_info.sentences_count++;
			save_in_dict(dict, word);
			bzero(word, WORD_LEN);
		}
		else
		{
			flag = 1;
			join(&word, bf[0]);
		}
	}
	print_text_info(&text_info);
	// print_dict(dict);
}
