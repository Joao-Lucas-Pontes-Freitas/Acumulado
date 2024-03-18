from collections import defaultdict


def obter_fechamento(atual, simbolo, dic):
    fechamento = set()
    for estado in atual:
        for transicao, prox in dic[estado]:
            if transicao == simbolo:
                fechamento.add(prox)
    return fechamento


def conversor(dic):
    estados = set()
    fila = [next(iter(dic.keys()))]
    automato = defaultdict(list)
    while fila:
        atual = fila.pop(0)
        estado = ''.join(sorted(atual))
        estados.add(estado)

        for simbolo in {'0', '1'}:
            prox = obter_fechamento(atual, simbolo, dic)
            if prox:
                prox_estado_str = ''.join(sorted(prox))
                automato[estado].append((simbolo, prox_estado_str))
                if prox_estado_str not in estados:
                    fila.append(prox)

    return automato


def imrpime(automato):
    print("\nTabela de Transições do AFD:")
    for estado, transicoes in automato.items():
        print(f"{estado}: {transicoes}")


# Exemplo de utilização
dic = {"F": [("0", "F"), ("1", "F"), ("1", "G")],
       "G": [("1", "H")],
       "H": [("1", "I")],
       "I": []
       }

automato = conversor(dic)
imrpime(automato)


