(* (3) Duas   matrizes  A  e  B  podem   ser   adicionadas   apenas   se   tiverem   as   mesmas 
dimensões, isto é, se forem da mesma ordem. Crie uma função que lê duas matrizes A 
e B, verifica se a soma A+B pode ser realizada e, se possível, computa e imprime A+B. 
As dimensões das matrizes devem ser solicitadas ao usuário. *)

let sum_matrix m1 m2 =
if (Array.length m1 <> Array.length m2) || (Array.length m1.(0) <> Array.length m2.(0)) then 
	invalid_arg "sum_matrix: as duas matrizes devem ter tamanhos iguais"
	else
		let sum = Array.make_matrix (Array.length m1) (Array.length m1.(0)) 0 in
			for i = 0 to (Array.length m1) -1 do
				for j = 0 to (Array.length m1.(0)) -1 do
					sum.(i).(j) <- m1.(i).(j) + m2.(i).(j);
				done;
			done;
sum

sum_matrix [|[|1;2;3|];[|4;5;6|]|] [|[|1;2;3|];[|4;5;6|]|]

