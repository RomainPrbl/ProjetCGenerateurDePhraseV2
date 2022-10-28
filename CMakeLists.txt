cmake_minimum_required(VERSION 3.21)
project(ProjetCGenerateurDePhraseV2 C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjetCGenerateurDePhraseV2 main.c three.c three.h list.c list.h display/displayTxt.h display/displayTxt.c)
