
#include "gender.h"

void pack_gender(unsigned short int *info, enum Gender gender)
{
	unsigned char value;

	value = gender;
	*info = *info | (value << 15);
}

enum Gender get_gender(unsigned short int info)
{
	if (info >> 15)
		return (FEMALE);
	return (MALE);
}

const char	*gender_to_string(enum Gender gender)
{
	if (gender == FEMALE)
		return ("Женский");
	return ("Мужской");
}
