(*Seja um arranjo v de valores do tipo 'a,  um valor init do tipo 'b,  e uma 
função f do tipo 'b -> 'a -> 'b.  Seja então a sequência s tal que s(0) = init e 
s(n+1) = f s(n) v.(n),  ou seja s(n+1) é o resultado da aplicação de f a s(n) e 
v.(n),  o elemento de v na posição n.  Defina uma função que,  aplicada a v,  
init e f,  retorna s(m),  onde m é o número de elementos de v. *)

let arrayfoldleft f init v  =
let s = ref init in
for i = 0 to (Array.length v) -1 do
s := f !s v.(i);
done;
!s

(*Essa função anterior é pré-definida em Caml sob o nome de Array.fold_left.  
Resolva novamente os exercícios anteriores utilizando essa função *)

(*Defina uma função que,  dado um arranjo v de valores do tipo int,  retorna 
a soma dos elementos desse arranjo. *)

let somavarray v =
let res = Array.fold_left (fun i z -> i+z) 0 v
in res

(*Defina uma função que,  dado um arranjo v de valores do tipo string,  
retorna a concatenação dos strings desse arranjo.  O resultado deve 
respeitar a ordem dos elementos:  aplicada a [| "a" ;  "bb" ;  "ccc" |],  retorna 
"abbccc".  Se o arranjo for de tamanho 0,  a função retorna "". *)

let confole v =
let res = Array.fold_left (fun i z -> i^z) "" v
in res