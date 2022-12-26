#ifndef MARITAL_STATUS_H
#define MARITAL_STATUS_H

enum MaritalStatus
{
	UNMARRIED,
	MARRIED
};

void				pack_marital_status(unsigned short int *info, enum MaritalStatus status);
enum MaritalStatus	get_marital_status(unsigned short int info);
const char			*marital_status_to_string(enum MaritalStatus status);

#endif
