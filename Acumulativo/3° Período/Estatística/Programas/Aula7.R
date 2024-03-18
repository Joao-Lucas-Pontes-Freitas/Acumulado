azeite <- read.table(file = "olive.txt", header = TRUE, sep = ",")
str(azeite)

indices <- sample(1:nrow(azeite), size = nrow(azeite), replace = FALSE)

azeite <- azeite[indices,]

n <- round(nrow(azeite)*0.8)
n
treinamento <- azeite[1:n,]
teste <- azeite[(n+1):nrow(azeite),]

no <- treinamento[treinamento$region == "Northern Italy",]
sa <- treinamento[treinamento$region == "Sardinia",]

summary(no)
summary(sa)
summary(so)
so$eicosenoic

boxplot(no$linoleic, sa$linoleic, 
        names = c("setosa", "versicolor"))

max(no$linoleic)
so$linoleic


previsao <-c()
for (j in 1:nrow(teste)){
  if(teste$eicosenoic[j] > 0.1 ){
    previsao[j] <- "Southern Italy"
  }
  else{
    if(teste$linoleic[j] > 10.5){
      previsao[j] <- "Sardinia"
    }else{
      previsao[j] <- "Northern Italy"
    }
  }
}

previsao
mean(previsao == teste$region)

par(mfrow = c(1,1))
plot(x = treinamento$eicosenoic, y = treinamento$linoleic, pch = 16, type = "n")
points(x = no$eicosenoic, y = no$linoleic, col = "#8429c1", pch = 16, cex = 1)
points(x = sa$eicosenoic, y = sa$linoleic, col = "#3c43fa", pch = 16, cex = 1)
points(x = so$eicosenoic, y = so$linoleic, col = "red", pch = 16, cex = 1)

previsao <-c()
for (j in 1:nrow(azeite)){
  if(teste$eicosenoic[j] > 0.1 ){
    previsao[j] <- "Southern Italy"
  }
  else{
    if(teste$linoleic[j] > 10.5){
      previsao[j] <- "Sardinia"
    }else{
      previsao[j] <- "Northern Italy"
    }
  }
}
previsao
mean(previsao == azeite$region)




