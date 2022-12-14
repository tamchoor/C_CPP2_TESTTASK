#include "find_file.h"

/*По реализации с потоками - возникает проблема с переходом в папку с большим объемом 
папок в папке (тестила на директории с 20 папками и 1000 файлами) и начинает ругаться  -fsanitize=address. 
Из-за недостатка времени так и не решила проблему. Но при работе с тестовой директорией dir1 все отрабатывает корректно 
- видимо там что-то со структурой данных
Поэтому прикрепляю еще реализацию без потоков.  */

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

