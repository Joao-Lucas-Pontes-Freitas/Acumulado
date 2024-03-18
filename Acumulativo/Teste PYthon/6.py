import tkinter as tk #importar a biblioteca tkinter
from unidecode import unidecode #biblioteca para remover os acentos
from tkinter import messagebox 
import random

class JogodaForca:

  def __init__(self, palavra):
    self.palavra = palavra #armazena a palavra
    self.palavra_sem_acento = unidecode(palavra).upper() #remove acento e coloca em maiúsculo
    self.tentativas = 6 #define as tentativas
    self.letras_descobertas = ["_"]*len(palavra) #representa as letras não descobertas
  
    self.window = tk.Tk() #criar uma nova janela usando o tkinter
    self.window.title("Jogo da Forca") #define um título 
    self.window.geometry("400x400") #tamanho definido

    self.letras_tentadas = [] #lista de letras tentadas pelo jogador

    #criar um objeto de desenho de tela no tkinter
    self.canvas = tk.Canvas(self.window, width=300, height=200) 
    self.canvas.pack(pady=10) #adiciona o canvas na tela gráfica

    self.label_palavra = tk.Label(self.window, text=" ".join(self.letras_descobertas), font=("Arial", 20)) #cria um rótulo para exibir as letras da palavra
    self.label_palavra.pack()

    self.label_tentativas = tk.Label(self.window, text = "Tentativas Restantes: {}".format(self.tentativas), font=("Arial", 16))
    self.label_tentativas.pack()

    self.label_tentadas = tk.Label(self.window, text = "Letras Tentadas: {}".format(" ".join(self.letras_tentadas)), font=("Arial", 16))
    self.label_tentadas.pack()

    #frame que agrupa a entrada e o botão
    self.frame_entry = tk.Frame(self.window)
    self.frame_entry.pack(pady=10)

    #cria o input do usuário
    self.entry = tk.Entry(self.frame_entry, font=("Arial", 16), width = 15)
    self.entry.pack(side = tk.LEFT)

    #criar o botão pra enviar a entrada do usuário
    self.button = tk.Button(self.frame_entry, text="Adivinhar", command=self.verificar_adivinhacao, font=("Arial", 16))
    self.button.pack(side = tk.RIGHT)

    self.desenhar_forca() #chamar o método para desenhar a forca

  def desenhar_forca(self):
    self.canvas.create_line(20, 180, 100, 180, width=2)  # Desenha a base horizontal
    self.canvas.create_line(60, 20, 60, 180, width=2)  # Desenha o poste vertical
    self.canvas.create_line(60, 20, 150, 20, width=2)  # Desenha a trave horizontal
    self.canvas.create_line(150, 20, 150, 40, width=2)  # Desenha a corda vertical

  def desenhar_boneco(self):
    if self.tentativas == 5:
      self.canvas.create_oval(140, 40, 160, 60, width=2)  # Desenha a cabeça
    elif self.tentativas == 4:
      self.canvas.create_line(150, 60, 150, 100, width=2)  # Desenha o corpo
    elif self.tentativas == 3:
      self.canvas.create_line(150, 80, 130, 90, width=2)  # Desenha o braço esquerdo
    elif self.tentativas == 2:
      self.canvas.create_line(150, 80, 170, 90, width=2)  # Desenha o braço direito
    elif self.tentativas == 1:
      self.canvas.create_line(150, 100, 130, 110, width=2)  # Desenha a perna esquerda
    elif self.tentativas == 0:
      self.canvas.create_line(150, 100, 170, 110, width=2)  # Desenha a perna direita
  

  def verificar_adivinhacao(self):
    entrada = self.entry.get().strip().upper() #obtem a entrada, tira os espaços e coloca em caixa alta
    self.entry.delete(0, tk.END) #limpe a caixa de entrada

    if len(entrada) != 1:
      messagebox.showinfo("Entrada inválida", "Digite somente uma letra.")
      return
    
    if entrada in self.letras_tentadas:
      messagebox.showinfo("Letra Repetida", "Você já tentou essa letra.")
      return 

    self.letras_tentadas.append(entrada) #adiciona às letras tentadas
    self.label_tentadas.config(text="Letras Tentadas: {}".format(" ".join(self.letras_tentadas)))

    if entrada in self.palavra_sem_acento:
      for i, l in enumerate(self.palavra_sem_acento):
        if l == entrada:
          self.letras_descobertas[i] = self.palavra[i]

      self.label_palavra.config(text= ' '.join(self.letras_descobertas))
    else:
      self.tentativas -= 1
      self.label_tentativas.config(text="Tentativas Restantes: {}".format(self.tentativas))
      self.desenhar_boneco()

    self.verificar_fim_de_jogo()

  def verificar_fim_de_jogo(self):
    if "_" not in self.letras_descobertas:
      messagebox.showinfo("Resultado:", "Você ganhou!")
      self.window.destroy()
    elif self.tentativas == 0:
      messagebox.showinfo("Resultado:", "Você perdeu! A palavra era: {}".format(self.palavra))
      self.window.destroy()
      


    
with open("palavras.txt", "r", encoding="utf-8") as arquivo:
  palavras = [palavra.strip() for palavra in arquivo.readlines()]

palavra_aleatoria = random.choice(palavras)
  
jogo = JogodaForca(palavra_aleatoria)
jogo.window.mainloop()