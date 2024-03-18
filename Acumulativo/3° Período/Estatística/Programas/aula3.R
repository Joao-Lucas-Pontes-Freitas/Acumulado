#ex1
vetor <- c()
for(i in 1:10000){
  quantos5 <- 0
  lancamentos <- 0
  while(quantos5 < 2){
    dado <- sample(x = 1:6, size = 1)
    lancamentos <- lancamentos + 1
    if(dado == 5){
      quantos5 <- quantos5 + 1
    }
  }
  vetor[i] = lancamentos
}
mean(vetor)

#ex2
vetor <- 0
for(i in 1:10000){
  figurinhas <- c()
  compras <- 30
  figurinhas <- sample(x = 1:30, size = 30, replace = TRUE, prob = c(1, 2, 3, rep(5, times = 27))) #figurinha 1 sendo rara
  while(length(unique(figurinhas)) != 30){
    sorteio = sample(x = 1:30, size = 1, prob = c(1, rep(5, times = 29)))
    figurinhas <- c(figurinhas, sorteio)
    figurinhas <- unique(figurinhas)
    compras <- compras + 1
  }
  vetor[i] = compras
}
print(mean(vetor))
hist(vetor)

#ex3
vitorias <- 0
for(i in 1:10000){
  jorel <- 7
  juju <- 18
  while(jorel > 0 && juju > 0){
    moeda <- sample(x = c("cara", "coroa"), size = 1)
    if(moeda == "cara"){
      juju <- juju + 1
      jorel <- jorel - 1
    }else{
      juju <- juju - 1
      jorel <- jorel + 1
    }
  }
  if(jorel == 0){
    vitorias <- vitorias + 1
  }
}
print(vitorias/10000)

#data frame
#arquivo murders
dados <- read.csv(file = "murders.csv", header = TRUE)
dados[,5]
mean(dados[,5])
dados$total
mean(dados$total)
max(dados$total)
dados$total == max(dados$total)
dados[dados$total == max(dados$total),]
dados$state[dados$total == max(dados$total)]

dados$region == "South"
sul <- dados[dados$region == "South", ]
sul
max(dados$total/dados$population)













