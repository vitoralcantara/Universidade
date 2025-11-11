(*Lista 04 - Recursão*)

(*Questão 1*)

let rec sequence s =
match s with
 0 -> 1
|_ when s<0 -> invalid_arg "dado errado"
|_ -> 2*sequence(s-1) +1  

(*Questão 2*)

let rec sequence2 u =
match u with 
 0 -> 1
|1 -> 2
|_ when u<0 -> invalid_arg "dado errado"
|_ -> 2*sequence2(u-1) - 3*sequence2(u-2)

(*Questão 3*)

let rec sequence3 v = 
match v with
 0 -> 1
|1 -> 1
|_ when v<0 -> invalid_arg "dado errado"
|_ when v>1 && v mod 2 = 0 -> 2*sequence3(v-1) - sequence3(v-2)
|_ when v>1 && v mod 2 <> 0 -> sequence3(v-1) - 2*sequence3(v-2)

(*Questão 4*)

let primo n =
match n with 
 0 -> false
|1 -> false 
|_ when n<0 -> invalid_arg "dado errado"
|_ -> let rec aux num den =
	if den = 1 then true 
	else if num mod den = 0 then false
	else aux num (den-1)
	in 
	aux n (n-1)

(*Questão 5*)

let rec nprimos n =
match n with
 0 | 1 |_ when n<0 -> 0
|_ -> if primo n then 1 +nprimos(n-1) else nprimos(n-1);;





  
     




 
