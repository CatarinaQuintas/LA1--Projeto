cmake_minimum_required(VERSION 3.15)
project(lab1 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab1 main.c dados/dados.c dados/dados.h interface/interface.c interface/interface.h logica/logica.c logica/logica.h logica/lista.c logica/lista.h)