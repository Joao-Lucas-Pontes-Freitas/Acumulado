xor :: Bool -> Bool -> Bool
xor a b = (a || b) && not (a && b)

xor1 :: Bool -> Bool -> Bool
xor1 a b = a /= b

xor2 :: Bool -> Bool ->Bool
xor2 a b = if(a /= b) then True else False

xor3 :: Bool -> Bool -> Bool
xor3 a b
    | a /= b = True
    | otherwise = False

par :: Int -> Bool
par x = if(mod x 2 == 0) then True else False

impar :: Int -> Bool
impar x = not (par x)

maior :: Float -> Float -> Float
maior x y
  |x > y = x
  |otherwise = y

menor :: Float -> Float -> Float
menor x y
  |x < y = x
  |otherwise = y

area :: Float -> Float
area d = pi*(r**2)
       where r = d/2

coeficientes :: Float -> Float -> Float -> Float
coeficientes a b c
  |z < 0 = 0
  |z > 0 = 2
  |otherwise = 1
  where z = (b**2)-4*a*c

menu :: Float -> Float -> Float -> Float
menu x y op =
    case op of
        1 -> x+y
        2 -> (maior x y) - (menor x y)
        3 -> x*y
        4 -> if(menor x y == 0) then -1 else (maior x y) / (menor x y)
        _ -> -1