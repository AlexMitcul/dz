#include "educations.h"

void pack_education(unsigned short int *info, enum Education education)
{
	unsigned char	value;

	value = education;
	*info = *info | (value << 13);
}

enum Education get_education(unsigned short int info)
{
	unsigned char	value;

	value = info >> 13;
	value = value ^ 0b100;

	return (value);
}

const char *education_to_string(enum Education education)
{
	if (education == INCOMPLETE_SECONDARY)
		return "Неполное среднее";
	else if (education == SECONDARY)
		return "Среднее";
	else if (education == HIGHER)
		return "Высшее";
	return "Без образования";
}
