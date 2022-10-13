#include "find_file.h"

int main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0] != '\0')
	{
		if (chdir(argv[1]) == -1)
		{
			write_error_and_exit("main:", argv[1], ": chdir error.\n", FP);
			return 1;
		}
		
		finder();
		return 0;
	}
	write(2, "For call program use finder [start folder name]\n", 48);
	return 1;
}

