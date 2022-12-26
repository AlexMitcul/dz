
#ifndef WORD_OPERATIONS_H
#define WORD_OPERATIONS_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "structs.h"

void	save_in_dict(t_dict *dict, char *new_word);
void	print_dict(t_dict *dict);

#endif
