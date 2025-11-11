(*(1) Qual valor é produzido pela função g abaixo? Explique comentando o código.
let g =
  let x  = 7 in
  let y  =
     let x = 2 in
       x +1
  in
     x+  y;;*)


let g =
  let x  = 7 in
  let y  =
     let x = 2 in
       x +1
  in
     x+  y;;

(* o valor da função g 10 *)

(*(3) Crie uma variável z com valor igual à soma de x e y, onde x e y são variáveis locais
    inteiras com valores 1 e 2, respectivamente.*)

let x = 1 and
	y = 2 in
x + y;;

(* (4) Crie uma função para identificar se três números inteiros são todos diferentes entre si. *)

let diferente_num a b c =
	if ((a<>b && b<>c && c<>a)) then true	
else false;;

(*(5) Escreva uma função que retorna quantos dos três números inteiros fornecidos como
    argumentos são iguais. A resposta poderá ser 3 (todos iguais), 2 (dois iguais e o
    terceiro diferente) ou 0 (todos diferentes).*)


let dif_num a b c=
	if ((a=b) && (b=c)) then 3 else
	if ((a=b) || (b=c) || (c=a))   then 2 
else 	 0;;

(* (6) Construa uma função que retorna o máximo de 3 inteiros fornecidos como argumentos. *)

let max3 a b c =
	if((a>b) && (a>c) )then a 
else
	if ((b>a) && (b>c)) then b 
	else c;;

(*(7) Construa uma função que recebe três inteiros e retorna o número de ocorrências do
    maior inteiro dentre eles. Use a função do exercício 6 para encontrar o maior inteiro.*)


let ocorrencia a b c=
	let max = max3 a b c in
if ((a= max) && (b= max) && (c= max)) then 3
else 
if( ((a= max) && (b=max)) || ((a=max) && (c=max)) || ((b=max) && (c=max))) then 2
else 1;;


(* LISTA 2- UMBERTO *)

(*(1) Escreva uma função f equivalente à exibida abaixo, mas sem utilizar a construção if.
       let f x y   z=
           if x >  z then true
           else
             if y  >= x then false
             else  true*)


let f x y z = (x>z) || (y<x) ;;

(*(2) Defina um tipo registro para representar frações. Esses registros devem armazenar o
    numerador e o denominador de uma fração em duas variáveis inteiras. Implemente:
   (a) funções que realizem as operações de adição, subtração, multiplicação e divisão;
   (b) função que converta um objeto fração para um tipo float.*)


type fracao = {num: int ; den:int};;

let fracao2= {num=10 ; den=3} and fracao3= {num=5 ; den=4};;

let sum (v1: fracao) (v2:fracao) = 
	((v1.num * v2.den) + (v2.num * v1.den)) / (v1.den * v2.den);;

let subtracao (v1: fracao) (v2:fracao) = 
	((v1.num * v2.den) - (v2.num * v1.den)) / (v1.den * v2.den);;

let mult (v1: fracao) (v2:fracao) = 
	((v1.num) * (v2.num)) / ((v1.den) * (v2.den)) ;;

let  divisao (v1: fracao) (v2: fracao) =
	((v1.num) + (v2.den)) / ((v1.den ) + (v2.num));;














