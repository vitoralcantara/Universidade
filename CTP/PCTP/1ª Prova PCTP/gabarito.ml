(* QUESTAO 01 *)

let idh (ev : float) (ta : float) (te : float) (pibpc : float) =
  let l = (ev -. 25.) /. 60. and
      e = (2. *. ta +. te) /. 3. and
      r = ((log pibpc /. log 10.) -. 2.) /. 2.60206
  in (l +. e +. r) /. 3.;;

(* QUESTAO 02 *)

let ocorrencias ((x,y,z,w), n : (int * int * int * int) * int) = 
  let ig a b = if a = b then 1 else 0 
  in ig x n + ig y n + ig z n + ig w n;;

(* QUESTAO 03 *)

(* A *)

type data = {dia : int; mes : int; ano : int};;

(* B *)

let periodo (d1 : data) (d2 : data) =
  let dias (d : data) = d.dia + 30*(d.mes-1) + 30*12*(d.ano-1)
  in dias d2 - dias d1;;
  
(* C *)

let valor (d1 : data) (d2 : data) (vl : float) (m1 : float) (m2 : float) =
  let p = periodo d1 d2 in
  if p <= 0 then vl
  else vl +. m1 +. m2 *. (float_of_int p);;
