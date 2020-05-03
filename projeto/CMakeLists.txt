cmake_minimum_required(VERSION 3.15)
project(rastros)

set(CMAKE_CXX_STANDARD 14)

include_directories(dados)
include_directories(interface)
include_directories(listas)
include_directories(logica)

add_executable(projeto
    dados/dados.c
    dados/dados.h
    interface/interface.c
    interface/interface.h
    listas/listas.c
    listas/listas.h
    logica/logica.c
    logica/logica.h
    main.c
    )

