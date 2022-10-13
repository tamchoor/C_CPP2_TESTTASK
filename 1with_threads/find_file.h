#ifndef FIND_FILE_H
# define FIND_FILE_H

#include <libc.h>
#include <dirent.h>
# include <pthread.h>

# define FLAG_PERROR	19
# define FP				19

typedef struct s_threads
{
	pthread_t			thread;
	pthread_mutex_t		*block;
	char				*dir;
	struct s_threads	*next;
} t_threads;


typedef struct s_info
{
	t_threads			*thread;
	char				*dir;
	pthread_mutex_t		block;
	pthread_mutex_t		block_forfree;

} t_info;


/* utils.c */

char		*ft_strjoin_path(char const *s1, char const *s2);
int			write_error_and_exit(char *str1, char *str2, char *str3, int flag_perror);
void	finder(char *dir);

#endif