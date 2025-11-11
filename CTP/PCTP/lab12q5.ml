(* (5) Dadas duas matrizes A e B, a multiplica��o A*B entre elas � bem-definida somente se
o número de colunas da matriz A � o mesmo que o n�mero de linhas da matriz B. Se A
� uma matriz mxn e B � uma matriz nxp, ent�o a matriz produto A*B mxp � dada por:
(A*B)[i,j] = A[i,1]*B[1,j]+A[i,2]*B[2,j]+...+A[i,n]*B[n,j]
para   cada  par  i  e  j.  Crie   uma   fun��o   que   l�  duas  matrizes  A  e  B,   verifica   se   a
multiplica��o entre elas pode ser realizada e, se poss�vel, produz e imprime a matriz
A*B. As dimens�es de A e B devem ser solicitadas ao usu�rio. *)

let prodmatrix m1 m2 =
	if (Array.length m1.(0) <> Array.length m2) then invalid_arg
	"prodmatrix: o num de colunas da primeira matrix deve ser = ao numero de linhas da segunda"
	else
		let prod = Array.make_matrix (Array.length m1) (Array.length m2.(0)) 0 in
			for i = 0 to (Array.length m1) -1 do
				for j = 0 to (Array.length m2.(0)) -1 do
					for k = 0 to (Array.length m1.(0)) -1 do
						prod.(i).(j) <- prod.(i).(j) + m1.(i).(k) * m2.(k).(j);
					done;
				done;
			done;
prod

prodmatrix [|[|1;2;|];[|4;5;|]|] [|[|1;2;3|];[|4;5;6|]|]
			[|[|1;2;3|];[|4;5;6|]|] [|[|1;4|];[|2;5|];[|3;6|]|]