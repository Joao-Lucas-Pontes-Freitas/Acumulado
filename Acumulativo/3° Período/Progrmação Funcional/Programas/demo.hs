imprime :: IO()
imprime = putStrLn "hello world!"
feio = putStrLn "pp é feio"

dobro :: Int -> Int
dobro x = 2*x

potencia :: Int -> Int -> Int
potencia x y = x^y

enzo = putStrLn "é manco"

quad :: Int -> Int
quad x = dobro(dobro x)

soma2 :: Int -> Int -> Int
soma2 x y = x+y

soma4 :: Int -> Int -> Int -> Int -> Int
soma4 w x y z = soma2 (soma2 w x) (soma2 y z)

hipotenusa :: Float -> Float -> Float
hipotenusa a b = sqrt ((a^2)+(b^2))

raiz :: Float -> Float -> Float
raiz y x = x**(1/y)

square_1:: Int -> Int
square_1 x = 3*x

sub :: Float -> Float -> Float
sub x y = x - y

area :: Float -> Float
area r = pi*(r**2)

composta :: Float -> Float -> Float
composta x y = sub (area x) (area y)
