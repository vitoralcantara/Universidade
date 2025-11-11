(* (1) Escreva a função alterne : string -> unit que recebe uma string como parâmetro de 
entrada e converte maiúsculas em minúsculas e vice-versa. A string modificada deve 
ser exibida ao usuário. *)
	
let alterne s =
for i = 0 to (String.length s) -1 do
 if s.[i] = Char.uppercase s.[i] then s.[i] <- Char.lowercase s.[i]
	else s.[i] <- Char.uppercase s.[i];
done;
s

(* (2) Escreva a função analise : string -> char-> int * int * int que recebe uma string s e 
um caractere c como parâmetros de entrada e retorna a tupla (x,y,z) onde:
    x corresponde ao número de ocorrências de c em s
    y corresponde à posição da primeira ocorrência de c em s
    z corresponde à posição da última ocorrência de c em s 
Considere que a primeira ocorrência de um caractere é a mais à esquerda. *)

(*Achar a primeira posição do valor*)
let firstone (s:string) (c: char) =
let i = ref 0 in
	while (s.[!i] <> c) do
		i:= !i +1;
	done;
!i

(*Achar a última posição do valor*)
let lastone s c =
let i = ref ((String.length s) -1) in
	while (s.[!i] <> c) do
		i := !i -1;
	done;
!i

(*Achar a quantidade de vezes que o valor aparece*)
let occur s c =
let res = ref 0 in
for i = 0 to (String.length s) -1 do
if s.[i] = c then res := !res +1;
done;
!res

(*função principal *)
let analise s c =
if (occur s c) > 0 then 
((occur s c),(firstone s c),(lastone s c)) else
(0,0,0)





