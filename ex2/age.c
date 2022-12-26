#include "age.h"

#include <stdio.h>

// void decimalToBinary(int num)
// {
// 	int binaryNum[16] = {0}; // Assuming 32 bit integer.
// 	int i=0;
// 	for ( ;num > 0; ){
// 		binaryNum[i++] = num % 2;
// 		num /= 2;
// 	}
// 	for (int i = 15; i >= 0; --i)
// 		printf("%d", binaryNum[i]);
// 	printf("\n");
// }

void pack_age(unsigned short int *info, unsigned char age)
{

	// decimalToBinary(*info);
	*info = *info | age;
	// decimalToBinary(*info);

}

unsigned char get_age(unsigned short int info)
{
	unsigned short int	value;

	// decimalToBinary(info);
	value = info & 0b1111111;
	// decimalToBinary(value);

	return value;
}
