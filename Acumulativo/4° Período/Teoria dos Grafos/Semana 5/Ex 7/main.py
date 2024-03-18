class Grafo:
    def __init__(self, n, m):
        self.n = n
        self.matriz_adjacencia = m

    def prim(self):
        # Todos os pais começam com -1 (não visitado) juntamente com suas chaves
        pai = [-1] * self.n
        chave = [float('inf')] * self.n

        # Marca vértice está na árvore mínima ou não
        em_agm = [False] * self.n

        # Começar com o vértice 0 como o vértice inicial
        chave[0] = 0

        for _ in range(self.n):
            u = self.prox_vertice(chave, em_agm)
            em_agm[u] = True

            # Verifica os adjacnetes do vértice e se o peso delas for válido e menor que atual, adicona na árvore
            for v in range(self.n):
                if 0 < self.matriz_adjacencia[u][v] < chave[v] and not em_agm[v]:
                    pai[v] = u
                    chave[v] = self.matriz_adjacencia[u][v]

        # Imprimir a árvore mínima
        for i in range(1, self.n):
            print(pai[i] + 1, i + 1)

    # Devolve o próximo vértice (menor índice que não foi viistado)
    def prox_vertice(self, chave, em_agm):
        min_chave = float('inf')
        vertice_min = -1
        for v in range(self.n):
            if chave[v] < min_chave and not em_agm[v]:
                min_chave = chave[v]
                vertice_min = v
        return vertice_min


# Leitura input
n = int(input())
matriz = [list(map(int, input().split())) for _ in range(n)]
grafo = Grafo(n, matriz)
grafo.prim()
