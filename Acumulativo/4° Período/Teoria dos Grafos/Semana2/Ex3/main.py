import networkx as nx
import matplotlib.pyplot as plt
import sys


def tem_ciclo(G, l):
    visitados = set()
    ciclo = set()

    for vertice in G.nodes:
        if vertice not in visitados:
            bep(G, l, vertice, visitados, ciclo)

    if len(l) == 0:
        return False
    else:
        return True


def bep(G, l, v, visitados, ciclo):
    visitados.add(v)
    ciclo.add(v)

    for vizinhos in G.neighbors(v):
        if vizinhos not in visitados:
            if bep(G, l, vizinhos, visitados, ciclo):
                return True
        elif vizinhos in ciclo:
            for v in ciclo:
                l.append(v)
            return True

    ciclo.remove(v)
    return False


def OrdemTopologica(G):
    posOrdemRev = []
    marcado = []
    for v in G.nodes():
        if v not in marcado:
            dfs(G, v, marcado, posOrdemRev)
    return posOrdemRev


def dfs(G, v, marcado, posOrdemRev):
    marcado.append(v)
    for vizinho in G.neighbors(v):
        if vizinho not in marcado:
            dfs(G, vizinho, marcado, posOrdemRev)
    posOrdemRev.insert(0, v)


with open('saida.txt', 'w') as arquivo:
    stdout_antigo = sys.stdout
    sys.stdout = arquivo
    while True:
        G = nx.DiGraph()
        entrada = input()
        partes = entrada.split()
        vertices = int(partes[0])
        arestas = int(partes[1])

        if vertices == 0 and arestas == 0:
            sys.stdout = stdout_antigo
            break

        for i in range(vertices):
            G.add_node(i + 1)

        for i in range(arestas):
            entrada = input()
            partes = entrada.split()
            G.add_edge(int(partes[0]), int(partes[1]))

        l = []
        if tem_ciclo(G, l):
            print("IMPOSSIBLE")
        else:
            ordem = OrdemTopologica(G)
            for i in ordem:
                print(i)

        pos = nx.spring_layout(G)

        nx.draw(G, pos, with_labels=True, node_size=1000, font_size=10)
        labels = nx.get_node_attributes(G, 'weight')
        nx.draw_networkx_labels(G, pos, labels=labels)
        plt.show()
