#include "word_operations.h"

/**
 * Проверяем есть ли это слово в словаре,
 * если да, увеличиваем количество вхождений на 1
*/
int	word_in_dict(t_dict *dict, char *word)
{
	t_word	*tmp;

	if (dict->word == NULL)
		return (0);
	tmp = dict->word;
	while (tmp)
	{
		if (strcmp(tmp->value, word) == 0)
		{
			tmp->count++;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	push(t_dict *dict, t_word *new)
{
	if (dict == NULL)
		return ;
	if (dict->word == NULL)
		dict->word = new;
	else
	{
		new->next = dict->word;
		dict->word = new;
	}
	new->count++;
}

t_word	*init_new_word_struct(char *new_value)
{
	t_word	*word;

	word = malloc(sizeof(t_word));
	word->count = 0;
	word->next = NULL;
	word->value = strdup(new_value);
	return (word);
}

/**
 * Добавляем новое слово в словарь
*/
void	save_in_dict(t_dict *dict, char *new_word)
{
	t_word	*word;

	if (word_in_dict(dict, new_word))
		return ;
	word = init_new_word_struct(new_word);
	push(dict, word);
}

void	print_dict(t_dict *dict)
{
	t_word	*word;

	word = dict->word;
	while (word)
	{
		printf("%s [ %d ]\n", word->value, word->count);
		word = word->next;
	}
}
