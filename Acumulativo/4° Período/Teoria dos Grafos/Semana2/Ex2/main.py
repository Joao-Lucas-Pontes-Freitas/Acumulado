import networkx as nx
import matplotlib.pyplot as plt
import keyboard


def bep(G, l, v, visitados, ciclo):
    visitados.add(v)
    ciclo.add(v)
    for vizinho in G.neighbors(v):
        print("Vizinho Atual: ", vizinho)
        if vizinho not in visitados:
            if bep(G, l, vizinho, visitados, ciclo):
                return True
        elif vizinho in ciclo:
            for v in ciclo:
                l.append(v)
                print("Lista atual: ", l)
            return True
    print("Visitados atual: ", visitados)
    print("Ciclo atual: ", ciclo)
    ciclo.remove(v)
    return False


def tem_ciclo(G, l):
    visitados = set()
    ciclo = set()

    for vertice in G.nodes:
        if vertice not in visitados:
            print("Vertice atual: ", vertice)
            bep(G, l, vertice, visitados, ciclo)


G = nx.DiGraph()

arestas = int(input())
for i in range(arestas):
    m, n = map(str, input().split())
    G.add_edge(m, n)
l = []
tem_ciclo(G, l)

while True:
    x = input()
    if x == "":
        break
    if x in l:
        print(x + " safe")
    else:
        print(x + " trapped")

pos = nx.spring_layout(G)

nx.draw(G, pos, with_labels=True, node_size=4000, font_size=10)
labels = nx.get_node_attributes(G, 'weight')
nx.draw_networkx_labels(G, pos, labels=labels)
plt.show()
