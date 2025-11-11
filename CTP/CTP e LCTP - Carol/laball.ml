 
 (*
 let min3max a b c = 

   let maxi = max3 a b c and
       tmp = ref 0 in
 if (a = maxi) then tmp := min b c; 
 if (b = maxi) then tmp := min a c; 
 if (c = maxi) then tmp := min a b; 

  printf "Minimo e o maximo dessa sequencia %d %d\n" !tmp maxi;;*)

 let min3max a b c = 

   let maxi = max3 a b c and
       tmp = ref 0 in
 if (a = maxi) then tmp := min b c; 
 if (b = maxi) then tmp := min a c; 
 if (c = maxi) then tmp := min a b; 

  printf "Minimo e o maximo dessa sequencia %d %d\n" !tmp maxi;;

  type hora =  { h: int ; m: int ; s: int }

  let verifica (h: hora) = 
    if (h.h < 24 && h.h >= 0) && (h.m < 60 && h.m >=0 ) && (h.s < 60 && h.s >=0) then true else false;;

   
   let h2s (h: hora) = h.h * 3600 + h.m * 60 + h.s;; 


   let anterior (h1: hora) (h2: hora) = 
        let ns1 = h2s h1 and ns2 = h2s h2 in
           if ns1 < ns2  then true
             else false;;

(* lista 3 , questao 4 *)
(*A*)

type ponto = float * float
type vetor = ponto * ponto

(*B*)

 let v1 = ((0.,0.) , (1.,0.)) and v2 ((0.,0.) , (0.,1.))

(*C*)

 let norma (v: vetor) = 
   let dx = fst (fst v) -. fst (snd v) and
       dy = snd (fst v) -. snd (snd v) in
          sqrt (dx *. dx  +. dy *. dy);;

 let  nprimos (n: int) =
     if (n < 0) then invalid_arg "falha"
else
     let acumulador = ref 0 in 
    for i=n downto 2 do 
        if (primo i) then
      acumulador := !acumulador + 1
done;
!acumulador;;
      
  let rec membernum (l: int list) (n: int) = 
      match l with
     [] -> 0 
  | ( a::b )  -> if (a=n) then 1 + membernum b n 
        else membernum b n;;


   type 'a arvbin = Vazia 
 | Vertice of ('a arvbin * 'a * 'a arvbin )

   let rec busca (n: 'a) (a: 'a arvbin) = 
       match a with 

      vazia -> false
 | Vertice (ve,v,vd) ->if v=n then true
       else
         if n<v then busca n ve
            else busca n vd;;

   

(*(1) Definir uma função que, dada uma lista de inteiros l, retorna o produto dos elementos
    de l.
(2) Construir uma função que, dada uma lista de inteiros l, retorna a lista composta pelos
    dobros dos elementos de l, respeitando a ordem.
(3) Construir uma função que, dada uma lista de inteiros l, retorne uma lista com os
    elementos em ordem inversa dos de l.
(4) Construir uma função que, dada uma lista de inteiros l, retorne uma lista com os
    elementos de l em ordem crescente.*)

 
  (*1*)

 let rec produto l = 
 match l with
   [] -> 1
 | a :: b -> a * (produto b);;

 (*2*)

 
  let rec dobro l =
 match l with
   [] -> []
 | a :: b -> (2 * a :: (dobro b));; 

 (*3*)

 let rec inverse l n =
 match l with
   [] -> [n]
 | a :: b -> 












 (*
 let rec subst l n1 n2 = 
	match l with
 [] -> []
|[n1] -> [n2]
|a::rest -> if a=n1 then n2::(subst rest n1 n2) else  [a]@ (subst rest n1 n2);;



(* paladin~nv_playdead 0,nv_basic 9,nv_firstaid 0,nv_summon 0,nv_givehp 0,sm_hprecovery 10,sm_fatalblow 0,sm_bash 10,sm_magnum 2,sm_berserk 0,sm_sword 10,sm_provoke 7,sm_moverecovery 0,sm_endure 10,cr_defendingaura 1,cr_guard 5,pl_gospel 2,pl_shieldchain 3,cr_holycross 6,cr_grandcross 10,cr_heal 10,cr_boomerang 5,cr_reflect 1,cr_faith 10,cr_demonbane 5,cr_cure 1,cr_ride 1,cr_cavalier 1,cr_divineprotection 5,cr_smite 3  *)


(*lista08*)
let rec dobro l= 
	let a = ref [] and b = ref l in
		while !b != [] do
			match !b with
		 [] -> ()
		|x::rest -> a := !a@[2*x];
					b := rest
		done;
		!a;;
