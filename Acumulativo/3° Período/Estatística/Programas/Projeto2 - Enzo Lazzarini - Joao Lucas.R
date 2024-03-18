#a
papagaio <- read.table(file = "papagaio.txt", header = TRUE, sep = ",")
str(papagaio) #indica as 3 variávoies númericas observadas e a éspecie
head(papagaio) #mostra os 6 primeros elementos da amostra e indica de que as especíes estão misturadas
tail(papagaio) #mostra os 6 últimos elementos da amostra e indica de que as especíes estão misturadas
summary(papagaio) #apresenta informações báscias sobre os extremos e concetração dos valores numéricos

#b
hist(papagaio$tamanho) #indica uma contração de tamanho entre 30-40 e poucos entre 0-20 e acima de 55
hist(papagaio$peso) #indica uma concetração de peso entre 400-800 com pico entre 600-700 e muito poucos acima de 1300
hist(papagaio$envergadura) #indica uma concetração de envergadura entre 50-65 e poucos entre 0-40 e acima de 80

#c e f
ar <- papagaio[papagaio$especie == "arctica",]
ci <- papagaio[papagaio$especie == "cirrhata",]
co <- papagaio[papagaio$especie == "corniculata",]

#arctica média e desvio padrão
mean(ar$tamanho)
mean(ar$peso)
mean(ar$envergadura)
sd(ar$tamanho)
sd(ar$peso)
sd(ar$envergadura)
#cirrhata média e desvio padrão
mean(ci$tamanho)
mean(ci$peso)
mean(ci$envergadura)
sd(ci$tamanho)
sd(ci$peso)
sd(ci$envergadura)
#corniculata média e desvio padrão
mean(co$tamanho)
mean(co$peso)
mean(co$envergadura)
sd(co$tamanho)
sd(co$peso)
sd(co$envergadura)

#d
boxplot(ar$peso,ci$peso,co$peso) #o peso das arcticas é muito menor que o das outras duas, uma vez que todas as arcticas 
#são mais leves que todas as cirrhatas e mais leves que metade das corniculata. As mais pesadas são as cirrhatas, que 
#apresentam metade das aves acima de 100% das arcticas e 75% das corniculata. Entretanto, mesmo que haja diferenças de peso, 
#todas as espécies apresentem alguma ave de uma mesma faixa de peso, o que torna difícil diferenciá-las por meio deste atributo.

#e
plot(x = papagaio$peso, y = papagaio$tamanho, type = "n")
points(x = ar$peso, y = ar$tamanho, pch = 16, col = "green")
points(x = ci$peso, y = ci$tamanho, pch = 16, col = "blue")
points(x = co$peso, y = co$tamanho, pch = 16, col = "red")
#ao analisar o peso e o tamanho das aves é difícil diferenciá-las, pois em um mesmo intervalo de peso e tamanho existem muitas
#aves de todas as espécies, não sendo possível separá-las por meio da relação entre peso e tamanho. Um exemplo disso é o 
#intervalo de peso 200-600 e altura 0-40, onde há um amontoado de indivíduos das 3 espécies diferentes. Entretanto,é possível 
#perceber que as cores verde e azul (arctica e cirrhata) estão mais espalhados entre si do que os pontos vermelhos(corniculata) 
#que parecem obedecer mais uma linearidade. Essa impressão fornecida pelo gráfico será confirmada a partir doscoeficientes 
#de correlação encontrados na questão g.

#g
coeficiente <- function(x, y){
  n <- sum(x)/mean(x)
  soma <- sum(x*y)
  numerador <- soma - n*mean(x)*mean(y)
  x1 <- x*x
  y1 <- y*y
  denominador <- sqrt(sum(x1)-n*mean(x)*mean(x))*sqrt(sum(y1)-n*mean(y)*mean(y))
  return (numerador/denominador)
}
#teste com o exemplo do pib e carbono
x <- c(1.7, 1.2, 2.5, 2.8, 3.6, 2.2, 0.8, 1.5, 2.4, 5.9)
y <- c(552.6, 462.3, 475.4, 374.3, 748.5, 400.9, 253.0, 318.6, 496.8, 1180.6)
coeficiente(x,y)

#arctica coeficiente
c1 <- coeficiente(ar$tamanho, ar$peso)
c1
#cirrhata coeficiente
c2 <- coeficiente(ci$tamanho, ci$peso)
c2
#corniculata coeficiente
c3 <- coeficiente(co$tamanho, co$peso)
c3
print("O maior coeficiente é o da espécie corniculata")

#h
reta <- function(x, y){
  n <- sum(x)/mean(x)
  soma <- sum(x*y)
  numerador <- n*soma - sum(x)*sum(y)
  x1 <- x*x
  denominador <- n*sum(x1) - sum(x)*sum(x)
  m <- numerador/denominador
  b <- mean(y) - m*mean(x)
  retorno <- c(m, b)
  return (retorno)
}
#teste com o exemplo do pib e carbono
x <- c(1.7, 1.2, 2.5, 2.8, 3.6, 2.2, 0.8, 1.5, 2.4, 5.9)
y <- c(552.6, 462.3, 475.4, 374.3, 748.5, 400.9, 253.0, 318.6, 496.8, 1180.6)
reta(x,y)

#i
reta(co$peso, co$tamanho)

#j
tamanho <- function(peso){
  if(peso < 278 || peso > 1120.9)
    return(0)
  equacao <- reta(co$peso, co$tamanho)
  m <- equacao[1]
  r <- equacao[2]
  return (m*peso + r)
}
summary(co)
tamanho(500)
tamanho(1300)










