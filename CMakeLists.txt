cmake_minimum_required(VERSION 3.10)
project(book_mgr_20181220 C)

set(CMAKE_C_STANDARD 99)

add_executable(book_mgr_20181220 main.c util/list_util.h util/list_util.c ui/menu.c ui/menu.h util/rw_util.h util/rw_util.c util/rw_util.c util/rw_util.h)