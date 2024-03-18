# import time
# from forcaBruta import forcaBruta
# from DC import closest
# from ponto import Ponto
# import random
# from tabulate import tabulate
#
#
# def gerarPontos(n):
#     pontos = []
#     set_x = set()
#
#     limite_inf, limite_sup = -1 * n * 2, n * 2
#     while len(pontos) < n:
#         x, y = random.randint(limite_inf, limite_sup), random.randint(limite_inf, limite_sup)
#         if x in set_x:
#             continue
#         set_x.add(x)
#         pontos.append(Ponto(x, y))
#
#     return pontos
#
#
# if __name__ == '__main__':
#     sementes = [1000000]
#     resultados = []
#
#     for semente in sementes:
#         pontos = gerarPontos(semente)
#         print("gerado")
#         pontos_y = [ponto for ponto in pontos]
#
#         start_time = time.perf_counter()
#         dist = closest(pontos, pontos_y, semente)
#         dc_time = time.perf_counter() - start_time
#
#         # start_time = time.perf_counter()
#         # bf_dist = forcaBruta(pontos, semente)
#         # bf_time = time.perf_counter() - start_time
#
#         resultados.append([semente, 0, dist, dc_time])
#         print(semente)
#
#     # Cabeçalhos coloridos
#     cabecalho = [
#         "\033[1;35mNúmero de Pontos\033[0m",
#         "\033[1;31mBrutalForce\033[0m",
#         "\033[1;33mDistância\033[0m",
#         "\033[1;32mDivide And Conquer\033[0m"
#     ]
#
#     # Imprime a tabela com texto centralizado
#     print(tabulate(resultados, headers=cabecalho, tablefmt="grid", stralign="center"))
#
#
#
#

import math
from fractions import Fraction


def numerador(fracao):
    return Fraction(fracao).limit_denominator().numerator


def denominador(fracao):
    return Fraction(fracao).limit_denominator().denominator


def cacluar_somatorio(N, xn):
    expressao = "X_k &= \\frac{1}{N}\sum_{n=0}^{N-1}{y_n[cos(k\\frac{2\pi}{N}n)]} \\\\"

    # Imprimindo a expressão
    print(expressao)

    coeficientes = N * []
    indices = N * []

    for k in range(N):
        indices.append(k)
        expressao = f"X_{{{k}}} &= \\frac{{1}}{{{N}}}\pi \left["
        soma_real = 0
        for n in range(N):
            soma_real += math.cos(2 * math.pi * k * n / N) * xn[n]

            if n != N - 1:
                expressao += (f"\\frac{{{numerador(xn[n])}}}{{{denominador(xn[n])}}}"
                              f"\\cos\left({k}\\frac{{2\\pi}}{{{N}}}{n}\\right) + ")
            else:
                expressao += (f"\\frac{{{numerador(xn[n])}}}{{{denominador(xn[n])}}}"
                              f"\\cos\left({k}\\frac{{2\\pi}}{{{N}}}{n}\\right)\\right] ")

        print(expressao, end="")

        soma_real /= N
        coeficientes.append(soma_real)
        print(f" = \\frac{{{numerador(soma_real)}}}{{{denominador(soma_real)}}}\pi \\\\")

    funcao = "p(t) = "

    for i in range(N):
        if i == N - 1:
            funcao += f"\\frac{{{numerador(coeficientes[i])}}}{{{denominador(coeficientes[i])}}}\pi\\cos\left({indices[i]}t\\right)"
        else:
            funcao += f"\\frac{{{numerador(coeficientes[i])}}}{{{denominador(coeficientes[i])}}}\pi\\cos\left({indices[i]}t\\right) + "

    print(funcao)


def calcular_somatorio_alasing(N, yn):
    # Expressão matemática
    expressao = "X_k &= \\frac{1}{N}\sum_{n=0}^{N-1}{y_n[cos(k\\frac{2\pi}{N}n)]} \\\\"

    # Imprimindo a expressão
    print(expressao)

    coeficientes = N * []
    indices = N * []

    for k in range(-N // 2, N // 2):
        indices.append(k)
        expressao = f"X_{{{k}}} &= \\frac{{1}}{{{N}}}\pi\left["
        soma_real = 0
        for n in range(N):
            soma_real += math.cos(2 * math.pi * k * n / N) * yn[n]

            if n != N - 1:
                expressao += (f"\\frac{{{numerador(yn[n])}}}{{{denominador(yn[n])}}}"
                              f"\\cos\left({k}\\frac{{2\\pi}}{{{N}}}{n}\\right) + ")
            else:
                expressao += (f"\\frac{{{numerador(yn[n])}}}{{{denominador(yn[n])}}}"
                              f"\\cos\left({k}\\frac{{2\\pi}}{{{N}}}{n}\\right)\\right] ")

        print(expressao, end="")

        soma_real /= N
        coeficientes.append(soma_real)
        print(f" = \\frac{{{numerador(soma_real)}}}{{{denominador(soma_real)}}}\pi \\\\")

    funcao = "p(t) = "

    for i in range(N):
        if i == N - 1:
            funcao += f"\\frac{{{numerador(coeficientes[i])}}}{{{denominador(coeficientes[i])}}}\pi\\cos\left({indices[i]}t\\right)"
        else:
            funcao += f"\\frac{{{numerador(coeficientes[i])}}}{{{denominador(coeficientes[i])}}}\pi\\cos\left({indices[i]}t\\right) + "

    print(funcao)


def gerarValores(a, b, N):
    intervalo = (a + b) / N
    lista = [] * N
    for i in range(N):
        lista.append(2 * a - pow(a, 2))
        a += intervalo
    return lista


N = 4
a = 0
b = 2
# yn = gerarValores(0, 2, N) # ou vc enche os valores que vc já tem sem o pi
yn = [0, 3/5, 9/5, 3/5]
print(yn)
cacluar_somatorio(N, yn)
calcular_somatorio_alasing(N, yn)
