# import sys

def find(u, parent):
    if u == parent[u]:
        return u
    parent[u] = find(parent[u], parent)
    return parent[u]


def union(u, v, parent):
    u = find(u, parent)
    v = find(v, parent)
    if u == v:
        return
    parent[u] = v


def kruskal(n, lista):
    parent = [i for i in range(n)]
    m = float('inf')

    lista.sort(key=lambda x: x[2], reverse=True)

    for u, v, w in lista:
        if find(u, parent) != find(v, parent):
            union(u, v, parent)
            m = min(m, w)

    return m


# sys.stdin = open("entrada.txt", "r")
# sys.stdout = open("saida.txt", "w")

casos = int(input())

# Leitura do input
for t in range(1, casos + 1):
    vertices, aresta = map(int, input().split())

    arestas = []

    for _ in range(aresta):
        i, j, peso = map(int, input().split())
        arestas.append((i, j, peso))

    minimo = kruskal(vertices, arestas)
    print(f"Case #{t}: {minimo}")
