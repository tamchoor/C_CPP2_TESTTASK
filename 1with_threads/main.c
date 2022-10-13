#include "find_file.h"

int main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0] != '\0')
	{
		finder(argv[1]);
		return 0;
	}
	write(2, "For call program use finder [start folder name]\n", 48);
	return 1;
}

