#ex1 
baleia <- read.table(file = "treino_baleias.txt", header = TRUE, sep = ",")
str(baleia)

teste <- read.table(file = "teste_baleias.txt", header = TRUE, sep = ",")

#exa
ba <- baleia[baleia$especie == "Baleia Azul",]
bf <- baleia[baleia$especie == "Baleia Fin",]
ca <- baleia[baleia$especie == "Cachalote",]
ju <- baleia[baleia$especie == "Jubarte",]

#exb
#varia�ncia
var(ba$peso)
var(bf$peso)
var(ca$peso)
var(ju$peso)

#desio padr�o
sd(ba$peso)
sd(bf$peso)
sd(ca$peso)
sd(ju$peso)

#m�dia
mean(ba$peso)
mean(bf$peso)
mean(ca$peso)
mean(ju$peso)

#coeficiente
#Baleias azuis tem peso mais concetrado perto da m�dia, ou seja varia, menos. 
#Enquanto cachalote tem peso mais distante da m�dia, variando mais.
sd(ba$peso)/mean(ba$peso)*100
sd(bf$peso)/mean(bf$peso)*100
sd(ca$peso)/mean(ca$peso)*100
sd(ju$peso)/mean(ju$peso)*100

#exc
summary(ca)
median(ca$volume_cranio)
#como existem um n�mero �mpar de baleias cachalote, o valor da mediana indica o valor central
#do veotr que cont�m o volume do cranio das cachalotes, indicando que existem uma mesma quantidade de
#baleias com um volume do cr�nio maior e menor do que o valor dessa mediana

#exd
hist(ba$peso)
#a maior parte das baleias azuis tem um peso contiodo no intervalo de 20000 e 21000
#e poucas baleias azuis tem pesos entre 16000-17000 e acima de 24000, 
# al�m de n�o exisitr no conjunto de dados uma baleia com peso entre 23000-24000

#exe
boxplot(ba$comprimento,bf$comprimento,ca$comprimento,ju$comprimento)
#obs essas afirma��es s� valem para o conjunto de treino
#as baleias azuis em sua maioria s�o todas maiores que as outras esp�cies
#as baleias fin s�o em geral maiores que cachalotes e jubartes, mas quase todas menores que as baleias azuis
#as baleias cachalote e jubarte apresentam comprimento bem parecido, uma vez que 50% das jubarte 
#est�o quse praticamente nas mesma faixa de valores que de comrpimento que 75% das cachalotes, com
#as diferen�as mais nos valores extremos de m�n e m�ximo

#exf
boxplot(ba$peso,bf$peso,ca$peso,ju$peso)
#obs essas afirma��es s� valem para o conjunto de treino
#as baleias azuis s�o todas mais pesadas que todas as outras baleias
#as baleias fin s�o todas mais leves que as baleias azuis e todas mais pesadas que todas as outras baleias
#50% das caclhaotes s�o mais pesadas que todas as baleis jubarte e os outros 50% tem o mesmo peso que as 25%
#jubartes mais pesadas

boxplot(ba$profundidade_maxima,bf$profundidade_maxima,ca$profundidade_maxima,ju$profundidade_maxima)
#obs essas afirma��es s� valem para o conjunto de treino
#50% das baleias azuis v�o a uma profunduade m�xima maior que de todas as oitras baleias, 
#os outros 50% est�o na mesma faixa que todas as baleias fin
#todas as baleias fin tem profundiade m�xima maior que as baleias jubarte e cachalote
#75% das baleias jubarte tem profundidade m�xima acima de todas as cachalotes

boxplot(ba$volume_cranio,bf$volume_cranio,ca$volume_cranio,ju$volume_cranio)
#obs essas afirma��es s� valem para o conjunto de treino
#todas as baleias azuis apresentam cranio maior que apriximadamente 75% das baleias fin, 
#e maior que todas de todas as outras esp�cies
#75% de todas as baleias fin tem cranio maior que todas as baleias cachalote e jubarte
#aproximandamente 50% das cachalotes tem cranio maior que todas as jubarte, os outros 50%
#est�o na mesma faixa que aproximandamente 75% das jubartes mais pesadas

