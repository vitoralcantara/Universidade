(* LCTP - Lista03 
Giuliano Vilela e Alexsandro Norberto *)


(* _questao01 *)

let rec fib = fun (n:int) ->

	match n with
	
 0 -> 1

|1 -> 1

|_ -> (fib (n-1)) + (fib (n-2));;




(* _questao02 *)

let rec factorial = fun (n:float) ->

if (n = 0.0) then 1.0 else

if (n = 1.0) then 1.0 else

(n *. factorial (n -. 1.0));;



(* _questao03 *)


let rec mdc = fun (a:int)(b:int) ->

if (b > a) then (mdc b a) else
if (a = b) then a else
 (* a é o maior *)



if ((a mod b) = 0) then b else
(mdc (a-b) (b));;


