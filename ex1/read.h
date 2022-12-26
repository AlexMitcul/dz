#ifndef READ_H
#define READ_H



#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "word_operations.h"
#include "structs.h"

# define DELIM " \t\n.,?!-:;'[]()\""

# define WORD_LEN 128
# define BF_SIZE 1

t_dict	*read_data(int fd);

#endif
