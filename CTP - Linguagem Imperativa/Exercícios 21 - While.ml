(*Usando o comando while,  escrever funções não recursivas para:*)

(*calcular o fatorial de um inteiro positivo*)

let fatorial n = 
if n < 0 then invalid_arg "deve ser maior que 0" else
if n = 0 then 0 else
let i = ref 1 and fat = ref 1 in
	while !i <= n do
	fat := !fat * !i;
	i := !i + 1;
	done;
	!fat

(*dados dois inteiros positivos n e p,  retornar np (n elevado a p).*)	

let exponencial n p =
if n < 0 then invalid_arg "deve ser maior que zero" else
let i = ref 1 and exp = ref 1 in
while !i <= p do
exp := !exp*n;
i := !i+1;
done;
!exp

(*calcular o maior divisor comum de dois inteiros positivos.*)
(*essa eu esqueci como calcular MDC*)

(*somar os elementos de uma lista de inteiros*)
let somalista l =
let lst = ref l and i = ref 1 and res = ref 0 in
while !i <= (List.length l) do
res := !res + (List.hd !lst);
lst := (List.tl !lst);
i := !i + 1;
done;
!res

(*retornar o maior elemento de uma lista de inteiros.*)
let maior_lista l = 
let lst = ref l and i = ref 1 and res = ref 0 in
while !i <= (List.length l) do
if (List.hd !lst) > !res then 
res := (List.hd !lst);
lst := (List.tl !lst);
i:= !i +1;
done;
!res 

(*inserir um valor em uma lista ordenada crescente de inteiros *)
let insert_list (v:int) (l: int list) =
let lst = ref l and l2 = ref [] and l3 = ref [] in
while ((List.hd !lst) < v) && (!lst <> []) do
l3 := (!l3)@[List.hd !lst];
lst := (List.tl !lst);
done;
if !lst = [] then l3 := !l3@[v] else
if (List.hd !lst) = v then l2 := !lst else
l2 := v::!lst;
l3 := (!l3)@(!l2);
!l3

(*Por que essa função não funciona quando será inserido um valor no final da lista? Ex: insert_list 3 [1;2];; *)

(*inverter uma lista*)

let invert_list l =
let entrada = ref l and i = ref 1 and saida = ref [] in
while !i <= List.length l do
saida := List.hd !entrada::!saida;
entrada := List.tl !entrada;
i := !i+1;
done;
!saida



[4;5;6;7] [7;6;5;4]




	



 




