(* ##############################################################
################ Laboratório de LCTP - Turma 01 #################
######## Giuliano Vilela ######### Alexsandro Norberto ##########
################################################################# *)


(* QUESTÃO 01 ---------------------------------------------------------------------*)

let g = (* associa variável *)
  let x  = 7 in (* variável local à expressão de 'g' *)
  let y  = (* variável local à expressão de 'g' e de 'x' *)
     let x = 2 in (* redefine o valor de 'x' somente para a atribuição de 'y' *)
       x +1 (* atribui um valor à x *)
  in
     x+  y;; (* atribui um valor à g *)

(* Resultado->   int: g = 10 *)



(* QUESTÃO 02 ---------------------------------------------------------------------*)

let f = (* associa variável *)
  let x = 1 in (* variável local à expressão de 'f' *)
  let z = (* variável local à expressão de 'x' e de 'f' *)
    let x = x + x in (* redefinindo 'x' localmente à 'z' *)
    let x = x + x in (* redefinindo 'x' usando o valor atribuido acima *)
      x+x   in (* atribuindo um valor à 'z' *)
   x + z;; (* expressão final de 'f' *)

(* Resultado -> int: f = 9 *)



(* QUESTÃO 03 ---------------------------------------------------------------------*)

let z = 
   let x = 1 in let y = 2 in 
x+y;;

(* Resultado -> int: z = 3 *)



(* QUESTÃO 04 ---------------------------------------------------------------------*)

let  diferentes x y z =
	( (x <> y) && (y <> z) && (z <> x) );;

(* Resultado -> <fun>:bool *)



(* QUESTÃO 05 ---------------------------------------------------------------------*)

let iguais x y z =
	if (x = y) && (y = z) then 3 else
	if (x = y) || (x = z) || (y = z) then 2 else 0;;
	
(* Resultado -> <fun>:int *)



(* QUESTÃO 06 ---------------------------------------------------------------------*)

let max3 a b c = 
	let max2 a b = if a > b then a else b in
	let max = max2 a b in
		if max > c then max else c;;

(* Resultado -> <fun>:int *)



(* QUESTÃO 07 ---------------------------------------------------------------------*)
let max_freq a b c =
	let m = max3 a b c in
		if m = a && m = b && m = c then 3 else
			if m = a && m = b || m = a && m = c || m = b && m = c then 2 else 1;;

(* Resultado -> <fun>:int *)