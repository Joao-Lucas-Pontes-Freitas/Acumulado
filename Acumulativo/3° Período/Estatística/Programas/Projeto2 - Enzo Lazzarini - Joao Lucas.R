#a
papagaio <- read.table(file = "papagaio.txt", header = TRUE, sep = ",")
str(papagaio) #indica as 3 vari�voies n�mericas observadas e a �specie
head(papagaio) #mostra os 6 primeros elementos da amostra e indica de que as espec�es est�o misturadas
tail(papagaio) #mostra os 6 �ltimos elementos da amostra e indica de que as espec�es est�o misturadas
summary(papagaio) #apresenta informa��es b�scias sobre os extremos e concetra��o dos valores num�ricos

#b
hist(papagaio$tamanho) #indica uma contra��o de tamanho entre 30-40 e poucos entre 0-20 e acima de 55
hist(papagaio$peso) #indica uma concetra��o de peso entre 400-800 com pico entre 600-700 e muito poucos acima de 1300
hist(papagaio$envergadura) #indica uma concetra��o de envergadura entre 50-65 e poucos entre 0-40 e acima de 80

#c e f
ar <- papagaio[papagaio$especie == "arctica",]
ci <- papagaio[papagaio$especie == "cirrhata",]
co <- papagaio[papagaio$especie == "corniculata",]

#arctica m�dia e desvio padr�o
mean(ar$tamanho)
mean(ar$peso)
mean(ar$envergadura)
sd(ar$tamanho)
sd(ar$peso)
sd(ar$envergadura)
#cirrhata m�dia e desvio padr�o
mean(ci$tamanho)
mean(ci$peso)
mean(ci$envergadura)
sd(ci$tamanho)
sd(ci$peso)
sd(ci$envergadura)
#corniculata m�dia e desvio padr�o
mean(co$tamanho)
mean(co$peso)
mean(co$envergadura)
sd(co$tamanho)
sd(co$peso)
sd(co$envergadura)

#d
boxplot(ar$peso,ci$peso,co$peso) #o peso das arcticas � muito menor que o das outras duas, uma vez que todas as arcticas 
#s�o mais leves que todas as cirrhatas e mais leves que metade das corniculata. As mais pesadas s�o as cirrhatas, que 
#apresentam metade das aves acima de 100% das arcticas e 75% das corniculata. Entretanto, mesmo que haja diferen�as de peso, 
#todas as esp�cies apresentem alguma ave de uma mesma faixa de peso, o que torna dif�cil diferenci�-las por meio deste atributo.

#e
plot(x = papagaio$peso, y = papagaio$tamanho, type = "n")
points(x = ar$peso, y = ar$tamanho, pch = 16, col = "green")
points(x = ci$peso, y = ci$tamanho, pch = 16, col = "blue")
points(x = co$peso, y = co$tamanho, pch = 16, col = "red")
#ao analisar o peso e o tamanho das aves � dif�cil diferenci�-las, pois em um mesmo intervalo de peso e tamanho existem muitas
#aves de todas as esp�cies, n�o sendo poss�vel separ�-las por meio da rela��o entre peso e tamanho. Um exemplo disso � o 
#intervalo de peso 200-600 e altura 0-40, onde h� um amontoado de indiv�duos das 3 esp�cies diferentes. Entretanto,� poss�vel 
#perceber que as cores verde e azul (arctica e cirrhata) est�o mais espalhados entre si do que os pontos vermelhos(corniculata) 
#que parecem obedecer mais uma linearidade. Essa impress�o fornecida pelo gr�fico ser� confirmada a partir doscoeficientes 
#de correla��o encontrados na quest�o g.

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
print("O maior coeficiente � o da esp�cie corniculata")

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










