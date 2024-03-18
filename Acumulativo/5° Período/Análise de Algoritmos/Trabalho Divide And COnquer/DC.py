from forcaBruta import forcaBruta


def compareX(a, b):
    return (a.x != b.x) * (a.x - b.x) + (a.y - b.y)


def compareY(a, b):
    return (a.y != b.y) * (a.y - b.y) + (a.x - b.x)


def maisProximo(strip, size, d):
    min_dist = d

    for i in range(size):
        for j in range(i + 1, size):
            if (strip[j].y - strip[i].y) < min_dist:
                dist = strip[i].dist(strip[j])
                if dist < min_dist:
                    min_dist = dist

    return min_dist


def menorDistancia(x_ordenados, y_ordenados, n):
    global k
    if n <= 3:
        return forcaBruta(x_ordenados, n)

    metade = n // 2
    mediana = x_ordenados[metade]
    y_esq = [None] * metade
    y_dir = [None] * (n - metade)
    esq_i = dir_i = 0
    for i in range(n):
        if ((y_ordenados[i].x < mediana.x
             or (y_ordenados[i].x == mediana.x
                 and y_ordenados[i].y < mediana.y)) and esq_i < metade):
            y_esq[esq_i] = y_ordenados[i]
            esq_i += 1
        else:
            y_dir[dir_i] = y_ordenados[i]
            dir_i += 1
    #conquistar
    esquerda = menorDistancia(x_ordenados, y_esq, metade)
    direita = menorDistancia(x_ordenados[metade:], y_dir, n - metade)

    #combinar
    menor = esquerda if esquerda < direita else direita

    distancias = [None] * n
    j = 0
    for i in range(n):
        if abs(y_ordenados[i].x - mediana.x) < menor:
            distancias[j] = y_ordenados[i]
            j += 1

    return maisProximo(distancias, j, menor)


def closest(matriz_x, matriz_y, n):
    matriz_x.sort(key=lambda x: x.x)
    matriz_y.sort(key=lambda x: x.y)

    return menorDistancia(matriz_x, matriz_y, n)
