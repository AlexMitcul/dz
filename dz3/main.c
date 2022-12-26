#include "main.h"

int main(void)
{
	int		fd;
	t_dict	*dict;
	char	filename[128] = "1.txt";

	// printf("Введите путь к файлу:\n");
	// scanf("%s", filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Неверный путь к файлы.\n");
		return (0);
	}
	dict = malloc(sizeof(t_dict));
	dict->word = NULL;
	read_data(fd, dict);
	close(fd);
	return (0);
}








