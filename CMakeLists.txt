cmake_minimum_required(VERSION 3.10)
project(book_mgr_20181220 C)

set(CMAKE_C_STANDARD 99)

add_executable(book_mgr_20181220 main.c model/book_model.h model/book_model.c ui/menu.c ui/menu.h model/test.c)