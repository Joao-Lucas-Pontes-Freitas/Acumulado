from collections import defaultdict


# Representa o grafo
class Grafo:

    def __init__(self, vertices):
        # Inicializa o grafo com um defaultdict de listas. Cada chave representa um vértice,
        # e o valor associado é uma lista de vértices adjacentes (vizinhos).
        self.grafo = defaultdict(list)

        # Conjunto para armazenar os vértices que estão em um ciclo.
        self.in_cicle = set()

        # Conjunto de todos os vértices do grafo.
        self.V = vertices

    def adicionar_aresta(self, u, v):
        # Adiciona uma aresta direcionada do vértice 'u' para o vértice 'v'.
        # Isso é feito adicionando 'v' à lista de vizinhos de 'u'.
        self.grafo[u].append(v)

    def bep(self, v, visitados, reconhecimento):
        # Busca em Profundidade para detectar ciclos.
        # 'v' é o vértice atual, 'visitados' é um conjunto de vértices já visitados,
        # e 'reconhecimento' é um conjunto de vértices no caminho de recorrência atual.

        # Marca o vértice 'v' como visitado e o adiciona ao caminho de recorrência.
        visitados.add(v)
        reconhecimento.add(v)

        # Visita todos os vizinhos do vértice 'v'.
        for vizinhos in self.grafo[v]:
            if vizinhos not in visitados:
                # Se o vizinho não foi visitado, faz uma chamada recursiva.
                if self.bep(vizinhos, visitados, reconhecimento):
                    return True
            elif vizinhos in reconhecimento:
                # Se o vizinho está em 'reconhecimento', um ciclo foi encontrado.
                self.in_cicle.update(reconhecimento)
                return True

        # Remove o vértice 'v' do caminho de recorrência ao voltar.
        reconhecimento.remove(v)
        return False

    def tem_ciclo(self):
        # Verifica se o grafo tem um ciclo.
        visitados = set()
        reconhecimento = set()

        # Inicia uma busca em profundidade a partir de cada vértice do grafo.
        for vertice in self.V:
            if vertice not in visitados:
                self.bep(vertice, visitados, reconhecimento)

    def is_safe(self, cidade):
        # Verifica se uma cidade (vértice) está em um ciclo do grafo.
        # Retorna "segura" se a cidade não está em um ciclo, e "presa" caso contrário.
        if cidade in self.in_cicle:
            return "segura"
        return "presa"


# Função principal
def main():
    # Lista para armazenar as arestas (voos) entre as cidades.
    voos = []

    # Lê o número de arestas (voos) do usuário.
    arestas = int(input())
    for i in range(arestas):
        m, n = map(str, input().split())
        voos.append((m, n))

    # Lista para armazenar as cidades que serão verificadas.
    cidades_verificadas = []
    while True:
        city = input("Verificar cidade (pressione Enter para sair): ")
        if city:
            cidades_verificadas.append(city)
        else:
            break

    # Passo 1: Construir o Grafo
    # Cria um conjunto de cidades (vértices) a partir das arestas (voos).
    cidades = set(cidade for voo in voos for cidade in voo)
    g = Grafo(cidades)

    # Adicionar arestas ao grafo
    for u, v in voos:
        g.adicionar_aresta(u, v)

    # Passo 2: Detectar Ciclo
    # Verifica se há um ciclo no grafo.
    g.tem_ciclo()

    # Passo 3: Verificar Segurança das Cidades
    # Verifica e imprime o status de segurança de cada cidade verificada.
    status_seguranca = [(cidade, g.is_safe(cidade)) for cidade in cidades_verificadas]
    print(status_seguranca)


# Executar a função principal
# Isso verifica se este arquivo é o ponto de entrada do programa.
# Se for verdade, a função main() será chamada.
if __name__ == "__main__":
    main()
