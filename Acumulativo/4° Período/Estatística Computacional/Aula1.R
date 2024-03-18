C*y = b
b = array(c(0,1,5), dim=c(3,1))
C = matrix(c(c(1,1,0),c(0,1,4),c(0:2)),3,3,1)
y = solve(C,b)
Cinv <- solve(C)
Cinv%*%b
Cinv
y
teste <- read.table("banco.txt", header = T, sep=",")
teste
str(teste)
plot(teste)
summary(teste)
plot(teste$temp)
a <- 1:20
b <- a^2
plot(a,b)
plot(a,b, type = "l")
x <- c(201, 225,305, 380, 560, 600, 685, 735)
y <-c(17, 20, 21, 23, 25, 24, 27, 27)

m1<- lm(y ~ x )
m1
plot(m1)
summary(m1)
summary(aov(m1))

plot(x,y)
abline(m1)

x1<-c(1,2,3,4,5,6,7,8,9,10)
x2<-c(10,9,8,7,6,5,4,3,2,1)
y1 <-c(0,1,0,1,1,1,1,0,0,1)
mod1 <- glm(y1~x2+x1,family = binomial(link = "logit"))

summary(mod1)



