import sys
from collections import defaultdict

sys.stdin = open("entrada.txt", "r")
sys.stdout = open("saida.txt", "w")


class Grafo:
    def __init__(self):
        self.grafo = defaultdict(list)
        self.pesos = {}
        self.vertices = set()

    def adicionar_aresta(self, u, v, peso):
        self.grafo[u].append(v)
        self.pesos[(u, v)] = peso
        self.vertices.add(u)
        self.vertices.add(v)

    def remover_aresta(self, u, v):
        if (u, v) in self.pesos:
            self.grafo[u].remove(v)
            del self.pesos[(u, v)]

    def atualizar_aresta(self, u, v, novo_peso):
        if (u, v) in self.pesos:
            self.pesos[(u, v)] = novo_peso

    def topological_sort_util(self, v, visitado, pilha):
        visitado[v] = True

        for i in self.grafo[v]:
            if not visitado[i]:
                self.topological_sort_util(i, visitado, pilha)

        pilha.insert(0, v)

    def topological_sort(self):
        visitado = {v: False for v in self.vertices}
        pilha = []

        for v in self.vertices:
            if not visitado[v]:
                self.topological_sort_util(v, visitado, pilha)

        return pilha

    def obter_todos_os_nos(self):
        return list(self.vertices)


def bellman_ford(grafo, origem, elevadores):
    dist = {}
    arestaPara = {}
    mesmo_elevador = [True] * len(elevadores)
    for no in grafo.obter_todos_os_nos():
        dist[no] = float('inf')

    dist[origem] = 0

    ordem = grafo.topological_sort()

    for u in ordem:
        for v in grafo.grafo[u]:
            x = 0

            # if u in elevador1 and v not in elevador1:
            #     x = 60
            # elif u in elevador2 and v not in elevador2:
            #     x = 60

            for e in range(len(elevadores)):
                if u in elevadores[e] and v not in elevadores[e]:
                    mesmo_elevador[e] = False
            mesmo = any(mesmo_elevador)
            if not mesmo:
                x = 60

            if float(dist[u]) + float(grafo.pesos[(u, v)]) + float(x) < dist[v]:
                dist[v] = float(dist[u]) + float(grafo.pesos[(u, v)])
                arestaPara[v] = u

    return dist, arestaPara


Grafo = Grafo()

numero_elevadores, destino = map(int, input().split())
pesos = input().split()
elevadores = [[]] * numero_elevadores

for k in range(numero_elevadores):
    elevadores[k] = input().split()

for i in range(numero_elevadores):
    for j in range(len(elevadores[i]) - 1):
        u, v = int(elevadores[i][j]), int(elevadores[i][j + 1])
        peso = pesos[i] * (v - u)
        Grafo.adicionar_aresta(u, v, peso)

# for i in range(len(sequencia1) - 1):
#     u, v = int(sequencia1[i]), int(sequencia1[i + 1])
#     peso = 10*(v-u)
#     Grafo.adicionar_aresta(u, v, peso)
#
# for i in range(len(sequencia2) - 1):
#     u, v = int(sequencia2[i]), int(sequencia2[i + 1])
#     peso = 5*(v-u)
#     Grafo.adicionar_aresta(u, v, peso)


distancias, arestaPara = bellman_ford(Grafo, 0, elevadores)
x = float("inf")
if distancias[destino] != x:
    print(distancias[destino])
else:
    print("Impossible")
