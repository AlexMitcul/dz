
#include <stdlib.h>
#include <string.h>
#include "structs.h"


t_dict	*init_dict()
{
	t_dict	*dict;

	dict = malloc(sizeof(t_dict));
	if (!dict)
		return (NULL);
	dict->words = malloc(64 * sizeof(t_word));
	dict->length = 64;
	dict->words = 0;
	return (dict);
}

void	extend_dict(t_dict *dict)
{
	int	new_size;

	new_size = dict->length * 2;
	dict->words = realloc(dict->words, new_size);
	dict->length = new_size;
}

int	cmpf(const void *a, const void *b)
{
	t_word	*word_a, *word_b;
	int		cmp_res;

	word_a = (t_word *)a;
	word_b = (t_word *)b;

	cmp_res = strcmp(word_a->value, word_b->value);
	return (cmp_res);
}

int	find_word_in_dict(t_dict *dict, t_word *to_find)
{
	t_word	*p;
	int		index;

	p = bsearch(to_find, dict->words, dict->words, sizeof(t_word), cmpf);
	index = (p - dict->word) / sizeof(t_word);

	return (index);
}

void	shift(t_dict *dict, int index)
{
	// shift all elements to right by 1
}

void	add_to_dict(t_dict *dict, char *new_word)
{
	int		index;
	t_word	*word;

	if (dict->length == dict->words)
		extend_dict(&dict);

	index = find_word_in_dict(dict);
	shift(dict, index);
	(dict->word) + index * sizeof(t_word) = word;
}
