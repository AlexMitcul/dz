#include "hair_color.h"

void	pack_hair_color(unsigned short int *info, enum HairColor color)
{
	unsigned char	value;

	value = color;
	*info = *info | (value << 11);
}

enum HairColor	get_hair_color(unsigned short int info)
{
	unsigned char	value;

	value = info >> 11;
	value = value & 0b11;

	return (value);
}

const char	*hair_color_to_string(enum HairColor color)
{
	if (color == BLACK)
		return "Черный";
	else if (color == WHITE)
		return "Белый";
	else if (color == REDHAIR)
		return "Рыжий";
	return "Нет волос";
}
