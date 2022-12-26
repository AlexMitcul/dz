#include "age.h"

#include <stdio.h>

void pack_age(unsigned short int *info, unsigned char age)
{
	*info = *info | age;
}

unsigned char get_age(unsigned short int info)
{
	unsigned short int	value;

	value = info & 0b1111111;
	return value;
}
