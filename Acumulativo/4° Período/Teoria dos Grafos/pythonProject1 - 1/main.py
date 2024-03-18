import networkx as nx
import matplotlib.pyplot as plt

def bipartido_profunidade(graph):
    cores = {}
    primeiro = list(graph.nodes())[0]
    cores[primeiro] = 0

    pilha = [primeiro]

    while pilha:
        vertice = pilha.pop()

        for vizinho in graph.neighbors(vertice):
            if vizinho not in cores:
                cores[vizinho] = 1 - cores[vertice]
                pilha.append(vizinho)
            elif cores[vizinho] == cores[vertice]:
                return False

    return True

def bipartido_largura(graph):
    cores = {}
    fila = []

    primeiro = list(graph.nodes())[0]

    cores[primeiro] = 1
    fila.append(primeiro)

    while fila:
        vertice = fila.pop(0)
        for vizinho in graph.neighbors(vertice):
            if vizinho not in cores:
                cores[vizinho] = 1 - cores[vertice]
                fila.append(vizinho)
            elif cores[vizinho] == cores[vertice]:
                return False
    return True


G = nx.Graph()

v = int(input())
a = int(input())

for i in range(a):
    entrada = input()
    partes = entrada.split()
    G.add_edge(int(partes[0]), int(partes[1]))

nx.draw_planar(G, with_labels=True)
plt.show()

print(bipartido_profunidade(G))
print(bipartido_largura(G))


