#include "main.h"

int main(void)
{
	int		fd;
	char	filename[128] = {0};
	char	*option = NULL;
	t_dict	*dict;
	char	*word_to_find[32];
	t_word	*word;

	printf("Обработать файл - 0\nПоиск слова - 1\n");
	do
	{
		if (*option == '0')
		{
			printf("Введите путь к файлу\n");
			scanf("%s", filename);
			fd = open(filename, O_RDONLY);
			if (fd < 0)
				printf("Неверный путь к файлу.\n");
			else
			{
				dict = read_data(fd);
				close(fd);
			}
		}
	} while (*option == '0' || *option == '1');
	// free_dict(dict);
	return (0);
}








