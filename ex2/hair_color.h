#ifndef HAIR_COLOR_H
#define HAIR_COLOR_H

enum HairColor
{
	NO_HAIR,
	BLACK,
	WHITE,
	REDHAIR
};

void			pack_hair_color(unsigned short int *info, enum HairColor color);
enum HairColor	get_hair_color(unsigned short int info);
const char		*hair_color_to_string(enum HairColor color);

#endif
