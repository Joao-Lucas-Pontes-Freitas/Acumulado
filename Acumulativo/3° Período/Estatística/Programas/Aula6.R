iris
str(iris)
levels(iris$Species)
iris[34,]

indices <- sample(1:nrow(iris), size = nrow(iris), replace = FALSE)

iris <- iris[indices,]

head(iris)
tail(iris)

n <- round(nrow(iris)*0.8)
n
treinamento <- iris[1:n,]
teste <- iris[(n+1):nrow(iris),]

summary(treinamento)

x <- c(5,2,10,7,3)
sort(x)

table(treinamento$Species)

barplot(table(treinamento$Species), ylim = c(0,50), 
        names.arg = c("setosa","versicolor","virginica"), col = c("#8429c1","#3c43fa","red"), 
        main = "Especies Iris")

hist(treinamento$Petal.Length, breaks = 30, xlab = "tamanho da pétala", 
     main = "histograma tamanho da pétala", ylab = "frequência", col = c("#8429c1","#3c43fa","red"))

setosa <- treinamento[treinamento$Species == "setosa",]
versicolor <- treinamento[treinamento$Species == "versicolor",]
virginica <- treinamento[treinamento$Species == "virginica",]


par(mfrow = c(2,3))

hist(setosa$Petal.Length, xlab = "tamanho da pétala setosa", 
     main = "histograma tamanho da pétala setosa", ylab = "frequência", col = c("#8429c1"#,"#3c43fa","red"
       ), xlim = c(0,7), ylim = c(0,20))

hist(versicolor$Petal.Length, xlab = "tamanho da pétala versicolor", 
     main = "histograma tamanho da pétala versicolor", ylab = "frequência", col = c("#8429c1"#,"#3c43fa","red"
       ),xlim = c(0,7), ylim = c(0,20))

hist(virginica$Petal.Length, xlab = "tamanho da pétala virginica", 
     main = "histograma tamanho da pétala virginica", ylab = "frequência", col = c("#8429c1"#,"#3c43fa","red"
       ), xlim = c(0,7), ylim = c(0,20))



hist(setosa$Petal.Width, xlab = "tamanho da pétala setosa", 
     main = "histograma tamanho da pétala setosa", ylab = "frequência", col = c("#8429c1"#,"#3c43fa","red"
     ), xlim = c(0,3), ylim = c(0,30))

hist(versicolor$Petal.Width, xlab = "tamanho da pétala versicolor", 
     main = "histograma tamanho da pétala versicolor", ylab = "frequência", col = c("#8429c1"#,"#3c43fa","red"
     ),xlim = c(0,3), ylim = c(0,30))

hist(virginica$Petal.Width, xlab = "tamanho da pétala virginica", 
     main = "histograma tamanho da pétala virginica", ylab = "frequência", col = c("#8429c1"#,"#3c43fa","red"
     ), xlim = c(0,3), ylim = c(0,30))


par(mfrow = c(1,1))
plot(x = treinamento$Petal.Length, y = treinamento$Petal.Width, pch = 16, type = "n")
points(x = setosa$Petal.Length, y = setosa$Petal.Width, col = "#8429c1", pch = 16, cex = 3)
points(x = versicolor$Petal.Length, y = versicolor$Petal.Width, col = "#3c43fa", pch = 16, cex = 3)
points(x = virginica$Petal.Length, y = virginica$Petal.Width, col = "red", pch = 16, cex = 3)

abline(h = 1.6)

previsao <-c()
for (j in 1:30){
  if(teste$Petal.Length[j] < 2.5){
    previsao[j] <- "setosa"
  }
  else{
    if(teste$Petal.Width[j] > 1.6){
      previsao[j] = "virginica"
    }else{
      previsao[j] <- "versicolor"
    }
  }
}

previsao

mean(previsao == teste$Species)

previsao <-c()
for (j in 1:150){
  if(iris$Petal.Length[j] < 2.5){
    previsao[j] <- "setosa"
  }
  else{
    if(iris$Petal.Width[j] > 1.6){
      previsao[j] = "virginica"
    }else{
      previsao[j] <- "versicolor"
    }
  }
}

previsao

mean(previsao == iris$Species)




