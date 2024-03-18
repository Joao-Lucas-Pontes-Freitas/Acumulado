import math
import sys


# Função para calcular distância com base nas coordenadas de dois pontos
def dist(x1, y1, x2, y2):
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)


# Função para achar o pai de um vértice (estrutura union-find)
def find(u, parent):
    if u == parent[u]:
        return u
    parent[u] = find(parent[u], parent)
    return parent[u]


# Função para unir dois vértices por meio da união de seus pais (estrutura union-find)
def union(u, v, parent):
    u = find(u, parent)
    v = find(v, parent)
    if u == v:
        return
    parent[u] = v


# Função do algoritmo de kruskal que acha a árvore mínima utilizando a estrutura union-find
def kruskal(n, lista):
    # Inicia o vetor com os pais de cada vértice sendo o próprio vértice
    parent = [i for i in range(n)]
    m = float('inf')
    # Ordena a lista de arestas por peso
    lista.sort(key=lambda x: x[2], reverse=True)

    for u, v, w in lista:
        if find(u, parent) != find(v, parent):
            union(u, v, parent)
            m = min(m, w)

    return m


sys.stdin = open("entrada.txt", "r")
sys.stdout = open("saida.txt", "w")
# Leitura de número de casos
casos = int(input())

# Leitura do input
for t in range(1, casos + 1):
    vertices, aresta = map(int, input().split())

    arestas = []

    # Adiciona ligações entre todos os vértices para todos os outros vértices calculando peso
    for _ in range(aresta):
        i, j, peso = map(int, input().split())
        arestas.append((i, j, peso))

    minimo = kruskal(vertices, arestas)
    print(f"Case #{t}: {minimo}")
