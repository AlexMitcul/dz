
#ifndef GENDER_H
#define GENDER_H

enum Gender
{
	MALE,
	FEMALE
};

void		pack_gender(unsigned short int *info, enum Gender gender);
enum		Gender get_gender(unsigned short int info);
const char	*gender_to_string(enum Gender gender);

#endif
