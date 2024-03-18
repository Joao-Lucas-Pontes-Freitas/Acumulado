palindromo :: IO()
palindromo = do putStrLn("Digite uma frase: ")
                frase <- getLine
                if frase == reverse frase
                then putStrLn("É palindromo")
                else putStrLn("Não é palindromo")


imprime :: IO()
imprime = do putStrLn("Digite três números float: ")
             num1 <- readLn
             num2 <- readLn
             num3 <- readLn
             putStrLn("O resultado eh: " ++ show(mult num1 num2 num3))

mult :: Float -> Float -> Float -> Float
mult x y z = x*y*z


celsius :: Double -> Double
celsius f = (5/9)*(f-32)

conversao :: IO()
conversao = do putStr("Digite uma temperatura: ")
               num1 <- readLn
               putStrLn("A temperatura em celsius é: "++ show(celsius num1))

aluno :: IO()
aluno = do putStrLn("Digite as tres notas do aluno: ")
           num1 <- readLn
           num2 <- readLn
           num3 <- readLn
           let z = (num1+num2+num3)/3 in media z
           

media :: Float -> IO()
media z
 |z < 3 = putStrLn("Reprovado com média = " ++ show(z))
 |z < 7 = putStrLn("Exame especial com média = " ++ show(z))
 |otherwise = putStrLn("Aprovado com média = " ++ show(z))


classe :: IO()
classe = do putStrLn("Digite a idade: ")
            num1 <- readLn
            let z = num1 in eleitor z
           

eleitor :: Int -> IO()
eleitor z
 |z < 16 = putStrLn("Não eleitor")
 |z < 18 || z > 65 = putStrLn("Eleitor facultativo")
 |otherwise = putStrLn("Elitor obrigatório")

