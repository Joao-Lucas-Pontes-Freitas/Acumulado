# Dados
dados <- data.frame(
  Cliente = c(1, 2, 3, 4, 5, 6, 7, 8),
  Importancia = c(10.85, 14.13, 8.62, 23.04, 16.04, 43.74, 25.39, 42.86),
  SalarioMedio = c(1500.80, 1496.07, 1448.79, 1277.33, 1204.02, 1190.94, 1292.91, 1590.66),
  ConsumoMedio = c(149.35, 187.99, 130.97, 424.87, 214.36, 1139.52, 358.39, 721.90)
)

# Padronizar as variáveis
dados_padronizados <- scale(dados[, -1])

# Ponto específico
ponto_especifico <- c(1.476, 0.103, 1.463)

# Calcular distâncias euclidianas entre o ponto específico e todos os clientes
distancias_ponto_especifico <- sqrt(rowSums((dados_padronizados - ponto_especifico)^2))

# Exibir as distâncias
print("Distâncias entre o Ponto Específico e Todos os Clientes:")
a <- as.matrix(distancias_ponto_especifico)


# Calcular distâncias euclidianas entre todos os clientes
distancias <- dist(dados_padronizados)
distancias <- as.matrix(distancias)

# Exibir a matriz de distâncias
print("Matriz de Distâncias:")
print(max(distancias))


# Análise de Componentes Principais (PCA)
pca_resultado <- prcomp(dados_padronizados, center = TRUE, scale = TRUE)

# a) Autovalores e Autovetores
autovalores <- pca_resultado$sdev^2
autovetores <- pca_resultado$rotation

# Exibir autovalores
print("Autovalores:")
print(autovalores)

# Exibir autovetores
print("Autovetores:")
print(autovetores)

# b) Expressão de cada componente
expressao_componentes <- pca_resultado$rotation
print("Expressão de Cada Componente:")
print(expressao_componentes)

# c) Porcentagem da variância explicada por cada componente
porcentagem_variancia <- pca_resultado$sdev^2 / sum(pca_resultado$sdev^2) * 100
print("Porcentagem da Variância Explicada por Cada Componente:")
print(porcentagem_variancia)

# d) Número de componentes a serem mantidos ou descartados
grafico_variancia <- plot(pca_resultado, type = "l", main = "Porcentagem da Variância Explicada", col = "blue")
abline(h = 70, col = "red", lty = 2)  # Linha de corte em 70%

# e) Variáveis mais importantes dentro dos componentes retidos
variaveis_importantes <- pca_resultado$rotation[, 1]  # Considerando o primeiro componente
print("Variáveis Mais Importantes:")
print(variaveis_importantes)

# f) Scores do componente mais importante
scores_componente <- pca_resultado$x[, 1]  # Considerando o primeiro componente
print("Scores do Componente Mais Importante:")
print(scores_componente)

# Análise de Agrupamento (Hierárquico)
distancia_euclidiana <- dist(dados_padronizados)
dendrograma_euclidiano <- hclust(distancia_euclidiana, method = "centroid")
plot(dendrograma_euclidiano, main = "Dendrograma - Distância Euclidiana")

# b) Método de Ward
dendrograma_ward <- hclust(distancia_euclidiana, method = "ward.D2")
plot(dendrograma_ward, main = "Dendrograma - Método de Ward")

# c) K-médias
kmeans_resultado <- kmeans(dados_padronizados, centers = 2)
print("Grupos Obtidos pelo Método das K-médias:")
print(kmeans_resultado$cluster)












# Exemplo de dados
dados <- data.frame(
  X1 = c(7, 4, 4, 5),
  X2 = c(3, 6, 2, 5),
  X3 = c(9, 11, 5, 7)
)

# Padronizar os dados
dados_padronizados <- scale(dados)

# Exibir os dados padronizados
print("Dados Padronizados:")
print(dados_padronizados)


# Calcular a matriz de covariância simétrica
matriz_cov_simetrica <- cov(dados)
matriz_cov_simetrica

matriz_cov_simetrica <- cov(dados_padronizados)
matriz_cov_simetrica