#ifndef FIND_FILE_H
# define FIND_FILE_H

#include <libc.h>
#include <dirent.h>

# define FLAG_PERROR	19
# define FP				19


char		*ft_strjoin_path(char const *s1, char const *s2);
int			write_error_and_exit(char *str1, char *str2, char *str3, int flag_perror);
void		finder();

#endif