#ex g
plot(x = baleia$comprimento, y = baleia$profundidade_maxima, type = "n")
points(x = ba$comprimento, y = ba$profundidade_maxima, pch = 16, col = "green")
points(x = bf$comprimento, y = bf$profundidade_maxima, pch = 16, col = "blue")
points(x = ca$comprimento, y = ca$profundidade_maxima, pch = 16, col = "red")
points(x = ju$comprimento, y = ju$profundidade_maxima, pch = 16, col = "purple")
abline(h = 210)
abline(h = 170)
abline(v = 27)

#exh
# analisando o gr�fico constru�do na quest�op anterior ficou n�tido alguns intervalos que poderiam ser
#utilzados para distin��o da esp�cie, uma vez que abaixo de 170 de profundidade m�xima amioria era cachalote
#e entre 170 e 210, maioria era jubrte, por fim, analisando o cumroimento das baleias, sa maiores s�o as azuis,
#logo a partir de um comrpimento 26, amioria � azul, podendo-se ent�o fazer as distin��es

#por fim, o resultado foi conisdervalemnte alto, uma vez que 94 em 100 baleias foi a taxa de acerto da esp�cie, 
#podendo-se melhorar com o uso de mias vari�veis ou ent�o de definir melhor os intervalos, entretanto, 
#deve-se tomar cuidaod para n�o fazer algo que funcione s� para o treinamento, o que torana a taxa de 94% 
#relevante para uma primeira vers�o

#ex i as linhas j� est�o demonstradas no gr�fico da g e foram usadas para ajudar a determinar os intervalos


previsao <-c()
for (j in 1:nrow(teste)){
  if(teste$profundidade_maxima[j] < 170 ){
    previsao[j] <- "Cachalote"
  }
  else{
    if(teste$profundidade_maxima[j] < 210){
      previsao[j] <- "Jubarte"
    }else{
      if(teste$comprimento[j] > 27){
        previsao[j] <- "Baleia Azul"
      }
      else{
        previsao[j] <- "Baleia Fin"
      }
    }
  }
}
mean(previsao == teste$especie)


#ex2
#uma simula��o 
x <- 0
vetorSteven <- c(0,1,0)
vetorGarnit <- c(0,0,1)
sorteio <- sample(x = 0:1, size = 3, replace = TRUE)
while(x == 0){
  print(sorteio)
  if(sum(sorteio == vetorSteven) == 3){
    print("Steven")
    x <- 1
  }else{
    if(sum(sorteio == vetorGarnit) == 3){
      print("Garnit")
      x <- 1
    }else{
      sorteio[1] <- sorteio[2]
      sorteio[2] <- sorteio[3]
      sorteio[3] <- sample(x = 0:1, size = 1, replace = TRUE)
    }
  }
}

#10 mil simula��es
vetorSteven <- c(0,1,0)
vetorGarnit <- c(0,0,1)
vetor <- c()

for(i in 1:10000){
  x <- 0
  sorteio <- sample(x = 0:1, size = 3, replace = TRUE)
  while(x == 0){
    if(sum(sorteio == vetorSteven) == 3){
      vetor[i] <- 0
      x <- 1
    }else{
      if(sum(sorteio == vetorGarnit) == 3){
        vetor[i] <- 1
        x <- 1
      }else{
        sorteio[1] <- sorteio[2]
        sorteio[2] <- sorteio[3]
        sorteio[3] <- sample(x = 0:1, size = 1, replace = TRUE)
      }
    }
  }
}
sum(vetor)/10000*100

#garnit tem uma maior porcetagem de vit�ria uma vez que quando o primeiro dos 3 sorteios � substitu�do,
# a sequ�ncia de steven est� mais sujeita a falha, uma vez que ao substituir uma casa, por exemplo, 
# caso o resultado tenha sido 0 0 0 do primeiro sorteio, ou seja, somente a �ltima casa errada para Garnit,
# � poss�vel que no primeiro sorteio repetido (quarta moeda) a seque�ncia de garnit d� certo, entretanto, 
# caso a sequ�ncia seja 0 1 1 do primeiro sorteio, � imposs�vel que um sorteio de a vit�ria pra ele, uma vez 
# que o 1 passar� para a primeira casa, ficando ( 1 1 x) e independemente do X sorteado, a sequ~encia estar� 
# errada pois come�ara com um 1



