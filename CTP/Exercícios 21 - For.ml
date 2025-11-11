(*Usando o comando for ,  escrever funções não recursivas para*)

(*calcular o fatorial de um inteiro positivo*)
let fatorial n =
if n = 0 then 0 else
let res = ref 1 in
for i = 1 to n do
res := !res*i;
done;
!res

(*dados dois inteiros positivos n e p,  retornar np (n elevado a p)*)

let exponencial n p =
let res = ref 1 in
for i = 1 to p do
res := !res*n;
done;
!res

(*somar os elementos de uma lista de inteiros*)
let somalista l =
let res = ref 0 and lst = ref l in
for i = 1 to (List.length l) do
res := !res + List.hd !lst;
lst := List.tl !lst;
done;
!res

(*retornar o maior elemento de uma lista de inteiros*)
let list_maior l =
let res = ref 0 and lst = ref l in
for i = 1 to List.length l do
if List.hd !lst > !res then 
res := List.hd !lst;
lst := List.tl !lst;
done;
!res

(*inserir um valor em uma lista ordenada crescente de inteiros.*)
(*Essa é muito foda *)

let listcount v l =
let lst = ref l and soma = ref 0 in 
for i = 1 to List.length l do
if v = (List.hd !lst) then soma := !soma +1;
lst := (List.tl !lst);
done;
!soma



let insertvalor v l =
let lista = ref l and track = ref [] in
for i = 1 to (List.length l) -1 do
if (v > List.hd !lista) && (v < List.hd (List.tl !lista)) 
	then 
	track := !track @ [List.hd !lista] @ [v]
	else track := !track @ [List.hd !lista];
lista := (List.tl !lista);
done;
track := !track @ !lista;
if (listcount v !track) = 0 then
	begin
		if v < (List.hd !track) then
			track := [v] @ !track else
			track := !track @ [v];
	end;
!track











(*inverter uma lista.*)
let inverterlista l =
let lst = ref l and l2 = ref [] in
for i = 1 to List.length l do
l2 := List.hd !lst::!l2;
lst := List.tl !lst;
done;
!l2



