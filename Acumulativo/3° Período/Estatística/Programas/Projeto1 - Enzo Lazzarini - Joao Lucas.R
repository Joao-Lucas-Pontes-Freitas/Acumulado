#2.1
rodas <- function(){
  roda1 <- c()
  roda2 <- c()
  roda3 <- c()
  sorteio1 <- sample(1:23, size = 1)
  sorteio2 <- sample(1:23, size = 1)
  sorteio3 <- sample(1:23, size = 1)
  if(sorteio1 == 1){
    roda1 <- c("BAR")
  }else{
    if(sorteio1 <= 4){
      roda1 <- c("7")
    }else{
      if(sorteio1 <= 8){
        roda1 <- c("Cereja")
      }else{
        if(sorteio1 <= 13){
          roda1 <- c("Banana")
        }else{
          if(sorteio1 <= 18){
            roda1 <- c("Limao")
          }else{
            roda1 <- c("Laranja")
          }
        }
      }
    }
  }
  if(sorteio2 == 1){
    roda2 <- c("BAR")
  }else{
    if(sorteio2 <= 2){
      roda2 <- c("7")
    }else{
      if(sorteio2 <= 5){
        roda2 <- c("Cereja")
      }else{
        if(sorteio2 <= 11){
          roda2 <- c("Banana")
        }else{
          if(sorteio2 <= 17){
            roda2 <- c("Limao")
          }else{
            roda2 <- c("Laranja")
          }
        }
      }
    }
  }
  if(sorteio3 == 1){
    roda3 <- c("BAR")
  }else{
    if(sorteio3 <= 2){
      roda3 <- c("7")
    }else{
      if(sorteio3 <= 5){
        roda3 <- c("Cereja")
      }else{
        if(sorteio3 <= 11){
          roda3 <- c("Banana")
        }else{
          if(sorteio3 <= 17){
            roda3 <- c("Limao")
          }else{
            roda3 <- c("Laranja")
          }
        }
      }
    }
  }
  
  r <- c(roda1, roda2, roda3)
  return (r)
}
#2.2
dinheiro <- function(){
  vetor <- rodas()
  banana <- sum(vetor == "Banana")
  cereja <- sum(vetor == "Cereja")
  limao <- sum(vetor == "Limao")
  laranja <- sum(vetor == "Laranja")
  sete <- sum(vetor == "7")
  BAR <- sum(vetor == "BAR")
  if(BAR == 3){
    return (50)
  }else{
    if(sete == 3){
      return (30)
    }else{
      if(cereja == 3){
        return (15)
      }else{
        if(limao == 3 || laranja == 3 || banana == 3){
          return (10)
        }else{
          if(cereja == 2){
            return (3)
          }else{
            if(cereja == 1){
              return(1)
            }else{
              return (-2)
            }
          }
        }
      }
    }
  }
    
}

#print(dinheiro())


#2.3
lucro <- c()
qtd <- 1000000
for(i in 1:qtd){
  lucro[i] <- dinheiro()
}
sum(lucro)/qtd
#A esperança corresponde ao valor esperado teoricamente a partir das probabilidades 
#de cada evento, podendo ser também associada a média dos valores obtidos no experimento 
#ao se realizar esses experimentos um número suficientemente grande de vezes. 
#Logo, ao realizar o experimento 1 milhão de vezes, a média dos experimentos 
#aproxima-se da esperança do experimento, ou seja, tende valor teórico.

#2.4
total <- c()
qtd <- 500
total[1] = 10000
for(i in 1:500){
  total[i+1] <- total[i] + dinheiro()
}
total[501]
total
plot(x = 1:501, y = total, type = "l")

#2.5 e 2.6

valores <- c()
grafico <- list()
cores <- rainbow(300)

for (k in 1:300) {
  total <- c()
  qtd <- 500
  total[1] <- 10000
  
  for (i in 1:500) {
    total[i + 1] <- total[i] + dinheiro()
  }
  
  valores[k] <- total[501]
  sorteio <- sample(1:5, size = 1, replace = FALSE)
  grafico[[k]] <- total
}

plot(grafico[[1]], type = "l", col = cores[1], main = "Variações do Vetor Total", xlab = "Iteração", ylab = "Total")

for (k in 2:300) {
  lines(grafico[[k]], type = "l", col = cores[k])
}

abline(h = 10000)

mean(valores)

#2.5 Como é possível de se observar pelo gráfico a maior parte dos experimentos 
#que começam com 10 mil reais e jogam 500x o jogo terminam com prejuízo, ou seja, 
#com o passar do tempo, na maior parte dos experimentos o jogador perde mais do 
#que ganha dinheiro, o que é o esperado, uma vez que a esperança tende a um valor 
#negativo, ou seja, em média, o jogador perde dinheiro a cada jogada.

#2.6 Ao calcular a média de dinheiro após fazer o experimento 300x de um jogo 
#que dura 500 rodadas, a média de dinheiro do apostador calculada é em torno de 9910. 
#Variando pouco para cima e para baixo desse valor. Ao realizar o cálculo teórico 
#e utilizando o fato de que a esperança de uma jogada é -2199/12167, ao jogar 500 rodadas 
#o valor teórico esperado de perda é -90.367387. Ou seja, o jogador perde em média 
#um valor próximo de 90 reais ao jogar 500 vezes. Ou seja, se o jogador começa com 
#10 mil reais, ele saíra com um valor em média de 9910 reais, que foi o resultado 
#prático obtido. Isso se dá pelo fato de que pela Lei dos Grande Números, em que 
#a média do experimento tende a esperança de X.




