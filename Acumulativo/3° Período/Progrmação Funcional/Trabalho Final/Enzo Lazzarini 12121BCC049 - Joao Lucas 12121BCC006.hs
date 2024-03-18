module Main (main) where

import System.IO ( stdout, hSetBuffering, BufferMode(NoBuffering) )
import Data.List
import Text.Printf

main :: IO ()
main = do hSetBuffering stdout NoBuffering
          menu
          putStrLn "Nota fiscal emitida no arquivo 'NotaFiscal.txt'!"

menu :: IO()
menu = let {    nova = criarLista (7, "Cheetos", 6.70) tabelaProdutos;
                nova2 = criarLista (8, "Coca", 8.93) nova;
                nova3 = removeElemento (004, "Sabao", 24.90) nova2; 
                nova4 = removeElemento (002, "Biscoito", 8.50) nova3;
                codigo = [1,4,7,3]}
          in notaFiscal nova codigo

type Codigo = Int
type Nome = String
type Preco = Float
type Produto = (Codigo, Nome, Preco) 

tabelaProdutos::[Produto]
tabelaProdutos = [ (001, "Chocolate", 5.25)
                 , (002, "Biscoito", 8.50)
                 , (003, "Laranja", 4.60)
                 , (004, "Sabao", 24.90)
                 , (005, "Batata Chips", 6.90)
                 , (006, "Doritos", 8.90)]

retiraCodigo :: Produto -> Codigo
retiraCodigo (x,_,_) = x

retiraNome :: Produto -> Nome
retiraNome (_,x,_) = x

retiraPreco :: Produto -> Preco
retiraPreco (_,_,x) = x
                       
criarLista :: Produto -> [Produto] -> [Produto]
criarLista x y = x:y

append :: Produto -> [Produto] -> [Produto]
append a xs = xs ++ [a]

alteraPreco :: Codigo -> Preco-> [Produto] -> [Produto]
alteraPreco _ _ [] = []
alteraPreco codigo preco ((c, n, p):xs) =
    if codigo == c
        then (c, n, preco) : xs
        else (c, n, p) : alteraPreco codigo preco xs

removeElemento :: Produto -> [Produto] -> [Produto]
removeElemento _ [] = []
removeElemento elem lista = filter (/= elem) lista

acharProdutos :: [Produto] -> [Codigo] -> [Produto]
acharProdutos p [] = []
acharProdutos produtos (i:c) = append (retornaProduto produtos i) (acharProdutos produtos c)

retornaProduto :: [Produto] -> Codigo -> Produto
retornaProduto [] codigo = (0, "", 0)
retornaProduto (h:t) codigo = if retiraCodigo h == codigo then h else retornaProduto t codigo

notaFiscal :: [Produto] -> [Codigo] -> IO()
notaFiscal lista codigos =  let { novaLista = inverterLista (acharProdutos lista codigos) ; 
                                  nota = "**********Nota Fiscal*********\n\n"; totalS = "\nTotal"; tamT = 30 - (length totalS + tamTotal (total novaLista));
                                  fill = take tamT (repeat '.')}
                            in writeFile "NotaFiscal.txt" (nota ++ printaProdutos novaLista ++ totalS ++ fill ++ formatarNumero (total novaLista))

tamN :: Produto -> Int
tamN p = length (retiraNome p)

tamP :: Produto -> Int
tamP p = (contaDigitosFloat (retiraPreco p)) + 2

tamTotal :: Float -> Int
tamTotal p = (contaDigitosFloat p) + 2

printaProdutos :: [Produto] -> String
printaProdutos [] = ""
printaProdutos (h:t) = let rep = 30 - tamN h - tamP h - 1; fill = take rep (repeat '.') 
                       in (retiraNome h) ++ fill ++ formatarNumero (retiraPreco h) ++ "\n" ++ printaProdutos t

total :: [Produto] -> Float
total [] = 0
total (h:t) = retiraPreco h + total t

contaDigitosFloat :: Float->Int
contaDigitosFloat n = d
               where
                  str = show (round n)
                  d = length str

inverterLista :: [Produto] -> [Produto]
inverterLista = \list ->
    case list of
        [] -> []
        x:xs -> inverterLista xs ++ [x]

formatarNumero :: Float -> String
formatarNumero numero = (printf "%.2f" numero) :: String
        