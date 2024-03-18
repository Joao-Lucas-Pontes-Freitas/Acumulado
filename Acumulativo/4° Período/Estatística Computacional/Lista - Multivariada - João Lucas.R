# 6

dados <- data.frame(
  Importancia = c(10.85, 14.13, 8.62, 23.04, 16.04, 43.74, 25.39, 42.86),
  SalarioMedio = c(1500.80, 1496.07, 1448.79, 1277.33, 1204.02, 1190.94, 1292.91, 1590.66),
  ConsumoMedio = c(149.35, 187.99, 130.97, 424.87, 214.36, 1139.52, 358.39, 721.90)
)

# Padronizar os dados
dados <- scale(dados)

# a) Calculando autovalores e autovetores por meio da correlação
R <- cor(dados)
autoR <- eigen(R)
cat("\na) Autovalores:\n")
autoR$values
cat("\na) Autovetores:\n")
autoR$vectors

# b) Mostrando a expressão de cada componente por meio do princomp
pca2 = princomp(dados, cor = TRUE)
cat("\nb) Expressão de cada componente:\n")
pca2$loadings

# c) Porcentagem de Variância
summary_pca <- summary(pca2)
cat("\nc) Porcentagem Variância Para Cada Componente:\n")
proporcao <- summary_pca$sdev^2 / sum(summary_pca$sdev^2)
proporcao

# d) Número de componentes para explicar 95% da variância
n <- sum(cumsum(proporcao) < 0.95) + 1
cat("\nd) Número de componentes:", n, "\n")

# e) Variáveis mais importantes nos componentes retidos
n1 <- n
cat("\ne) Variáveis Mais Importantes nos Componentes Retidos:\n")
variaveis_importantes <- apply(pca2$loadings[, 1:n1], 2, function(x) colnames(dados)[which.max(x)])
print(variaveis_importantes)

# f) Scores para cada Cliente
scores_componente1 <- pca2$scores[, 1]
resultado <- data.frame(Score_Componente_1 = scores_componente1)

cat("\nf) Scores:\n")
print(resultado)

# Os scores negativos que aconteceram nos casos dos clientes 1, 2, 3, 5 indicam 
# que os scores de Salário Médio, que tem influência negativa na primeira 
# componente principal, foram maiores que os das outras duas variavés 
# (Importância e Cosnumo Médio). Da mesma forma que scores positivos dos casos
# 4, 6, 7, 8 indicam que os scores de Salário Médio foram menores que das outras

# 7) Agrupamento k médias com 2 grupos

agp <- kmeans(dados,2)
agp$cluster
membros <- agp$cluster
result <- cbind(leg, membros)
result
plot(dados,col= agp$cluster)
