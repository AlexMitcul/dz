#include "marital_status.h"

void	pack_marital_status(unsigned short int *info, enum MaritalStatus status)
{
	unsigned char	value;

	value = status;
	*info = *info | (value << 10);
}

enum MaritalStatus	get_marital_status(unsigned short int info)
{
	int value;

	value = info >> 10;
	value = value & 0b1;

	return (value);
}

const char	*marital_status_to_string(enum MaritalStatus status)
{
	if (status == MARRIED)
		return ("Состоит в браке");
	return ("Не состоит в браке");
}
