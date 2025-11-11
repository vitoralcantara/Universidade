(*Questao parecida com a prova, vc da 3 entradas, e sai como resultado a media da ufrn, qnto precisa
pra fazer a prova final e sua condi��o*)

let media (n1:float) (n2:float) (n3:float) =
	let media = (n1*. 4. +. n2*. 5. +. n3*. 6.)/. 15. 
	in  let qnt = 10. -. media in
		if (media < 7.) && (media < 3.) then
			 (media,qnt,"tranque a materia mermao")
		else 
		if (media < 7.) && (media > 3.)
			 then (media,qnt, "vai pra final brodi")
		else (media, 0., "vai pro proximo semestre meu xapa");;

(* Inserir tupla de string (4) e um string e ao inserir uma entrada na função (1 string e os valores
da tupla, mostrar a quantidade de vezes que o valor do string aparece na tupla*)

let count ((a,b,c,d):int*int*int*int) n:int = 

(*a*)   if n = a && n <> b && n <> c && n <> d then 1 else 
(*b*)   if n <> a && n = b && n <> c && n <> d then 1 else 
(*c*)   if n <> a && n <> b && n = c && n <> d then 1 else 
(*d*)   if n <> a && n <> b && n <> c && n = d then 1 else 
(*ab*)  if n = a && n = b && n <> c && n <> d then 2 else 
(*ac*)  if n = a && n <> b && n = c && n <> d then 2 else 
(*ad*)  if n = a && n <> b && n <> c && n = d then 2 else 
(*bc*)  if n <> a && n = b && n = c && n <> d then 2 else 
(*bd*)  if n <> a && n = b && n <> c && n = d then 2 else 
(*cd*)  if n <> a && n <> b && n = c && n = d then 2 else 
(*abc*) if n = a && n = b && n = c && n <> d then 3 else 
(*abd*) if n = a && n = b && n <> c && n = d then 3 else 
(*acd*) if n = a && n <> b && n = c && n = d then 3 else 
(*bcd*) if n <> a && n = b && n = c && n = d then 3 else 4


(*Dizer se a data é valida*)
(*Meses que terminam com dia 31: 1, 3, 5, 7, 8, 10, 12*)
(*Meses que terminam com dia 30: 4, 6, 9, 11*)
(*Fevereiro: termina no dia 28*)

type data = {dia: int; mes: int; ano: int}

let valida (x:data) = 
if x.mes = 1 || x.mes = 3 || x.mes = 5 || x.mes = 7 || x.mes = 8 || x.mes = 10 || x.mes = 12 then 
			if x.dia >= 1 && x.dia <= 31 then "data valida"    else "data invalida" 
else if x.mes = 4 || x.mes = 6 || x.mes = 9 || x.mes = 11 then
				if x.dia >= 1 && x.dia <= 30 then "data invalida" else "data invalida"
else if x.mes = 2 then if x.dia >= 1 && x.dia <= 28 then "data valida" else "data invalida" 
else "mes invalido" 					



(*função que diz o dia seguinte (ainda ta incompleta) *)

let seguinte (x:data) = 
if valida(x) = "data valida" then {dia = x.dia + 1 ; mes = x.mes ; ano =  x.ano}
else {dia = x.dia; mes = x.mes + 1 ; ano =  x.ano}






