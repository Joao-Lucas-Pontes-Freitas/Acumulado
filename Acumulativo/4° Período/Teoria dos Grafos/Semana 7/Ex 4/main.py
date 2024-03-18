import sys

sys.stdin = open("entrada.txt", "r")
sys.stdout = open("saida.txt", "w")

from collections import defaultdict


def bfs(adjacentes, vertice, importante):
    soma = 0
    fila = [vertice]
    visitados = set()
    dist = {vertice: 0}
    edgeto = {}

    while len(fila) > 0:
        v = fila.pop(0)
        for w in adjacentes[v]:
            if w not in visitados:
                edgeto[w] = v
                dist[w] = dist[v] + 1
                visitados.add(w)
                fila.append(w)

    for n in range(1, len(dist) + 1):
        if n in importante:
            soma += dist[n]
    return soma


casos = int(input())
for _ in range(casos):
    adjacencias = defaultdict(list)
    estacoes, linhas = map(int, input().split())
    matriz = [[] for _ in range(linhas)]
    for j in range(linhas):
        primeiro, *linha = map(int, input().split())
        adjacencias[primeiro].append(linha[0])
        adjacencias[linha[0]].append(primeiro)
        for i in range(len(linha)):
            if linha[i] != 0 and i > 0:
                if linha[i - 1] not in adjacencias[linha[i]]:
                    adjacencias[linha[i]].append(linha[i - 1])
            if linha[i] != 0 and i < len(linha) - 1:
                if linha[i + 1] not in adjacencias[linha[i]] and linha[i + 1] != 0:
                    adjacencias[linha[i]].append(linha[i + 1])
        matriz[j].append(primeiro)
        for e in linha:
            if e != 0:
                matriz[j].append(e)

    important = set()
    for m in range(estacoes):
        estacao = m + 1
        cont = 0
        for k in matriz:
            if estacao in k:
                cont += 1
        if cont > 1:
            important.add(estacao)

    menor = float('inf')
    indice = 0

    for u in important:
        atual = bfs(adjacencias, u, important)
        print(u, atual)
        if atual < menor:
            menor = atual
            indice = u
        elif atual == menor:
            indice = min(indice, u)

    print("Krochanska is in:", indice)
