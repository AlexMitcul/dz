#ifndef HEIGHT_H
#define HEIGHT_H

enum Height
{
	BELOW_AVG,
	AVG,
	UPPER_AVG,
	GIANT
};

void		pack_height(unsigned short int *info, enum Height height);
enum Height	get_height(unsigned short int info);
const char	*height_to_string(enum Height height);

#endif
