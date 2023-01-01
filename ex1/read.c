#include "read.h"


void	read_file(int fd, t_info *info, int *sf)
{
	char	bf[1];
	char	flag;

	flag = 0;
	while (read(fd, bf, 1) > 0)
	{
		sf[*bf]++;
		if (strrchr(DELIMETERS, *bf) == 0)
			flag = 1;
		else
		{
			if (flag)
				info->words_count++;
			flag = 0;
			if (*bf == '.' || *bf == '!' || *bf == '?')
				info->sentences_count++;
			else if (*bf == '\n')
				info->paragraphs_count++;
		}
	}
}
