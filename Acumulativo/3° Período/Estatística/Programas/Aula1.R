#comentário bacana sobre o enzo
# O R como calculadora
#para executar tudo: ctrl a + ctrl enter
#para executar só a linha atual: ctrl enter

3+3 #soma
3-2 #subtração
3*2 #multiplicação
3/2 #divisão
3**2 #potência
3^2 #potência
sqrt(9) #raiz
exp(1) # e elevado a 1
exp(2) # e elevado a 2
# quando quiser pesquisar no R como funciona a função execute ex: ?log
log(23,4) #log
log(b = 4, x = 23)

#atribuindo valores e as classes
a <- 3+2
A <- 3+2
a.2 <- 3+2
class(a.2)
w <- "palavra" #atribuição
class(w) #pede a clase

#definindo vetores, vetor só admite elementos de mesma clase
x <- c(5,5,3,2,1,1) #definindo vetor
x #printa o vetor
y <- c(x, "teste") #concatenação
y[6] #printa a sexta posição
x[c(2,4)]  #printa mais de uma posição diferente
x*2 #multiplicou tudo por inteiro
x*c(2,3) #multiplica alternando e só funciona para um número que é múltiplo do outro
x/c(2,3) #divide alternando e só funciona para um número que é múltiplo do outro
sum(x) #soma dos elementos
sum(x)/length(x) #conta média
mean(x) #função média
cumsum(x) #soma acumulada

#usando a função sample (sorteio)
dado <- sample(x = 1:6, size = 200000, replace = TRUE) #sorteio de 1 a 6, 20x, podendo repetir o número
saiu_6 <- dado == 6 #ciar um vetor lógico do mesmo tmanho do sorteio que compara o valor sorteado com o 6 e preenche com TRUE e FALSE, TRUE vale 1 e FALSE vale 0
sum(saiu_6) #soma pra saber o número de vezes que siram 6
mean(saiu_6) #proporção de vezes que sai o 6
#valor do dado < 4
dado < 4
mean(dado < 4)
dado[dado<4]
#dados iguis
dado1 <- sample(1:6, size = 1000, replace = TRUE)
dado2 <- sample(1:6, size = 1000, replace = TRUE)
dado1 == dado2
sum(dado1 == dado2)
mean(dado1 == dado2)
#replce tem que ser SEMPRE TRUE quando tem mais repetições do que elementos
sample(x = 1:3, size = 10, prob = c(5,2,1), replace = TRUE) #sorteio de 1 a 3, 10x, com probabilidade específica para cada número
sample(10)
set.seed(0953)

#moeda
moeda <- sample(x = c("cara", "coroa"), size = 10000, replace = TRUE)
saiu_cara <- moeda == "cara"
saiu_cara
sum(saiu_cara)
media_acumulada <- cumsum(saiu_cara)/1:10000 #valores acumulados da média 
plot(x = 1:10000, y = media_acumulada, type = "l") #desenha gráfico de linha
abline(h = 0.5, col = "red") #faz linha horizontal para marcar a média
mean(saiu_cara)















