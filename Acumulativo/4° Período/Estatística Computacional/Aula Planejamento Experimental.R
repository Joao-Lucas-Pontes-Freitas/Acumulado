attach(algoritmos)

Ta <- sum(ecusto[alg == "A"])
Tb <- sum(ecusto[alg == "B"])
Tc <- sum(ecusto[alg == "C"])
Td <- sum(ecusto[alg == "D"])
Te <- sum(ecusto[alg == "E"])
Tf <- sum(ecusto[alg == "F"])

r <- 8
t <- 6

v_T <- c(Ta, Tb, Tc, Td, Te, Tf)
C <- sum(v_T)^2/t/r

SQTotal <- sum(ecusto^2) - C
SQTrat <- sum(v_T^2)/r - C
SQErro <- SQTotal - SQTrat

QMTrat <- SQTrat / 5
QMErro <- SQErro / 42

Fcal <- QMTrat / QMErro
Ftab <- qf(0.95, 5, 42)

# rejita H0, pelo menos uma média diferente

pvalor <- 1-pf(Fcal, 5, 42)


# jeito bom
Tratamento <- factor(alg)
y <- ecusto
m1 <- aov(y ~ Tratamento)
summary(m1)

TukeyHSD(m1, which='Tratamento', ordered=TRUE, conf.level=0.95)

# melhor jeito de ver diferenças entre médias
plot(TukeyHSD(m1, which='Tratamento', ordered=TRUE, conf.level=0.95)) 

pairwise.t.test(y,Tratamento)

# Análise fatorial
attach(eucalipto)
E <- factor(V1)
R <- factor(V2)
y5 <- V3

fat5 <- aov(y5 ~ E + R + E*R)

summary(fat5)

fat2.dic(E, R, y5, quali = c(TRUE, TRUE), 
         mcomp = "tukey", fac.names = c("Fac1", "Fac2"))

plot(fat5)

interaction.plot(E,R,y5)
interaction.plot(R,E,y5)






