import matplotlib.pyplot as plt
import networkx as nx


def OrdemTopologica(G):
    posOrdemRev = []
    marcado = set()
    for v in G.nodes():
        if v not in marcado:
            dfs(G, v, marcado, posOrdemRev)
    for e in posOrdemRev:
        print(e, end="")


def dfs(G, v, marcado, posOrdemRev):
    marcado.add(v)
    for vizinho in G.neighbors(v):
        if vizinho not in marcado:
            dfs(G, vizinho, marcado, posOrdemRev)
    posOrdemRev.insert(0, v)
    print(posOrdemRev)


while True:
    G = nx.DiGraph()
    entrada1 = input()
    entrada2 = input()
    if entrada1 == "":
        exit()
    while entrada2 != "#":
        t = min(len(entrada1), len(entrada2))
        for i in range(t):
            if entrada1[i] != entrada2[i]:
                G.add_edge(entrada1[i], entrada2[i])
                break
        entrada1 = entrada2
        entrada2 = input()

    OrdemTopologica(G)
    print()
    pos = nx.shell_layout(G)

    nx.draw(G, pos, with_labels=True, node_size=1000, font_size=10)
    labels = nx.get_node_attributes(G, 'weight')
    nx.draw_networkx_labels(G, pos, labels=labels)
    plt.show()
