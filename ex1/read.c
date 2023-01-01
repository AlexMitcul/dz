#include "read.h"

void	add_symbol(char **word, char new_symbol)
{
	char	*tmp;

	tmp = *word;
	while (*tmp)
		tmp++;
	*tmp = new_symbol;
}

void	add_word_to_dict(t_word **dict, char *word)
{
	t_word	*new_word;
	t_word	*it;

	it = *dict;
	while (it)
	{
		if (strcmp(it->value, word) == 0)
		{
			it->repetition++;
			return ;
		}
		it = it->next;
	}

	new_word = malloc(sizeof(t_word));
	new_word->repetition = 1;
	new_word->value = strdup(word);
	new_word->next = NULL;
	if (*dict == NULL)
		*dict = new_word;
	else
	{
		new_word->next = *dict;
		*dict = new_word;
	}
}

void	read_file(int fd, t_info *info, int *sf, t_word **dict)
{
	char	bf[1];
	char	flag;
	char	*word;

	flag = 0;
	word = calloc(32, sizeof(char));
	while (read(fd, bf, 1) > 0)
	{
		sf[*bf]++;
		if (isalnum(*bf))
		{
			add_symbol(&word, *bf);
			flag = 1;
		}
		else if (strchr(DELIMETERS, *bf))
		{
			if (flag)
			{
				info->words_count++;
				add_word_to_dict(dict, word);
			}
			if (*bf == '.' || *bf == '!' || *bf == '?')
				info->sentences_count++;
			else if (*bf == '\n')
				info->paragraphs_count++;
			flag = 0;
			bzero(word, 32);
		}
	}
}
