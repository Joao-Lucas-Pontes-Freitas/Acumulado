import networkx as nx
import matplotlib.pyplot as plt

G = nx.Graph()
b = int(input())
h = int(input())

mapa = [input() for _ in range(h)]
node = -1
gps = 0
verifica = False
i = 0
j = 0
while True:
    if G.has_node((i,j)):
        break
    if mapa[i][j] == '*':
        G.add_node((i,j), weight="*")
        G.add_edge(node, (i, j))
        verifica = True
        break
    elif mapa[i][j] == '>':
        if node != -1:
            G.add_node((i, j), weight=">")
            G.add_edge(node, (i, j))
        node = (i, j)
        j += 1
        gps = 1
    elif mapa[i][j] == '<':
        if node != -1:
            G.add_node((i, j), weight="<")
            G.add_edge(node, (i, j))
        node = (i, j)
        j -= 1
        gps = -1
    elif mapa[i][j] == '^':
        if node != -1:
            G.add_node((i, j), weight="^")
            G.add_edge(node, (i, j))
        node = (i, j)
        i -= 1
        gps = 2
    elif mapa[i][j] == 'v':
        if node != -1:
            G.add_node((i, j), weight="v")
            G.add_edge(node, (i, j))
        node = (i, j)
        i += 1
        gps = -2
    elif mapa[i][j] == '.':
        if gps == 1:
            j += 1
        elif gps == -1:
            j -= 1
        elif gps == 2:
            i -= 1
        elif gps == -2:
            i += 1


if verifica:
    print('*')
else:
    print('!')

pos = nx.planar_layout(G)

nx.draw(G, pos, node_size=1000, font_size=10)
labels = nx.get_node_attributes(G, 'weight')
nx.draw_networkx_labels(G, pos, labels=labels)
plt.show()

