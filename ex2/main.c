#include <stdio.h>
#include <stdlib.h>

#include "main.h"

void decimalToBinary(int num)
{
	int binaryNum[16] = {0}; // Assuming 32 bit integer.
	int i=0;
	for ( ;num > 0; ){
		binaryNum[i++] = num % 2;
		num /= 2;
	}
	for (int i = 15; i >= 0; --i)
		printf("%d", binaryNum[i]);
	printf("\n");
}

void print_info(unsigned short int person)
{
	printf("Пол: %s\n", gender_to_string(get_gender(person)));
	printf("\tВозраст: %d\n", get_age(person));
	printf("\tОбразование: %s\n", education_to_string(get_education(person)));
	printf("\tВолосы: %s\n", hair_color_to_string(get_hair_color(person)));
	printf("\tСемейное положение: %s\n", marital_status_to_string(get_marital_status(person)));
	printf("\tЗанятость: %s\n", work_status_to_string(get_work_status(person)));
	printf("\tРост: %s\n", height_to_string(get_height(person)));
}

void	save_person(unsigned short int **persons, int *index, int *max_index,
					unsigned short int person)
{
	unsigned short int	*tmp;

	if (*index == *max_index)
	{
		tmp = realloc(*persons, *max_index * 2);
		free(*persons);
		*persons = tmp;
		*max_index *= 2;
	}
	(*persons)[*index] = person;
	(*index)++;
}

int	main(void)
{
	int	count = 0;
	int	max = 32;
	unsigned short int	*persons;
	unsigned short int	person;

	char	repeat[1] = "1";
	char	gender[1];
	char	age[7];
	char	education[1];
	char	hair_color[1];
	char	marital_status[1];
	char	work_status[1];
	char	height_category[1];

	persons = calloc(max, sizeof(unsigned short int));
	while (*repeat == '1')
	{
		person = 0;
		do
		{
			printf("Введите пол (0 — муж, 1 — жен): ");
			scanf("%s", gender);
		} while (*gender < '0' || *gender > '1');
		pack_gender(&person, atoi(gender));

		printf("Введите возраст: ");
		scanf("%s", age);
		pack_age(&person, atoi(age));

		do
		{
			printf("Введите образование. (0 — нет, 1 — неполное ср., 2 — ср, 3 — выс.): ");
			scanf("%s", education);
		} while (*education < '0' || *education > '3');
		pack_education(&person, atoi(education));
		do
		{
			printf("Введите цвет волос (0 — нет, 1 — чер., 2 — бел, 3 — рыж.): ");
			scanf("%s", hair_color);
		} while (*hair_color < '0' || *hair_color > '3');
		pack_hair_color(&person, atoi(hair_color));

		do
		{
			printf("Введите сем. полож. (0 — не сост., 1 — сост.): ");
			scanf("%s", marital_status);
		} while (*marital_status < '0' || *marital_status > '1');
		pack_marital_status(&person, atoi(marital_status));

		do
		{
			printf("Введите занятость (0 — безработный, 1 — работает): ");
			scanf("%s", work_status);
		} while (*work_status < '0' || *work_status > '1');
		pack_work_status(&person, atoi(work_status));

		do
		{
			printf("Введите рост (0 — <150 см., 1 — 150-170 см., 2 - 170-200 см., 3 - >200 см.): ");
			scanf("%s", height_category);
		} while (*height_category < '0' || *height_category > '3');
		pack_height(&person, atoi(height_category));

		save_person(&persons, &count, &max, person);

		printf("Хотите добавить еще одного человека? [0 — нет, 1 — да]: ");
		scanf("%s", repeat);

	}

	for (int i = 0; i < count; ++i)
	{
		printf("%d)\t", i + 1);
		print_info(persons[i]);
	}

	return (0);
}
