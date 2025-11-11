(*Terceira Prova de Umberto Semestre Passado*)  

(* Questão 1 (2,5 pontos) 
Crie a função OCaml trocas : int ref -> int ref -> int ref -> int ref * int ref * int ref que 
toma três argumentos a0, a1 e a2, copia o conteúdo de cada ai em aj, onde j = (i+1) mod 
3, para 0 = i = 2, e retorna a tupla (a0,a1,a2). Exemplos de uso da fun��o trocas: 
# trocas (ref 1) (ref 2) (ref 3);; 
- : int ref * int ref * int ref = 
({contents = 3}, {contents = 1}, {contents = 2}) 
# trocas (ref 8) (ref 5) (ref 0);; 
- : int ref * int ref * int ref = 
({contents = 0}, {contents = 8}, {contents = 5}) 	*)

let trocas a0 a1 a2 = 
let lst = [|!a0;!a1;!a2|] in
let res = Array.create (Array.length lst) !a0 in
for i = 0 to (Array.length res) -1 do
res.(i) <- lst.((i+2)mod 3);
done;
res

(* Questão 2 (2,5 pontos) 
Na matemática, número de Euler e, assim chamado em homenagem ao matemático suíço 
Leonhard Euler, é a base dos logaritmos naturais e vale aproximadamente 
2,718281828459045235360287.  O número de Euler pode ser escrito como a soma da série 
infinita: 
   e = ? (1/n!) = (1/0!) + (1/1!) + (1/2!) + (1/3!) +... 
onde n! representa o fatorial de n. Crie uma função OCaml não-recursiva euler : int -> 
float que toma um inteiro k > 0 e retorna número de Euler calculado com k parcelas. 
# euler 1;; 
- : float = 1. 
# euler 10;; 
- : float = 2.7182815255731922 
# euler 20;; 
- : float = 2.7182818130713988  *)

let fatorial n =
let res = ref 1 in
for i = 1 to n do 
res := !res * i;
done;
!res

let euler k =
let res = ref 0. in
for i = 0 to (k-1) do
res := !res +. (1. /. float_of_int (fatorial i));
done;
!res 

(*Questão 3 (2,5 pontos) 
Uma aplicação interessante dos computadores  são os desenhos de gráficos e códigos de 
barras. Escreva uma função OCaml cbarras : int * int * int * int * int -> unit que toma 
uma tupla de 5 números inteiros (cada um entre 1 e 30) e, para cada número lido, imprime 
uma linha contendo esse número de asteriscos adjacentes. Suponha que apenas valores 
válidos são passados à função. Abaixo, um exemplo de execução: 
# cbarras (12,3,21,1,10);; 
************ 
*** 
********************* 
* 
********** 
- : unit = () *)

let printstar n =
let star = ref "" in
for i = 0 to n do
star := !star^"*";
done;
!star

let cbarras (i1,i2,i3,i4,i5) =
Printf.printf "%s \n %s \n %s \n %s \n %s" 
(printstar i1) (printstar i2) (printstar i3) (printstar i4) (printstar i5)

let cbarras i1 i2 i3 i4 i5 =
print_string(
	(printstar i1) ^ "\n" ^ 
	(printstar i2) ^ "\n" ^
	(printstar i3) ^ "\n" ^
	(printstar i4) ^ "\n" ^
	(printstar i5))

(*Questão 4 (2,5 pontos) 
Escreva uma função OCaml não-recursiva  pi : unit -> unit que calcule o valor de  p 
utilizando séries infinitas: 
p = 4 – (4/3) + (4/5) – (4/7) + (4/9) – (4/11) + ... 
e imprima uma tabela que mostra o valor aproximado de p para 1.000, 2000 e 3000 termos 
dessa série. Veja o comportamento esperado desta função: 
# pi ();; 
Pi          Numero de Termos 
3.14059265384   1000 
3.14109265362   2000 
3.14125932027   3000 
- : unit = () *)

let pi n =
	if n = 1 then 4. else 
	let sinal = ref ~-.1. and den = ref 3. and sum = ref 4. in
	for i = 2 to n do
	sum := !sum +. !sinal *. (4. /. !den);
	sinal := !sinal *. ~-.1.;
	den := !den +. 2.	
	done;
!sum
	
	
let printpi () =
Printf.printf  "Pi  Numero de Termos \n
%f  1000 \n
%f  2000 \n
%f  3000" (pi 1000) (pi 2000) (pi 3000)
		


