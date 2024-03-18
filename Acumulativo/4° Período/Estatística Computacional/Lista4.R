# Instale os pacotes necessários se ainda não estiverem instalados
install.packages("agricolae")
install.packages("easyanova")

# Carregue os pacotes
library(agricolae)
library(easyanova)

# Entrada dos dados para análise
trat <- as.factor(rep(seq(1:4), e = 5))
bloco <- as.factor(rep(c('I', 'II', 'III', 'IV', 'V'), 4))
resist <- scan(dec = ",", nmax = 20, text = "
1,3 1,6 0,5 1,2 1,1
2,2 2,4 0,4 2,0 1,8
1,8 1,7 0,6 1,5 1,3
3,9 4,4 2,0 4,1 3,4")
dados <- data.frame(trat, bloco, resist)

# Modelo Estatístico
mod <- aov(resist ~ trat + bloco)

# Teste de Tukey com agricolae
tukey_result <- HSD.test(mod, "trat", console = TRUE)

# Plot dos resultados do teste de Tukey
plot(tukey_result, las = 1, col = 'blue')

# Realizar análise de variância com easyanova
ea1(dados, design = 2)









# Entrada dos dados para análise
trat <- as.factor(rep(seq(1:4),e=5))
bloco <- as.factor(rep(c('I','II','III','IV','V'),4))
resist <- scan(dec=",",nmax = 20,text = "
1,3 1,6 0,5 1,2 1,1
2,2 2,4 0,4 2,0 1,8
1,8 1,7 0,6 1,5 1,3
3,9 4,4 2,0 4,1 3,4")
dados <- data.frame(trat,bloco,resist)


# Modelo Estatístico
mod <- aov(resist ~ trat + bloco)
# Pressuposições do modelo
## Teste de normalidade
shapiro.test(mod$res)
## Teste de homogeneidade de variâncias
bartlett.test(mod$res~trat)
# Análise de Variância
anova(mod)








