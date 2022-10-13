#include "../find_file.h"

char	*ft_strjoin_path(char const *s1, char const *s2)
{
	char	*dest;
	size_t	lens1;
	size_t	lens2;
	size_t	i;

	if (s1 == 0 || s2 == 0)
		return (0);
	lens1 = strlen(s1);
	lens2 = strlen(s2);
	dest = (char *) calloc((lens1 + lens2 + 1 + 1), sizeof(char));
	if (!dest)
		return (0);
	memcpy(dest, s1, lens1);
	dest[lens1++] = '/';
	i = 0;
	while (lens2 > 0)
	{
		dest[lens1] = s2[i];
		lens2--;
		lens1++;
		i++;
	}
	dest[lens1] = '\0';
	return (dest);
}


int	write_error_and_exit(char *str1, char *str2, char *str3, int flag_perror)
{
	write(2, "ff: ", 4);
	if (str1)
		write(2, str1, strlen(str1));
	if (flag_perror == FLAG_PERROR)
		perror(str2);
	else
	{
		if (str2)
			write(2, str2, strlen(str2));
		if (str3)
			write(2, str3, strlen(str3));
		else
			write(2, "Error.\n", 7);
	}
	exit (1);
}
