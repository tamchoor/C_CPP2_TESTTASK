# C_CPP2_TESTTASK


По реализации с потоками - нашла лики, если програма завершается аварийно через exit(), 
хотя выделенная память при этом должна была быть особождена самим exit(). Поэтому прикрепляю еще реализацию 
без потоков и без ликов соотвественно. 








Необходимо на языку программирования C реализовать программу для вывода на консоль всех обнаруженных файлов и каталогов. Программа представляет собой утилиту командной строки, которая запускается следующим образом:

finder  (start folder name)

- finder – имя утилиты

- start folder name – имя каталога с которого начинается поиск.

Вывод содержимого осуществляется, начиная с заданного каталога. Программа должна вывести все дочерние файлы и каталоги, расположенных на всех подуровнях заданного каталога. Количество файлов и подуровней каталогов ничем не ограничено. Пример вывода данных для каталога /etc/X11.

./Xsession.options

./xsm

./xsm/system.xsm

./xkb

./Xreset.d

./Xreset.d/README

./default-display-manager

./Xsession.d

./Xsession.d/75dbus_dbus-launch

./Xsession.d/90gpg-agent

./Xsession.d/55gnome-session_gnomerc

./Xsession.d/60x11-common_localhost

./Xsession.d/35x11-common_xhost-local

./Xsession.d/90x11-common_ssh-agent

./Xsession.d/50x11-common_determine-startup

./Xsession.d/40x11-common_xsessionrc

./Xsession.d/30x11-common_xresources

./Xsession.d/60xbrlapi

./Xsession.d/70im-config_launch

./Xsession.d/20x11-common_process-args

./Xsession.d/99x11-common_start

./Xsession.d/90qt-a11y

./Xsession.d/90atk-adaptor

./Xsession.d/20dbus_xdg-runtime

./Xsession.d/95dbus_update-activation-env

./Xsession.d/60x11-common_xdg_path

./rgb.txt

 

Если имя каталога не задано, то программа должны вывести сообщение об ошибке и завершиться.

Использование сторонних утилит (find, grep и т.п.)  для формирования потока вывода не допускается. Не допускается использование семейства библиотек boost.

Возможно использование библиотек для работы со строками, файловой системой (за исключение nftw), потоками и т.п. В качестве системы сборки желательно использовать CMake.

Желательно включить в проект unit tests. Возможно использование любого знакомого\удобного фреймворка тестирования (Например, gtest, gmock и т.п.).

Прислать код необходимо в файле *.с

Не забудьте подписать файл в формате "Разработка C и C++_Тестовое задание_Фамилия Имя".

