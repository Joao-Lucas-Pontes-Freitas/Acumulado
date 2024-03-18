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

dados1 <- c(4,5,5,6,6,6,7,7,8)
dados2 <- c(2,3,3,6,6,6,9,9,10)
dados3 <- c(2,5,5,6,6,6,7,7,10)
table(dados1)
#variância e desvio padrão
var(dados1)
var(dados2)
var(dados3)
sd(dados1)
sd(dados2)
sd(dados3)


ad <- treinamento[treinamento$species == "Adelie",]
ch <- treinamento[treinamento$species == "Chinstrap",]
ge <- treinamento[treinamento$species == "Gentoo",]
var(ad$body_mass_g)
var(ch$body_mass_g)
var(ge$body_mass_g)
sd(ad$body_mass_g)/mean(ad$body_mass_g)*100
sd(ch$body_mass_g)/mean(ch$body_mass_g)*100
sd(ge$body_mass_g)/mean(ge$body_mass_g)*100



plot(x = treinamento$culmen_length_mm, y = treinamento$culmen_depth_mm, type = "n")
points(x = ad$culmen_length_mm, y = ad$culmen_depth_mm, pch = 16, col = "green")
points(x = ch$culmen_length_mm, y = ch$culmen_depth_mm, pch = 16, col = "blue")
points(x = ge$culmen_length_mm, y = ge$culmen_depth_mm, pch = 16, col = "red")

plot(x = treinamento$island, y = treinamento$flipper_length_mm, type = "n")
points(x = ad$island, y = ad$flipper_length_mm, pch = 16, col = "green")
points(x = ch$island, y = ch$flipper_length_mm, pch = 16, col = "blue")
points(x = ge$island, y = ge$flipper_length_mm, pch = 16, col = "red")


distancia <- function(x,y){
  return (sqrt(sum((x-y)**2)))
}

previsao <- c()
for(i in 1:nrow(teste)){
  distancias <- c()
  for(j in 1:nrow(treinamento)){
    distancias[j] <- distancia(teste[i,3:5], treinamento[j,3:5])
  }
  previsao[i] <- as.character(treinamento$species[order(distancias)[1]])
}

mean(previsao == teste$species)






