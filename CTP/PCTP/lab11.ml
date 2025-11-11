(*(1) Escreva uma função que toma dois arranjos de inteiros a1 e a2 e retorna um terceiro
arranjo a3 que corresponde à soma dos elementos de a1 e a2. Para produzir a3, some
os elementos de mesmo índice em a1 e a2. Caso os arranjos a1 e a2 tenham tamanhos
diferentes, encerre a3 ao percorrer o menor arranjo entre a1 e a2. *)

let array_sum a1 a2 =
let ar = if Array.length a1 <= Array.length a2 then a1 else a2 in
let res = Array.create (Array.length ar) 0 in
for i = 0 to (Array.length ar) -1 do
	res.(i) <- a1.(i) + a2.(i);
done;
res 	

(*(2) Escreva  uma   função   para   buscar   um  elemento   em um  arranjo.  Essa   função   deve 
retornar uma lista com os índices onde o elemento se encontra. 	*)

let rec lastinsert v lst =
match lst with
 [] -> [v]
|c::r -> c::(lastinsert v r) 

let poslist v a =
let lst = ref []  in
for i = 0 to (Array.length a) -1 do
 if v = a.(i) then lst := !lst@[i];
done;
!lst

(* (3) Escreva   uma   função   que,   dado   um  arranjo   a   e   um  valor   v   do  mesmo   tipo   dos 
elementos do arranjo a, constrói um novo arranjo cujos elementos são v na posição 0 e 
os elementos de a nas posição 1 até Array.length a. *)

let array_init v a =
let res = Array.create ((Array.length a) +1) a.(0) in
res.(0) <- v;
for i = 1 to (Array.length a) -1 do
res.(i) <- a.(i-1);
done;
res

(* (4) Defina uma função que, dada um número natural n, e uma função f: int -> 'a, retorna
o arranjo cujo  i-ésimo elemento é (f   i).  Essa  função é pré-definida em Caml,  sob o
nome de Array.init. *)

let array_init n (f:int -> 'a) =
let res = Array.create n 0 in
for i = 0 to (Array.length res) -1 do
res.(i) <- f i;
done;
res



