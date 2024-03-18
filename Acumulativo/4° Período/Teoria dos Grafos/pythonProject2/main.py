import networkx as nx
import matplotlib.pyplot as plt
def dfs(G, grid, i, j, node):
    m, n = len(grid), len(grid[0])

    if 0 <= i < m and 0 <= j < n and grid[i][j] == '@':
        grid[i][j] = '*'
        if node != -1:
            G.add_edge(node, (i,j))
        node = (i,j)

        deslocamentos = [(-1, -1), (-1, 0), (-1, 1),
                         (0, -1), (0, 1),
                         (1, -1), (1, 0), (1, 1)]

        for di, dj in deslocamentos:
            nova_posicao_i = i + di
            nova_posicao_j = j + dj

            if nova_posicao_i < m and nova_posicao_j < n:
                if grid[nova_posicao_i][nova_posicao_j] == '@':
                    dfs(G, grid, nova_posicao_i, nova_posicao_j, node)


def contador(G, grid):
    m, n = len(grid), len(grid[0])
    count = 0
    node = -1
    for i in range(m):
        for j in range(n):
            if grid[i][j] == '@':
                count += 1
                dfs(G, grid, i, j, node)

    return count


m, n = map(int, input().split())
grid = [list(input()) for _ in range(m)]

G = nx.Graph()
print(contador(G, grid))

pos = nx.spring_layout(G)

nx.draw(G, pos, with_labels= True, node_size=1000, font_size=10)
labels = nx.get_node_attributes(G, 'weight')
nx.draw_networkx_labels(G, pos, labels=labels)
plt.show()

nx.draw_planar(G, with_labels = True)
plt.show()

