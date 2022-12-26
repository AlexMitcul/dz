#include "work_status.h"

void	pack_work_status(unsigned short int *info, enum WorkStatus status)
{
	unsigned char	value;

	value = status;
	*info = *info | (value << 9);
}

enum WorkStatus	get_work_status(unsigned short int info)
{
	int value;

	value = info >> 10;
	value = value & 0b1;

	return (value);
}

const char	*work_status_to_string(enum WorkStatus status)
{
	if (status == EMPLOYED)
		return ("Работает");
	return ("Безработный");
}
