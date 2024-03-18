pinguim <- read.table(file = "pinguim.txt", header = TRUE, sep = ",")
str(pinguim)

indices <- sample(1:nrow(pinguim), size = nrow(pinguim), replace = FALSE)

pinguim <- pinguim[indices,]

pinguim <- na.omit(pinguim)

which(pinguim$sex == ".")
pinguim <- pinguim[-which(pinguim$sex == "."), ]


n <- round(nrow(pinguim)*0.8)
n
treinamento <- pinguim[1:n,]
teste <- pinguim[(n+1):nrow(pinguim),]

ad <- treinamento[treinamento$species == "Adelie",]
ch <- treinamento[treinamento$species == "Chinstrap",]
ge <- treinamento[treinamento$species == "Gentoo",]

previsao <-c()
for (j in 1:nrow(teste)){
  if(teste$island[j] == "Torgersen" || (teste$island[j] == "Biscoe" && teste$flipper_length_mm[j] < 203) || (teste$island[j] == "Dream"  && teste$culmen_length_mm[j] <= 44.1) ){
    previsao[j] <- "Adelie"
  }
  else{
    if(teste$island[j] == "Biscoe"){
      previsao[j] <- "Gentoo"
    }else{
      previsao[j] <- "Chinstrap"
    }
  }
}

previsao <- c()
for(j in 1:nrow(teste)) {
  if(teste$island[j] == "Torgersen") {
    previsao[j] <- "Adelie"
  } else {
    if(teste$island[j] == "Biscoe") {
      if (teste$flipper_length_mm[j] >= 203) {
        previsao[j] <- "Gentoo"
      }else {
        previsao[j] <- "Adelie"
      }
    }else{
      if (teste$culmen_length_mm[j] > 44.5) {
        previsao[j] <- "Chinstrap"
      } else {
        previsao[j] <- "Adelie"
      }
    }
  }
}

mean(previsao == teste$species)
