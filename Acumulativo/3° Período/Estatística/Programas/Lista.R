#ex1 a
vetor <- c(seq(from = 1, to = 20))
vetor

#ex1 b
vetor <- c(seq(from = 20, to = 1))
vetor

#ex1 c
vetor <- c(seq(from = 1, to = 20), seq(from = 19, to = 1))
vetor

#ex1 d
vetor <- c(rep(c(4,6,3), times = 12))
vetor

#ex1 e
vetor <- c(rep(c(4,6,3), times = 12), 4)
vetor

#ex1 f
x <- seq(from = 3, to = 6, by = 0.1)
for(i in 1:(length(x))){
  y <- (2.718281**x[i]) * (cos(x[i])) 
  vetor[i] <- y
}
vetor

#ex2 a
soma <- 0
for(i in 10:100){
  soma <- soma + (i**3 + 4*(i**2))
}
soma

#ex2 b
soma <- 0
for(i in 10:25){
  soma <- soma + (((2**i)/i) + ((3**i)/i**2))
}
soma

#ex3 a
xVec <- sample(x = 0:999, size = 250, replace = T)
final <- c()
for(i in 1:250){
  if(i %% 2 == 1){
    final <- c(final, xVec[i])
  }
}
final

#ex3 b
yVec <- sample(x = 0:999, size = 250, replace = T)
xVec <- sample(x = 0:999, size = 250, replace = T)
final <- c()
for(i in 2:250){
  final <- c(final, (yVec[i] - xVec[i-1]))
}
final

#ex3 c
xVec <- sample(x = 0:999, size = 250, replace = T)
final <- c()
for(i in 3:250){
  final <- c(final, (xVec[i-2] + 2*xVec[i-1] - xVec[i]))
}
final

#ex4 a
yVec <- sample(x = 0:999, size = 250, replace = T)
final <- c()
for(i in 1:250){
  if(yVec[i] > 600){
    final <- c(final, i)
  }
}
final

#ex4 b
yVec <- sample(x = 0:999, size = 250, replace = T)
final <- c()
for(i in 1:250){
  if(yVec[i] > 600){
    final <- c(final, yVec[i])
  }
}
final

#ex4 c
xVec <- sample(x = 0:999, size = 250, replace = T)
m <- mean(xVec)
final <- c()
for(i in 1:250){
  final <- c(final, (abs(xVec[i]-m))**(1/2))
}
final

#ex4 d
yVec <- sample(x = 0:999, size = 250, replace = T)
final <- c((abs(yVec - maxi)))
sum(final < 200)

#ex4 e
xVec <- sample(x = 0:999, size = 250, replace = T)
final <- c(xVec %% 2 == 0)
sum(final)

#ex4 f
yVec <- sample(x = 0:999, size = 250, replace = T)
i <- 1
final <- c()
while(i <= 250){
  final <- c(final, yVec[i])
  i <- i + 3
}
final

#x5
fibonacci <- function(n){
  vet_fibonacci <- c(1,1)
  if(n > 2){
    for(i in 3:n){
      vet_fibonacci[i] <- vet_fibonacci[i-1] + vet_fibonacci[i-2]
    }
    vet_fibonacci
  }else{
    print("Inválido")
  }
}
fibonacci(6)

#ex6
coelhos <- function(n, k){
  vet_coelhos <- c(1,1)
  if(n < 3){
    return (print("Inválido"))
  }
  for(i in 3:n){
    vet_coelhos[i] <- vet_coelhos[i-1] + k*vet_coelhos[i-2]
  }
  vet_coelhos[n]
}
coelhos(5,3)

#ex7
teste <- c()
for(j in 1:100000){
  c <- 0
  sorteio <- sample(1:4, size = 4, replace = FALSE)
  for(i in 1:4){
    if(sorteio[i] == i){
      c <- 1
    }
  }
  if(c == 1){
    teste[j] = 0
  }else{
    teste[j] <- 1
  }
}
100-sum(teste)/100000*100 #62,5% como resposta exata na teoria


#ex8
vetor <- seq(from = 1, to = 10, by = 1)
num.impar <- function(vetor){
  q <- 0
  for(i in 1:length(vetor)){
    if(vetor[i] %%2 != 0){
      q <- q+1
    }
  }
  return (q)
}
num.impar2 <- function(vetor){
  return (sum(vetor%%2 != 0))
}
vetor
num.impar(vetor)
vetor
num.impar2(vetor)

#ex9
v <- c()
for(i in 1:100000){
  x <- 0
  while(x == 0){
    sorteio <- sample(x = 1:6, size = 2, replace = TRUE)
    soma <- sum(sorteio)
    if(soma == 7 || soma == 11){
      x <- 1
      v[i] <- 1
    }else{
      if(soma == 2 || soma == 3 || soma == 12){
        x <- 1
        v[i] <- 0
      }else{
        while(x == 0){
          sorteio2 <- sample(x = 1:6, size = 2, replace = TRUE)
          if(sum(sorteio2) == soma){
            x <- 1
            v[i] <- 1
          }else{
            if(sum(sorteio2) == 7){
              x <- 1
              v[i] <- 0
            }
          }
        }
      }
    }
  }
}
sum(v)/100000*100 

#ex 10 a
Luke1 <- function(L, N){
  while(L != 0 & L != N){
    moeda <- sample(x = c("cara", "coroa"), size = 1, replace = TRUE)
    if(moeda == "cara"){
      L <- L + 1
    }else{
      L <- L - 1
    }
  }
  if(L == N){
    return (1)
  }else{
    return (0)
  }
}
if(Luke1(10,20) == 1){
  print("Casa")
}else{
  print("Precipício")
}

#ex 10 b
Luke2 <- function(L, N){
  v <- c()
  for(i in 1:100000){
    v[i] <- Luke1(L,N)
  }
  return(sum(v)/100000*100)
}
print(Luke2(0,20))

#ex 10 c
v <- c()
N <- 20
for(i in 1:N){
  v[i] <- Luke2(i,N)
}
plot(x = 1:20, y = v, type = "l", ylim = c(0,100), names.arg = c("mulheres","homens"), col = c("#8429c1"), 
     main = "Proporção de sucesso em chegar em casa")





