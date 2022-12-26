#ifndef EDUCATION_H
#define EDUCATION_H

enum Education
{
	NONE,
	INCOMPLETE_SECONDARY,
	SECONDARY,
	HIGHER
};

void			pack_education(unsigned short int *info, enum Education education);
enum Education	get_education(unsigned short int info);
const char		*education_to_string(enum Education education);

#endif
