titanic <- read.table(file = "titanic.txt", header = TRUE, sep = ",")
titanic <- titanic[,-1]
str(titanic)

titanic$Survived <- as.factor(titanic$Survived)
str(titanic)
table(titanic$Survived)
prop.table(table(titanic$Survived)) #frequencia absoluta
round(prop.table(table(titanic$Survived)), digits = 2) #frequencia relativa

barplot(table(titanic$Survived), ylim = c(0,600), names.arg = c("morreram", "sobreviveram"), col = "#05cba6")
#ggplot

table(titanic$Sex)
barplot(table(titanic$Sex), ylim = c(0,600), names.arg = c("mulheres", "homens"), col = c("#8429c1","#3c43fa"), main = "Quantidade de mulheres e homens")
#ggplot

titanic$Pclass <- as.factor(titanic$Pclass)

table(titanic$Pclass)
barplot(table(titanic$Survived, titanic$Pclass), ylim = c(0,600),
        names.arg = c("1ª Classe","2ª Classe","3ª Classe"), col = c("#1566d1", "#04c1f2"),
        main = "Proporção de mortes por classe",
        args.legend = list(bty = "n" #x = right
                           ),
        legend.text = c("morreram", "sobreviveram"), cex.names = 1.3)
#ggplot

table(titanic$Survived, titanic$Sex)
barplot(table(titanic$Survived, titanic$Sex), ylim = c(0,600), 
        names.arg = c("mulheres","homens"), col = c("#8429c1","#3c43fa"), 
        main = "Proporção de mortes por sexo", 
        beside = TRUE,
        args.legend = list(bty = "n", #x = "right"
                           cex = 1.3),
        legend.text = c("morreram", "sobreviveram"), cex.names = 1.3)

homens <- titanic[titanic$Sex == "male", ]
mulheres <- titanic[!titanic$Sex == "male", ]

tabela_mulheres <- table(mulheres$Survived, mulheres$Pclass)
barplot(tabela_mulheres)

tabela_homens <- table(homens$Survived, homens$Pclass)
barplot(tabela_homens)

par(mfrow = c(1,2))



