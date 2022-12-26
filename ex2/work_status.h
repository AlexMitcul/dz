#ifndef WORK_STATUS_H
#define WORK_STATUS_H

enum WorkStatus
{
	UNEMPLOYED,
	EMPLOYED
};

void			pack_work_status(unsigned short int *info, enum WorkStatus status);
enum WorkStatus	get_work_status(unsigned short int info);
const char		*work_status_to_string(enum WorkStatus status);


#endif
