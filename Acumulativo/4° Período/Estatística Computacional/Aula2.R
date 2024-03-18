
#Exemplo Academia Regress?o Linear

attach(exemploAcademia)
names(exemploAcademia)
modelo1 <- lm(G ~ Kw + H)
summary(modelo1)
anava <- aov(modelo1)
summary(anava)


#valor tebelado com 5% de signific?ncia, 2 e 12 como Graus de liberdade
qf(0.95, 2, 12)
#p valor, se for menor que a signific?ncia, rejieta Ho e o modelo ? significante em pelo menos uma vari?vel
1 - pf(50.18, 2, 12)

par(mfrow = c(2,2))
plot(modelo1)
names(modelo1)
par(mfrow = c(1,2))
plot(Kw, modelo1$residuals)
res_pad <- scale(modelo1$residuals)
plot(Kw, res_pad, pch = 16, col = "purple")
plot(H, res_pad, pch = 16, col = "red")
par(mfrow = c(1,1))
plot(modelo1$fitted.values, res_pad, pch = 16, col = "blue")

shapiro.test(modelo1$residuals)


#Exemplo Cirurgia Regress?o Log?sitca

attach(dadoscirurgia)
m1 <- glm(Y ~ X2 + X1, family = binomial(link = "logit"))
summary(m1)
plot(m1)

B2 <- -2.42743
B1 <- 0.13891
#odds Ratio

OR1 <- exp(B1) # vari?vel tempo de experi?ncia
OR2 <- exp(B2) # vari?vel homem ou mulher






attach(exemploAcademia)
X <- exemploAcademia$Kw
Y <- exemploAcademia$G
Z <- exemploAcademia$H
N <- length(Y)


# letra a)
X <- cbind(1, X, Z)
X_transposta_X <- t(X) %*% X
inversa <- solve(X_transposta_X)
X_transposta_Y <- t(X) %*% Y
X_transposta_Y
inversa


# letra b)
beta <- inversa %*% X_transposta_Y
beta0 <- beta[1,1]
beta1 <- beta[2,1]
beta2 <- beta[3,1]
beta0
beta1
beta2

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
Pvalor

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
attach(exemploAcademia)
modelo1 <- lm(G ~ Kw + H)
summary(modelo1)
anava <- aov(modelo1)
summary(anava)





















