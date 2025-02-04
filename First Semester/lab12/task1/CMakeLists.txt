# Задание: задать имя проекта и версию cmake, добавить subdirectory для background и pipes, в которых 
# тоже есть свои CMakeLists.txt (внутри них тоже нужно добавить одну-две строки для сборки, задание описано в них же)
# Решить проблему с заголовочными файлами, включив директории в корневом CMakeLists.txt (include_directories)
# Слинковать исполняемый файл из src/main.c с библиотекой background
# Все это дело собрать, используя cmake и make
# Для установки cmake нужно установить его: sudo apt install build-essential cmake -y

cmake_minimum_required(VERSION 3.10)

project(programm)

set(SOURCE src/main.c)

include_directories("./background" "./pipes")

add_executable(Main ${SOURCE})

add_subdirectory("./background")
add_subdirectory("./pipes")
target_link_libraries(Main MY_LIB MY_LIB2)

