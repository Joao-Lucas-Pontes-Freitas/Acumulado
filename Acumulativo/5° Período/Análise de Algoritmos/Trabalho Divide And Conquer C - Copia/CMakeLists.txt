cmake_minimum_required(VERSION 3.28)
project(Trabalho_Divide_And_Conquer_C___Copia C)

set(CMAKE_C_STANDARD 11)

# Adiciona todos os arquivos fonte ao mesmo executável
add_executable(Trabalho_Divide_And_Conquer_C___Copia auxiliares.c brutalForce.c divideConquer.c qSort.c main.c )
