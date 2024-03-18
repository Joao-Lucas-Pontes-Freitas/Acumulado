# import networkx as nx
# import matplotlib.pyplot as plt
import sys


class Grafo:
    def __init__(self):
        self.grafo = {}
        self.values = {}

    def adiciona_vertice(self, vertice, value):
        self.grafo[vertice] = []
        self.values[vertice] = value

    def adiciona_aresta(self, u, v):
        if u not in self.grafo:
            self.adiciona_vertice(u, None)
        self.grafo[u].append(v)

    def obter_adjacentes(self, vertice):
        return self.grafo.get(vertice, [])

    def verifica_vertice(self, vertice):
        return vertice in self.grafo


def dfs(g, v, visitados, pilha):
    visitados.append(v)
    for vizinho in g.obter_adjacentes(v):
        if vizinho not in visitados:
            dfs(g, vizinho, visitados, pilha)
    pilha.insert(0, v)


def transposto(g, nodes):
    gt = Grafo()
    for v in nodes:
        for vizinho in g.obter_adjacentes(v):
            gt.adiciona_aresta(vizinho, v)
    return gt


def componentes(g, visitados, pilha, final):
    n = 0
    for v in pilha:
        if v not in visitados:
            dfs(g, v, visitados, [])
            n += 1
    final.append(n)


final = []
sys.stdin = open('entrada.txt', 'r')
while True:
    vertices, arestas = map(int, input().split())
    nodes = []
    G = Grafo()
    if vertices == 0:
        break
    for _ in range(vertices):
        nodes.append(input())
    for i in range(arestas):
        u = input()
        v = input()
        G.adiciona_aresta(u, v)

    pilha = []
    visitados = []

    for vertice in nodes:
        if vertice not in visitados:
            dfs(G, vertice, visitados, pilha)

    # print(pilha)

    # nx.draw_planar(G, with_labels=True)
    # plt.show()
    G = transposto(G, nodes)
    # nx.draw_planar(G, with_labels=True)
    # plt.show()

    visitados = []
    componentes(G, visitados, pilha, final)
sys.stdout = open('saida.txt', 'w')
for i in final:
    print(i)

# G = nx.DiGraph()
# G.add_edge(1, 2)
# G.add_edge(1, 3)
# G.add_edge(3, 1)
# G.add_edge(2, 4)
# G.add_edge(3, 4)
# G.add_edge(4, 1)
# G.add_edge(1, 4)
# nx.draw_planar(G, with_labels=True)
# plt.show()
# pilha = []
# visitados = []
#
# dfs(G, 1, visitados, pilha)
# G = transposto(G)
# nx.draw_planar(G, with_labels=True)
# plt.show()
# visitados = []
# n = 0
# componentes(G, pilha, visitados, n)
