class Grafo2:
    def __init__(self):
        self.grafo = {}
        self.values = {}

    def adiciona_vertice(self, vertice, value):
        self.grafo[vertice] = []
        self.values[vertice] = value

    def adiciona_aresta(self, u, v):
        if u not in self.grafo:
            self.adiciona_vertice(u, None)
        if v not in self.grafo:
            self.adiciona_vertice(v, None)
        self.grafo[u].append(v)
        self.grafo[v].append(u)

    def obter_adjacentes(self, vertice):
        return self.grafo.get(vertice, [])

    def verifica_vertice(self, vertice):
        return vertice in self.grafo


def findp(x, parent):
    return x if parent[x] == x else findp(parent[x], parent)


def dfs(grafo, u, contador, visited, ap, parent, num, low):
    children = 0
    visited[u] = True
    num[u] = contador
    low[u] = contador
    contador += 1
    for v in grafo.obter_adjacentes(u):
        if not visited[v]:
            children += 1
            parent[v] = u
            dfs(grafo, v, contador, visited, ap, parent, num, low)

            if low[v] > num[u]:
                ap.append((u, v))

            low[u] = min(low[u], low[v])

        elif v != parent[u]:
            low[u] = min(low[u], num[v])


def Articulacoes_final(grafo, n, parent):
    visited = [False] * n
    num = [-1] * n
    low = [-1] * n
    ap = []
    contador = 0
    for u in range(n):
        parent[u] = u
        if not visited[u]:
            dfs(grafo, u, contador, visited, ap, parent, num, low)

    return ap


results_final = []

# while True:
#     G = Grafo2()
#     n = int(input())
#     if n == 0:
#         break
#
#     while True:
#         m = list(map(int, input().split()))
#         for i in range(1, len(m)):
#             G.adiciona_aresta(m[0] - 1, m[i] - 1)
#         if len(m) == 1:
#             break
#
#     results_final.append(Articulacoes_final(G, n))
while True:
    r = []
    vertices, arestas, testes = map(int, input().split())
    parent = [-1] * vertices
    if vertices == 0 and arestas == 0 and testes == 0:
        break
    g = Grafo2()
    for i in range(arestas):
        u, v = map(int, input().split())
        g.adiciona_aresta(u - 1, v - 1)

    l = Articulacoes_final(g, vertices, parent)
    for i in range(testes):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        results_final.append("Y" if findp(a, parent) == findp(b, parent) else "N")


[print(i) for i in results_final]
