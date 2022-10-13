#include "../find_file.h"


void	cycle_through_files(DIR *direct, struct dirent *diren, char *dir)
{
	char *new_dir;

	while (diren != NULL)
	{
		if (diren->d_type == 4 && diren->d_name[0] != '.')
		{
			new_dir = ft_strjoin_path(dir, diren->d_name);
			if (chdir(new_dir) != -1)
			{
				finder();
			}
			else
			{
				write(2, "Can't check dir - ", 17);
				write(2, diren->d_name, strlen(diren->d_name));
			}
			free(new_dir);
		}
		if (diren->d_name[0] != '.')
		{
			write(1, "./", 2);
			write(1, diren->d_name, strlen(diren->d_name));
			write(1, "\n", 1);
		}
		diren = readdir(direct);
	}
}

/* открытие текущей директории для чтения из нее и запуск цикла проверки*/
void finder()
{

	char			*dir;
	DIR				*direct;
	struct dirent	*diren;

	dir = NULL;
	dir = getcwd(dir, PATH_MAX);
	if (dir == NULL)
		write_error_and_exit("searching_in_current_dir:", 0, ": getcwd error.\n", FP);
	direct = opendir(dir);
	diren = readdir(direct);
	cycle_through_files(direct, diren, dir);
	free(dir);
	if (closedir(direct) == -1)
		write_error_and_exit("searching_in_current_dir:", 0, ": closedir error.\n", FP);
}
