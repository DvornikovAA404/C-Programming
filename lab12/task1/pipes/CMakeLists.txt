# Задание: Создать библиотеку pipes из read_pipe.c write_pipe.c

set(SOURCE_LIB read_pipe.c write_pipe.c)	
add_library(MY_LIB2 SHARED ${SOURCE_LIB})	# Создание дин. библиотеки с именем MY_LIB