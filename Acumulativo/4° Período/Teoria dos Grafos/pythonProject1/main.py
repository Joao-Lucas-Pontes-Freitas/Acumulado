import networkx as nx
import matplotlib.pyplot as plt
G = nx.Graph()
verifica = True
entrada = input()
partes = entrada.split()
vertices = int(partes[0])
arestas = int(partes[1])

for i in range(vertices):
    G.add_node(i, weight=int(input()))

for i in range(arestas):
    entrada = input()
    partes = entrada.split()
    G.add_edge(int(partes[0]), int(partes[1]))
def dfs_recursiva(grafo, vertice, visitados, pesos):
    visitados.add(vertice)
    pesos.append(G.nodes.get(vertice)['weight'])
    for vizinho in list(G.neighbors(vertice)):
      if vizinho not in visitados:
        dfs_recursiva(grafo, vizinho, visitados, pesos)

for i in range(vertices):
    visitados = set()
    pesos = []
    dfs_recursiva(G, 0, visitados, pesos)
    if(sum(pesos) != 0):
        verifica = False
        break

if verifica == False:
    print("IMPOSSIBLE")
else:
    print("POSSIBLE")


