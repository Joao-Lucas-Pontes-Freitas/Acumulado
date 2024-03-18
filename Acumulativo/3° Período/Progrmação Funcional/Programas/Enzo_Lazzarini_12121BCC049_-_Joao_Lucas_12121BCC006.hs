module Main (main) where

import System.IO ( stdout, hSetBuffering, BufferMode(NoBuffering) )

main :: IO ()
main = do hSetBuffering stdout NoBuffering
          menu

menu :: IO()
menu = do putStrLn "\n========================================="
          putStrLn "Banco Enzo Lazzarini e Joao Lucas Pontes"
          putStrLn "========================================="
          putStrLn "Opcoes:"
          putStrLn "1. Saldo"
          putStrLn "2. Extrato"
          putStrLn "3. Deposito"
          putStrLn "4. Saque"
          putStrLn "5. Fim"
          putStr "Escolha uma opcao: "
          opcao <- readLn
          case opcao of
               1 -> do { putStrLn "\n------" ;  putStr "Saldo: R$" ; imprime "saldo.txt" ; putStrLn "------" }
               2 -> do { putStrLn "\n------" ; putStrLn "Extrato:" ; putStrLn "----" ; imprime "extrato.txt" ; putStrLn "------" }
               3 -> do { putStrLn "\nDigite o valor do deposito: " ; valor <- getLine ; deposito (read valor) }
               4 -> do { putStrLn "\nDigite o valor do saque: " ; valor <- getLine ; saque (read valor) } 
               5 -> putStrLn "Obrigado por utilizar nosso banco!"
               _ -> putStrLn "Opcao inexistente!"
          if opcao /= 5 then menu else putStrLn "Saindo..."

imprime :: String -> IO()
imprime x = do conteudo <- readFile x
               putStrLn conteudo

deposito :: Float -> IO()
deposito x = do conteudo <- readFile "saldo.txt"
                putStrLn ("Saldo atual: " ++show (read conteudo + x))
                writeFile "saldo.txt" (show (read conteudo + x))
                appendFile "extrato.txt" ("\n+" ++ show x)

saque :: Float -> IO()
saque x = do saldo <- readFile "saldo.txt"
             putStrLn ("Saldo atual: " ++ show (read saldo - x))
             writeFile "saldo.txt" (show (read saldo - x)) 
             appendFile "extrato.txt" ("\n-" ++ show x)