cmake_minimum_required(VERSION 3.10)
project(Task6 C)

ENABLE_LANGUAGE(ASM_NASM)
set(CMAKE_ASM_NASM_FLAGS "${CMAKE_ASM_NASM_FLAGS} -g -f elf32")
set(CMAKE_ASM_FLAGS "-g -f elf32")
set(CMAKE_CXX_FLAGS -m32)
set(CMAKE_C_FLAGS -m32)
add_executable(Task6 main.c allthemath.c allthemath.h f1.asm f2.asm f3.asm f4.asm f5.asm f6.asm)