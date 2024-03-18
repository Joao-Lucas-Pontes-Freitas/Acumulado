#data frame
#arquivo murders
dados <- read.csv(file = "murders.csv", header = TRUE)
dados2 <- read.table(file = "murders1.txt", header = TRUE, sep = ",")
str(dados)
summary(dados)
dados[c(2,27),4]
dados[,5]
mean(dados[,5])
dados$total
mean(dados$total)
max(dados$total)
dados[dados$total == min(dados$total),]
dados$total == max(dados$total)
dados[dados$total == max(dados$total),]
dados$state[dados$total == max(dados$total)]
dados[which(dados$total == max(dados$total)),]
dados[which(dados$total == min(dados$total)),]



max(dados$total/dados$population)

#vetor <- c()
#for (i in 1:51){
#  vetor[i] = dados[i, 5] * 100000 / dados[i, 4]
#}
#vetor

dados$rate <- 100000 * dados$total / dados$population
dados$region == "South"
sul <- dados[dados$region == "South", ]
sul

write.table(dados, file = "mortes.txt", sep = ",", row.names = FALSE)

dados[which(dados$rate == max(dados$rate)),]
dados[which(dados$rate == min(dados$rate)),]
dados$rate <- round(dados$rate, digits = 2)
dados[order(dados$rate),]











