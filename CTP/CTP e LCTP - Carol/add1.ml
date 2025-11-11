

(* (1) Implemente a funÃ§Ã£o inserth, que recebe elm e list e retorna uma nova lista
   correspondente a inserÃ§Ã£o de elm na cabeÃ§a de list.
(2) Implemente a funÃ§Ã£o insertt, que recebe elm e list e retorna uma nova lista
   correspondente a inserÃ§Ã£o de elm no final de list*)


 (*1*)

 let rec inserth l n = 
  match l with  

 [] -> [n] 
| a :: b -> n :: a :: b;;

(*2*)

 let rec insertt l n =
  match l with
  [] -> [n]
| a :: b -> a :: (insertt b n);; 


 (*3*)

 let rec st l n = 
 match l with
  [] -> [n]
| a :: b -> let p = (st b) in
  if n > a && n > p 

 type list_int = Empty | Cons of int * list_int;;

let rec list_oinsert l i =
   match l with
     Empty -> Cons(i, Empty) |
     Cons(a, rest) -> if i <= a then Cons(i, l) else Cons( a , list_oinsert rest i)

  
let rec list_sort = function
   Empty          -> Empty
| Cons (a, rest) -> list_oinsert (list_sort rest) a




let rec oinsert l n = 
 match l with
  [] ->  [n]
| a :: b -> if n > a then a::( oinsert b n) else n :: l;; 


let rec orderinsert l =
 match l with
   [] -> []
 | a :: b -> oinsert (orderinsert b) a ;;



let rec oinsert l n = 
 match l with
  [] -> n
| a :: b -> 











let rec busca l n = 
 match l with
  [] -> false
| a :: b -> if n = a then true else (busca b n);;
               



let list_insert (l:int list) (n:int) =
	match l with
	[] -> [n] |
	x :: rest -> n :: x :: rest;; 

let rec list_ord (l:int list) =
	match l with
	[] -> [] |
	x :: rest -> let rec ord (n:int list) (i:int) =
			match n with
			[] -> [i] |
			x :: rest -> if (i <= x) then (i :: x :: rest) else 
				(x :: (ord rest i)) in 
		(ord (list_ord rest) x);;

let list_ord_ins (l:int list) (n:int) =
	list_ord (list_insert l n);;


 let rec list_sort l =
  match l with
 [] -> []
| a :: b -> 



 (*
  paladin~nv_playdead 0,nv_basic 9,nv_firstaid 0,nv_summon 0,nv_givehp 0,sm_hprecovery 10,sm_fatalblow 0,sm_bash 10,sm_magnum 2,sm_berserk 0,sm_sword 10,sm_provoke 7,sm_moverecovery 0,sm_endure 10,cr_defendingaura 1,cr_guard 5,pl_gospel 2,pl_shieldchain 3,cr_holycross 6,cr_grandcross 10,cr_heal 10,cr_boomerang 5,cr_reflect 1,cr_faith 10,cr_demonbane 5,cr_cure 1,cr_ride 1,cr_cavalier 1,cr_divineprotection 5,cr_smite 3  *)


  let rec imp l n =
 match l with 
    [] -> []
 | a :: b -> if a = n then b  else a :: (imp b n );;
 
(* (8) Implemente a função subst, que toma dois elementos, elm1 e elm2, e list e retorna uma
    nova lista correspondente à substituição de cada ocorrência de elm1 por elm2, se elm1
    estiver na lista.
(9) Implemente a função larger, que retorna o maior elemento de uma lista.
(10) Implemente a função corder, que recebe uma lista e devolve uma lista em ordem
    decrescente.*)





(*8*)


 let rec subst l n m = 
 
 match l with
    [] -> [] 
 |  [n] -> [m]
 | a :: b -> if n = a then m :: (subst b n) else (subst b n);;

     


let rec subst l n1 n2 = 
	match l with
 [] -> []
|[n1] -> [n2]
|a::rest -> if a=n1 then n2 :: (subst rest n1 n2) else  [a]@ (subst rest n1 n2);;





 

 (*9*)

 let rec larger l =
 match l with
   [a] -> a
 | a :: b -> 
             if a > larger b then a else larger b;;
 (*10*)




 (*10*)


 let rec add l n = 
 match l with
 [] -> [n]
 | a :: b -> if n<a then a :: (add b n) else n :: l;;
 
 
 let rec corder l =
 match l with
    [] -> []
 | a :: b -> add (corder b) a;;



(*  paladin~nv_basic 9,nv_firstaid 0,nv_givehp 0,nv_playdead 0,nv_summon 0,sm_bash 10,sm_berserk 0,sm_endure 10,sm_fatalblow 0,sm_moverecovery 0,sm_hprecovery 10,sm_magnum 4,sm_provoke 5,sm_sword 10,cr_cure 1,cr_demonbane 5,cr_divineprotection 5,cr_faith 10,pl_pressure 5,pl_gospel 1,cr_guard 5,cr_heal 9,cr_resistantsouls 5,cr_boomerang 5,pl_shieldchain 5,cr_reflect 10,cr_smite 3 *)


  
