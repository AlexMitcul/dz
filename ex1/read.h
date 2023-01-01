#ifndef READ_H
#define READ_H

#include <unistd.h>
#include <string.h>

#include "structs.h"

void	read_file(int fd, t_info *info, int *sf);

#endif
