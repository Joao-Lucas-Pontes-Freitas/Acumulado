#import sys


class Grafo2:
    def __init__(self, vertices):
        self.grafo = {}
        self.values = {}
        self.vertices = vertices

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

    def dfs(self, ver, busca, pilha):
        busca.add(ver)
        for neighbor in self.grafo.get(ver, []):
            if neighbor not in busca:
                self.dfs(neighbor, busca, pilha)
        pilha.insert(0, ver)

    def conta(self):
        n = 0
        visited = set()
        pilha = []
        for element in range(self.vertices):
            if element not in visited:
                self.dfs(element, visited, pilha)

        visited = set()
        for vert in pilha:
            if vert in visited:
                continue
            self.dfs(vert, visited, [])
            n += 1
        return n


#sys.stdin = open('entrada.txt', 'r')
#sys.stdout = open('saida.txt', 'w')
casos = int(input())
for j in range(casos):
    nodes = []
    vertices, arestas = map(int, input().split())
    G = Grafo2(vertices)

    for i in range(arestas):
        u, v = map(int, input().split())
        G.adiciona_aresta(u - 1, v - 1)

    if j != casos - 1:
        input()
    print("Case {}: {}".format(j + 1, G.conta()))
