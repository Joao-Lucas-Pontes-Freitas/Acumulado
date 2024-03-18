attach(dadosvendas)
X <- dadosvendas$X
Y <- dadosvendas$Y
Z <- dadosvendas$Z
N <- length(Y)


# letra a)
matriz_X <- cbind(1, X, Z)
X_transposta_X <- t(matriz_X) %*% matriz_X
inversa <- solve(X_transposta_X)
X_transposta_Y <- t(matriz_X) %*% Y



# letra b)
beta <- inversa %*% X_transposta_Y
beta0 <- beta[1,1]
beta1 <- beta[2,1]
beta2 <- beta[3,1]

# letra c)
p <- nrow(beta)
GL_reg <- p - 1
GL_erro <- N - p
SQ_total <- sum(Y*Y) - X_transposta_Y[1,1]*X_transposta_Y[1,1]/N
SQ_reg <- t(beta) %*% X_transposta_Y - X_transposta_Y[1,1]*X_transposta_Y[1,1]/N
SQ_erro <- SQ_total - SQ_reg
QM_reg <- SQ_reg/GL_reg
QM_erro <- SQ_erro/GL_erro
Fcal <- QM_reg / QM_erro

# letra d)
Ftab <- qf ((1-0.05), GL_reg, GL_erro)
Pvalor <- 1 - pf(Fcal,GL_reg, GL_erro)

# letra e) 
Var0 <- inversa[1,1]
Var1 <- inversa[2,2]
Var2 <- inversa[3,3]
SB0 <- sqrt(Var0*QM_erro)
SB1 <- sqrt(Var1*QM_erro)
SB2 <- sqrt(Var2*QM_erro)
t0 <- beta0 / SB0
t1 <- beta1 / SB1
t2 <- beta2 / SB2
lim_inferior <- qt((0.05/2), GL_erro)
lim_superior <- qt((1 - 0.05/2), GL_erro)

# letra f)
attach(dadosvendas)
modelo1 <- lm(Y ~ X + Z)
summary(modelo1)
anava <- aov(modelo1)
summary(anava)






Y <- dadosSinistro$Sinistro
X1 <- dadosSinistro$Idade
X2 <- dadosSinistro$ECivil
X3 <- dadosSinistro$Sexo
m1 <- glm(Y ~ X1 + X2 + X3, family = binomial(link = "logit"))
summary(m1)

B3 <- 3.70268
B2 <- -3.62511
B1 <- -0.18957
B0 <- 3.78103

#odds Ratio
OR1 <- exp(B1) 
OR2 <- exp(B2) 
OR3 <- exp(B3)

func <- 1 / (1 + exp(-(B0 + B1 * 25 + B2 * 1 + B3 * 0)))*100
func



Y <- dadosTreinamento$Reacao
X1 <- dadosTreinamento$idade
X2 <- dadosTreinamento$escolaridade
X3 <- dadosTreinamento$sexo
m1 <- glm(Y ~ X1 + X2 + X3, family = binomial(link = "logit"))
summary(m1)

B3 <- 4.5705
B2 <- 1.6425
B1 <- -0.2314
B0 <- -10.5877

#odds Ratio

OR1 <- exp(B1) 
OR2 <- exp(B2) 
OR3 <- exp(B3)

func <- 1 / (1 + exp(-(B0 + B1 * 25 + B2 * 0 + B3 * 0)))*100
func



