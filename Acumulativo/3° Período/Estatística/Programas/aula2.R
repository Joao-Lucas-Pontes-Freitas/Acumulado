a <- c(3,6,67)
a
a[2]
a[c(1,3,1)]
c(a, "teste")

sorteio <- sample(x = 1:100, size = 20, replace = TRUE)
sorteio

sorteio == 27
sum(sorteio == 27)
which(sorteio == 27)
sorteio[12]

sorteio < 27
sorteio [sorteio < 27]

#repetição
#for
soma <- 0
for (j in 1:20) {
  soma <- soma + j
}
soma
sum(1:20)
#medias dos valores que tira no dado
medias <- c()
for (j in 1:10000) {
  dado <- sample(x = 1:6, size = 100, replace = TRUE)
  medias[j] = mean(dado)
}
medias
mean(medias)
hist(medias)

#while para média de vezes que joga dado para tirar o 5
final <- c()
for (j in 1:10000) {
  dado <- 0
  jogadas <- 0
  #resultados <- c()
  while(dado != 5){
    dado <- sample(x = 1:6, size = 1)
    jogadas <- jogadas + 1
   # resultados <- c(resultados, dado)
  }
  #jogadas
  #resultados
  final[j] = jogadas
}
final
mean(final)

#condicional
dado <- sample(1:6, size = 1)
dado
if(dado %% 2 == 0){
  final = final + 1
  print("o resultado é par")
}else{
  print("o resultado é ímpar")
}

#exercicio saber quantos resultados diferentes de sorteio tem

dado <- sample(1:6, size = 3, replace = TRUE)
dado
if(length(unique(dado)) == 3){
  print("todos diferentes")
}else if(length(unique(dado)) == 2){
  print("dois diferentes")
}else{
  print("todos iguais")
}
#exercicio sair 2x o numero 5 ~= 12
vetor <- c()
for (i in 1:100000) {
  contador <- 0
  j <- 0
  while(contador != 2){
    dado <- sample(1:6, size = 1)
    if(dado == 5){
      contador <- contador + 1
    }
    j <- j + 1
  }
  vetor[i] = j
}
mean(vetor)
hist(vetor)

#exercicio 2 
figurinhas <- 1:30
quantidade_figurinhas <- c()
for(k in 1:5000) {
  album <- c()
  figurinhas_distintas <- 0
  compras <- 0
  while(figurinhas_distintas < 30) {
    album <- c(album, sample(figurinhas, size=1,replace = TRUE))
    figurinhas_distintas <- length(unique(album))
    compras <- compras + 1
  }
  quantidade_figurinhas[k] <- compras
}
mean(quantidade_figurinhas)
hist(quantidade_figurinhas)

#exercicio juju
vitorias <- 0
for(i in 1:10000){
  juju <- 18
  jorel <- 7
  while(juju > 0 && jorel > 0){
    moeda <- sample(x = c("cara", "coroa"), size = 1)
    if(moeda == "cara"){
      juju <- juju + 1
      jorel <- jorel - 1
    }else{
      juju <- juju - 1
      jorel <- jorel + 1
    }
    jogadas <- jogadas + 1
  }
  if(jorel == 0){
    vitorias <- vitorias + 1
  }else{
    vitorias <- vitorias + 0
  }
}
print(vitorias/10000)








