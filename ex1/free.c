#include "structs.h"
#include <stdlib.h>

void	free_dict(t_word *dict)
{
	t_word	*curr;
	t_word	*next;

	curr = dict;
	while (curr)
	{
		next = curr->next;
		free(curr->value);
		free(curr);
		curr = next;
	}
}
