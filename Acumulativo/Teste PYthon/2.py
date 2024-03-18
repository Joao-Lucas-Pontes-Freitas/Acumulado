import random
class JogoDeTiro:
  
  def __init__(self):
    # Inicializa o tabuleiro vazio
    self.tabuleiro = [["-","-","-","-","-","-","-","-","-","-","-","-","-","-","-"], ["-","-","-","-","-","-","-","-","-","-","-","-","-","-","-"],["-","-","-","-","-","-","-","-","-","-","-","-","-","-","-"],["-","-","-","-","-","-","-","-","-","-","-","-","-","-","-"],["-","-","-","-","-","-","-","-","-","-","-","-","-","-","-"],["-","-","-","-","-","-","-","-","-","-","-","-","-","-","-"],["-","-","-","-","-","-","-","-","-","-","-","-","-","-","-"],["-","-","-","-","-","-","-","-","-","-","-","-","-","-","-"],["-","-","-","-","-","-","-","-","-","-","-","-","-","-","-"],["-","-","-","-","-","-","-","-","-","-","-","-","-","-","-"],["-","-","-","-","-","-","-","-","-","-","-","-","-","-","-"],["-","-","-","-","-","-","-","-","-","-","-","-","-","-","-"],["-","-","-","-","-","-","-","-","-","-","-","-","-","-","-"],["-","-","-","-","-","-","-","-","-","-","-","-","-","-","-"],["-","-","-","-","-","-","-","-","-","-","-","-","-","-","-"]]  
    # Define o jogador atual como "X". Teremos os jogadores X e O.
    vetorX = []
    vetorY = []
    for i in range (0,4):
        x = random.randint(0,14)
        while(x in vetorX):
            x = random.randint(0,14)
        vetorX.append(x)

    for i in range (0,4):
        y = random.randint(0,14)
        while(y in vetorY):
            y = random.randint(0,14)
        vetorY.append(y)

    for i in range (0,4):
      #  print(vetorX[i])
      #  print(vetorY[i])
       self.tabuleiro[vetorX[i]][vetorY[i]] = "*"
       
    
    self.jogador_atual = "X"  
    # Define se o jogo terminou como falso
    self.terminou = False  
    self.rodadas = 0

  def exibir_tabuleiro(self):
    #Exibe o tabuleiro na tela
    print("  01 02 03 04 05 06 07 08 09 10 11 12 13 14 15")
    for i in range(15):
      if(i < 9):
        print("0", end = '')
      print(f"{i+1} {'  '.join(self.tabuleiro[i])}")
    # {i+1} são os números na esquerda
    #{' '.join(self.tabuleiro[i])} cria uma string com cada linha matriz
  
  def exibir_jogador_atual(self):
    print(f"Vez do jogador: {self.jogador_atual}")
    #Exibe o jogador atual

  #Faz uma jogada na posição especificada
  def fazer_jogada(self, linha, coluna, Jogador1, Jogador2):

    self.rodadas += 1
    #if not self.terminou -> se o terminou for falso 
    #quer dizer que o jogo ainda não terminou
    if not self.terminou and self.tabuleiro[linha][coluna] == "-":
    #preenche com X ou O de acordo com a escolha do usuário
      self.tabuleiro[linha][coluna] = self.jogador_atual
      if self.rodadas > 2:
        resposta = int(input("Deseja fazer melhorias? (1 para sim e 0 para não)"))
      #Troca para o próximo usuário
      if self.jogador_atual == "O":
        print()
        print("Vida: ", Jogador2.vida)
        print("Ataque: ", Jogador2.ataque)
        print("Defesa: ", Jogador2.defesa)
        print("Moedas: ", Jogador2.moedas)
        if self.rodadas == 1 or self.rodadas == 2 or resposta == 1:
          Jogador2.Comprar()
        if self.rodadas > 20:
          Jogador2.vida -= 5
        if Jogador2.x > 0:
          self.tabuleiro[Jogador2.x][Jogador2.y] = "-"
        Jogador2.x = linha
        Jogador2.y = coluna
        self.jogador_atual = "X"
      else:
        print()
        print("Vida: ", Jogador1.vida)
        print("Ataque: ", Jogador1.ataque)
        print("Defesa: ", Jogador1.defesa)
        print("Moedas: ", Jogador1.moedas)
        if self.rodadas == 1 or self.rodadas == 2 or resposta == 1:
          Jogador1.Comprar()
        if self.rodadas > 20:
           Jogador1.vida -= 5
        if Jogador1.x > 0:
          self.tabuleiro[Jogador1.x][Jogador1.y] = "-"
        Jogador1.x = linha 
        Jogador1.y = coluna
        self.jogador_atual = "O"
    
          
  def verificar_vitoria(self, Jogador1, Jogador2):
    if Jogador1.vida <= 0 and Jogador2.vida > 0:
      self.terminou = True
      return "X"
    elif Jogador2.vida <= 0 and Jogador1.vida > 0:
      self.terminou = True
      return "0"
    elif Jogador1.vida <= 0 and Jogador2.vida <= 0:
      self.terminou = True
      return "Empate"
    #Verifica se um jogador venceu o jogo
    for i in range(15):
      # Verifica vitória em linhas: se os símbolos em uma linha são iguais e diferentes de "-", há um vencedor
      if (self.tabuleiro[i][0] == self.tabuleiro[i][1] == self.tabuleiro[i][2] != "-"):
        # Atualiza a flag 'terminou' para indicar que o jogo terminou
        self.terminou = True
        # Retorna o símbolo do jogador vencedor
        return self.tabuleiro[i][0]  
        # Retorna o símbolo do jogador vencedor

      # Verifica vitória em colunas: se os símbolos em uma coluna são iguais e diferentes de "-", há um vencedor
      if (self.tabuleiro[0][i] == self.tabuleiro[1][i]== self.tabuleiro[2][i] != "-"):
        # Atualiza a flag 'terminou' para indicar que o jogo terminou
        self.terminou = True
        # Retorna o símbolo do jogador vencedor
        return self.tabuleiro[0][i]
      # Verifica vitória nas diagonais:
      # Se os símbolos nas diagonais principais ou secundárias são iguais e diferentes de "-", há um vencedor
      if (self.tabuleiro[0][0] == self.tabuleiro[1][1] == self.tabuleiro[2][2] != "-") or (self.tabuleiro[0][2] == self.tabuleiro[1][1] == self.tabuleiro[2][0] != "-"):
        # Atualiza a flag 'terminou' para indicar que o jogo terminou
        self.terminou = True
        # Retorna o símbolo do jogador vencedor
        return self.tabuleiro[1][1]
     # Se os símbolos nas diagonais principais ou secundárias são iguais e diferentes de "-", há um vencedor

      if all(self.tabuleiro[i][j] != "-" for i in range(15) for j in range(15)):
        self.terminou = True
        return "Empate"

    return None  # Retorna None se o jogo ainda não terminou
