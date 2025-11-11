(* (4) A  multiplicação   é   uma   das   operações  mais   simples   que   podem  ser   feitas   com 
matrizes.   Para  multiplicar   um  número  k  qualquer   por   uma  matriz  nxm  A,   basta 
multiplicar cada entrada aij de A por k. Assim, a matriz resultante B será também nxm 
e B[i,j] = k*A[i,j]. Crie uma função que lê um número k, uma matriz nxm A, produz e 
imprime a matriz B, de acordo com o enunciado acima. As dimensões n e m devem ser 
solicitadas ao usuário para a leitura da matriz A. *)

let int_mult_matrix m k =
for i = 0 to (Array.length m) -1 do
	for j = 0 to (Array.length m.(i)) -1 do
		m.(i).(j) <- m.(i).(j) * k;
	done;
done;
m


int_mult_matrix [|[|1;2;3|];[|4;5;6|]|] 3