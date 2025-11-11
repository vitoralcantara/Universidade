(*Questão 1a: Crie o tipo lista_simples, uma lista ligada simples. Uma lista_simples deve ser definida ou como um nó (NO) contendo um valor inteiro e uma (sub)lista de
elementos, nesta ordem, ou uma lista vazia, representada pelo nó NULO.*)

type lista_simples = Empty | Cons of int * int list;;

(*Questão 1b: Função vazia : lista_simples -> bool, que verifica se a lista dada é vazia.*)

let rec vazia ls =
match ls with
 [] -> true
|hd::tl -> false;;

(*Questão 1c: Função insercao_fim : lista_simples -> int -> lista_simples, que recebe a lista l1, o valor n e retorna l2, a lista resultante da inserção de n no final de l1.*)

let rec insercao_fim ls n =
match ls with
 [] -> [n]
|hd::tl -> hd::(insercao_fim tl n)

(*Questão 1d: Função remocao_inicio : lista_simples -> lista_simples, que recebe a lista l1 e retorna l2, a lista resultante da remoção do primeiro nó de l1*)

let remocao_inicio ls =
match ls with
 [] -> []
|hd::tl -> tl

(*Questão 1e: Função remocao_fim : lista_simples -> lista_simples, que recebe a lista l1 e retorna l2, a lista resultante da remoção do último nó de l1.*)

let rec remocao_fim ls =
match ls with
 [] -> []
|[a] -> []
|hd::tl -> hd::(remocao_fim tl)
 
 (*Questão 1f: Função busca : lista_simples -> int -> bool, que recebe a lista l1 e o valor n e informa se n pertence a l1.*)

let rec busca l1 n =
match l1 with 
 [] -> false
|[a] -> if a = n then true else false
|hd::tl -> if hd = n then true else busca tl n

(*Questão 1g: Função impressao : lista_simples -> unit, que imprime os valores da lista dada.*)

let impressao ls =
let rec aux lista = 
match lista with
 [] -> "0"
|[a] -> string_of_int(a) 
|hd::tl -> string_of_int(hd)^(aux tl)
in print_string(aux ls)

(*Questão 2a: busca: int -> int_arvbin -> bool, que realiza buscas por uma chave em uma árvore de busca binária.*)
type int_arvbin = Vazia | Vertice of (int_arvbin * int * int_arvbin);;

let rec busca (ab: int_arvbin) n =
match ab with
 Vazia -> false
|Vertice(menor,base,maior) -> if n = base then true else
							  if busca menor n = true then true else
								busca maior n	
											
(*Questão 2b: insercao: int -> int_arvbin -> int_arvbin, que toma uma árvore de busca binária e um valor, inserindo-o na árvore.*)

let rec insercao (ab: int_arvbin) n =
match ab with
 Vazia -> Vertice(Vazia, n,Vazia)
|Vertice(menor,base,maior) -> if n = base then Vertice(menor,base,maior)
								else if n > base then Vertice(menor,base,insercao maior n)
								else Vertice(insercao menor n, base, maior)
								
(*Questão 2c: altura: int_arvbin -> int, que calcula a altura de uma árvore binária, isto é, o maior número arestas (ligações) conectando a raiz da árvore a uma folha específica.*)

let rec altura (ab:int_arvbin) =
	match ab with
	 Vazia -> 0
	|Vertice(Vazia,base,maior) -> 1 + altura maior
	|Vertice(menor,base,Vazia) -> 1 + altura menor
	|Vertice(menor,base,maior) -> if altura menor > altura maior then altura menor else altura maior
									
(*Questão 2d: naovazios : int_arvbin -> int, que calcula o número de nós não-vazios de uma árvore. *)

let rec naovazios (ab:int_arvbin) =
 match ab with
 Vazia -> 0
|Vertice(menor,base,maior) -> 1 + naovazios menor + naovazios maior


	
											
											
											
											

	(*Árvore Para Testes*)
	Vertice(Vertice(Vertice(Vazia,4,Vazia),5,Vertice(Vazia,7,Vertice(Vazia,8,Vazia))),9,Vazia)
  

 