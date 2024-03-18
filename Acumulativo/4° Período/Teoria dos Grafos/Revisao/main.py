from collections import defaultdict

import matplotlib.pyplot as plt
import networkx as nx


def find(parent, u):
    if u == parent[u]:
        return u
    parent[u] = find(parent, parent[u])
    return parent[u]


# Função para unir dois vértices por meio da união de seus pais (estrutura union-find)
def union(parent, u, v):
    u = find(parent, u)
    v = find(parent, v)
    if u == v:
        return
    parent[u] = v


class UnionFind:
    def __init__(self, n):
        self.pai = [i for i in range(n + 1)]

    def find(self, v):
        if v == self.pai[v]:
            return v
        self.pai[v] = self.find(self.pai[v])
        return self.pai[v]

    def union(self, u, v):
        u = self.find(self.pai[u])
        v = self.find(self.pai[v])
        if u == v:
            return
        self.pai[u] = v


def segundaArvore(lista, n):
    arvore, _ = Kruskal(lista, n)
    menor = {float('inf'): None}
    for e in arvore:
        lista1 = lista
        lista1.remove(e)
        arv, temp = Kruskal(lista1, n)
        if temp < list(menor.keys())[0]:
            menor.clear()
            menor[temp] = arv
    return menor


def Kruskal(lista, n):
    lista.sort(key=lambda x: x[2])
    menor = 100
    arvore = []
    conjunto = UnionFind(n)
    soma = 0
    for elemento in lista:
        x, y, p = elemento
        if conjunto.find(x) != conjunto.find(y):
            conjunto.union(x, y)
            arvore.append(elemento)
            soma += p
    return arvore, soma


def KruskalMaior(lista, n):
    lista.sort(key=lambda x: x[2], reverse=True)
    maior = 0
    arvore = []
    conjunto = UnionFind(n)
    for elemento in lista:
        x, y, p = elemento
        if conjunto.find(x) != conjunto.find(y):
            conjunto.union(x, y)
            arvore.append(elemento)
            maior = max(p, maior)
    return arvore, maior


def KruskalSub(lista, n, obrigatorio):
    lista.sort(key=lambda x: x[2])
    arvore = []
    conjunto = UnionFind(n)

    for e in obrigatorio:
        x, y, p = e
        if conjunto.find(x) != conjunto.find(y):
            conjunto.union(x, y)
            arvore.append(e)

    for elemento in lista:
        x, y, p = elemento
        if conjunto.find(x) != conjunto.find(y):
            conjunto.union(x, y)
            arvore.append(elemento)

    return arvore


def KruskalFloresta(lista, n, num):
    lista.sort(key=lambda x: x[2])
    arvore = []
    conjunto = UnionFind(n)
    num_componentes = n

    for elemento in lista:
        x, y, p = elemento

        if conjunto.find(x) != conjunto.find(y):
            conjunto.union(x, y)
            arvore.append(elemento)
            num_componentes -= 1

            if num_componentes == num:
                break

    return arvore


def dfsStoD(adj, u, dest, path, visitados):
    visitados.add(u)
    if u == dest:
        return True
    for v in adj[u]:
        if v not in visitados:
            path.append(v)
            if dfsStoD(adj, v, dest, path, visitados):
                return True
            path.remove(v)


def bfs(grafo, v):
    fila = [v]
    dic = {v: 1}
    while fila:
        vertice = fila.pop(0)
        for vizinho in grafo.neighbors(vertice):
            if vizinho not in dic:
                dic[vizinho] = dic[v] * -1
                fila.append(vizinho)
            elif dic[vizinho] == dic[v]:
                return False
    return True


li = [(1, 2, 5), (1, 3, 8), (3, 5, 2), (2, 5, 3), (3, 4, 18), (2, 6, 16), (5, 4, 12), (5, 6, 30), (5, 7, 14), (4, 7, 4),
      (6, 7, 26)]
print(Kruskal(li, 7))
dic = segundaArvore(li, 7)
for i in dic:
    print(dic[i])
# arv, m = KruskalMaior(li, 8)
# print("Arvore:", arv, "maior:", m)
# print(KruskalSub(li, 8, [(7, 8, 9), (8, 1, 3)]))
# print(KruskalFloresta(li, 8, 3))
# arv, m = Kruskal(li, 8)
# print("Arvore:", arv, "menor:", m)

# dic = {}
# for u, v, p in arv:
#     print(u, v, p)
#     if u not in dic:
#         dic[u] = []
#     if v not in dic:
#         dic[v] = []
#     dic[u].append(v)
#     dic[v].append(u)
# caminho = []
# visit = set()
# dfsStoD(dic, 2, 8, caminho, visit)
# print(caminho)
# G = nx.DiGraph()
# G.add_edge(1, 2)
# G.add_edge(1, 3)

# from collections import defaultdict
#
#
# class UnGraph:
#     def __init__(self, v=None):
#         self.V = v
#         self.grafo = defaultdict(list)
#
#     def addAresta(self, u, v):
#         self.grafo[u].append(v)
#         self.grafo[v].append(u)
#
#     def adj(self, u):
#         return self.grafo[u]
#
#
# def dfs(grafo, u, visitados, descoberta, parent, ap, low, desc):
#     visitados.add(u)
#     desc[u] = descoberta
#     low[u] = descoberta
#     children = 0
#
#     for v in grafo.adj(u):
#         if v not in visitados:
#             parent[v] = u
#             children += 1
#             dfs(grafo, v, visitados, descoberta + 1, parent, ap, low, desc)
#             low[u] = min(low[u], low[v])
#
#             if parent[u] not in visitados and children > 1:
#                 ap.add(u)
#
#             if parent[u] in visitados and low[v] >= desc[u]:
#                 ap.add(u)
#
#         elif v != parent[u]:
#             low[u] = min(low[u], desc[v])
#
#
# def articulacoes(g):
#     visitados = set()
#     pais = {u: -1 for u in set(g.grafo)}
#     ap = set()
#     low = {}
#     desc = {}
#
#     for u in set(g.grafo):
#         if u not in visitados:
#             dfs(g, u, visitados, 0, pais, ap, low, desc)
#
#     return ap
#
#
# g = UnGraph()
# g.addAresta(0, 1)
# g.addAresta(1, 2)
# g.addAresta(1, 4)
# g.addAresta(3, 4)
# g.addAresta(4, 5)
# g.addAresta(5, 6)
#
# print(articulacoes(g))