class Jogador:
    def __init__(self):
        self.vida = 100  
        self.moedas = 100 
        self.ataque = 0
        self.defesa = 0
        self.x = -1
        self.y = -1

    def Comprar(self):
        vetArmas = [0]
        vetArmaduras = [0]
        listaArmas = [["Tipo: Arma","Nome: Espada Graveto","Material: Madeira", 5, 15],["Tipo: Arma","Nome: Arco Quebrado","Material: Madeira", 8, 25],["Tipo: Arma","Nome: Espada Mortal","Material: Ferro", 10, 45],["Tipo: Arma","Nome: Arco Mágico","Material: Desconhecido",12, 60]]  
        listaArmaduras = [["Tipo: Armadura","Nome: Armadura Enferrujada","Material: Ferro Enferrujado", 3, 10],["Tipo: Armadura","Nome: Armadura Consertada","Material: Ferro",5, 20],["Tipo: Armadura","Nome: Armadura do Cavaleiro","Material: Aço",8, 40],["Tipo: Armadura","Nome: Armadura Tecnológica","Material: Nanotencnoliga",10, 50]]  
        
        x = random.randint(0,3)
        while(x in vetArmas):
          x = random.randint(0,3)

        y = random.randint(0,3)
        while(y in vetArmas):
            y = random.randint(0,3)
        print()
        for i in range (0,3):
          print(listaArmas[x][i])
        print("Ataque: ", end = '')
        print(listaArmas[x][3])
        print("Preço: ", end = '')
        print(listaArmas[x][4], end = "\n\n")

        for i in range (0,3):
            print(listaArmaduras[y][i])
        print("Defesa: ", end = '')
        print(listaArmas[y][3])
        print("Preço: ", end = '')
        print(listaArmaduras[y][4], end = "\n\n")

        if self.moedas >= listaArmas[x][3]:
            c = int(input("Digite 1 para comprar a arma e 0 para rejeitar: "))
            if c != 0:
                vetArmas.append(x)
                self.ataque = listaArmas[x][3]
                self.moedas -= listaArmas[x][4]
        else:
           print("\nSem dinheiro para comprar armas")
        if self.moedas >= listaArmaduras[y][3]:
            c = int(input("Digite 1 para comprar a armadura e 0 para rejeitar: "))
            if c != 0:
                vetArmaduras.append(y)
                self.defesa = listaArmaduras[y][3]
                self.moedas -= listaArmaduras[y][4]
        else:
           print("Sem dinheiro para comprar armaduras")
        print()

    


print("====== JOGO DE TIRO ======")
jogo = JogoDeTiro()
Jogador1 = Jogador()
Jogador2 = Jogador()
#enquanto terminou for falso, ou seja, enquanto o jogo ainda não acabou
while not jogo.terminou:
  # Exibe o tabuleiro atualizado
  jogo.exibir_tabuleiro() 
  # Exibe o símbolo do jogador que deve fazer a jogada
  jogo.exibir_jogador_atual() 
  # Recebe a linha e coluna escolhida pelo jogador 
  #(subtrai 1 para ajustar o índice)
  while True:
    linha = int(input("Digite a linha (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 ou 15): ")) - 1
    coluna = int(input("Digite a coluna (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 ou 15): ")) - 1
    if linha == -2:
      quit()
    elif linha not in [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14] or coluna not in [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]:
      print("Entrada inválida. Tente novamente.")
    else:
      break
  # Faz a jogada no tabuleiro com a linha e coluna escolhidos pelo jogador
  jogo.fazer_jogada(linha, coluna, Jogador1, Jogador2)
  # Verifica se há um vencedor
  vencedor = jogo.verificar_vitoria(Jogador1, Jogador2)

# Se o jogo empatou
if vencedor == "Empate":
  print("O jogo empatou!")
else:
  # Exibe o tabuleiro final
  jogo.exibir_tabuleiro()
  # Exibe o símbolo do jogador vencedor
  print(f"O jogador {vencedor} venceu o jogo!")

