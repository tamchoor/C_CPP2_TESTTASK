#include "find_file.h"

void *searching_in_current_dir();

void	cycle_through_files(DIR *direct, struct dirent *diren, char *dir, t_info *info)
{
	char *new_dir;
	t_threads *current_thread = info->thread;

	if (current_thread)
	{
		while (current_thread->next)
			current_thread = current_thread->next;
		current_thread->next = (t_threads *)calloc(1, sizeof(t_threads));
		if (!current_thread->next)
		{
			write_error_and_exit("cycle_through_files:", 0, ": calloc error.\n", FP);
		}
		current_thread = current_thread->next;
	}
	else
	{
		current_thread = (t_threads *)calloc(1, sizeof(t_threads));
		if (!current_thread)
		{
			write_error_and_exit("cycle_through_files:", 0, ": calloc error.\n", FP);
		}
	}
	current_thread->block = &info->block;
	current_thread->next = NULL;

	while (diren != NULL)
	{
		if (diren->d_type == 4 && diren->d_name[0] != '.')
		{
			new_dir = ft_strjoin_path(dir, diren->d_name);
			// if (chdir(new_dir) != -1)
			// {
			// 	searching_in_current_dir(info);
			// }
			// else
			// {
			// 	write(2, "Can't check dir - ", 17);
			// 	write(2, diren->d_name, strlen(diren->d_name));
			// }
			current_thread->dir = new_dir;
			if (pthread_create(&current_thread->thread, NULL, searching_in_current_dir, (info)) != 0)
			{
				write_error_and_exit("cycle_through_files:", 0, ": pthread_creat error.\n", FP);
			}
			pthread_mutex_lock(&info->block_forfree);
			// free(new_dir);
		}
		if (diren->d_name[0] != '.')
		{
			pthread_mutex_lock(&info->block);
			write(1, "./", 2);
			write(1, diren->d_name, strlen(diren->d_name));
			write(1, "\n", 1);
			pthread_mutex_unlock(&info->block);
		}
		diren = readdir(direct);
	}
	pthread_join (current_thread->thread, NULL);
}

/* открытие текущей директории для чтения из нее и запуск цикла проверки*/
void *searching_in_current_dir(void *info1)
{
	t_info *info = (t_info *)info1;
	t_threads *current_thread = info->thread;

	char			*dir;
	DIR				*direct;
	struct dirent	*diren;

	if (!info->thread)
	{
		if (chdir(info->dir) == -1)
		{
			write_error_and_exit("main:", info->dir, ": chdir error.\n", FP);
		}
	}
	else 
	{
		while (current_thread->next)
			current_thread = current_thread->next;
		if (chdir(current_thread->dir) == -1)
		{
			write_error_and_exit("main:", current_thread->dir, ": chdir error.\n", FP);
		}
	}
	dir = NULL;
	dir = getcwd(dir, PATH_MAX);
	if (dir == NULL)
		write_error_and_exit("searching_in_current_dir:", 0, ": getcwd error.\n", FP);
	direct = opendir(dir);
	diren = readdir(direct);
	pthread_mutex_unlock(&info->block_forfree);
	cycle_through_files(direct, diren, dir, info);
	free(dir);
	if (closedir(direct) == -1)
		write_error_and_exit("searching_in_current_dir:", 0, ": closedir error.\n", FP);
	return ((void *) 0);
}

void	finder(char *dir)
{
	t_info info;

	if (pthread_mutex_init(&info.block, NULL) != 0)
	{
		write_error_and_exit("finder:", 0, ": pthread_mutex_init error.\n", FP);
	}
	if (pthread_mutex_init(&info.block_forfree, NULL) != 0)
	{
		write_error_and_exit("finder:", 0, ": pthread_mutex_init error.\n", FP);
	}
	info.thread = NULL;
	info.dir = dir;
	pthread_mutex_lock(&info.block_forfree);
	searching_in_current_dir(&info);
	pthread_mutex_destroy(&info.block);
	pthread_mutex_destroy(&info.block_forfree);

	t_threads *first = info.thread;

	while (first)
	{
		info.thread = info.thread->next;
		free(first->dir);
		free(first);
		first = info.thread;
	}
}
