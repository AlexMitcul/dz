#include "height.h"

void		pack_height(unsigned short int *info, enum Height height)
{
	unsigned char	value;

	value = height;
	*info = *info | value << 7;
}

enum Height	get_height(unsigned short int info)
{
	unsigned char	value;

	value = info >> 7;
	value = value & 0b11;

	return (value);
}

const char	*height_to_string(enum Height height)
{
	if (height == GIANT)
		return (">200");
	else if (height == UPPER_AVG)
		return ("170-200");
	else if (height == AVG)
		return ("150-170");
	return ("<150");
}
