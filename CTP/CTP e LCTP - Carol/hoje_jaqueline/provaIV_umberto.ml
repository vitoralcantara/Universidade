(*#use "C:/Documents and Settings/quen quen/Desktop/provaIV_umberto.ml";;*)

(*1.1 Qual valor é produzido pela função g abaixo? Explique comentando o código.*)
(*g = 10*)
let g =
  let x  = 7 in
  let y  =
     let x = 2 in
       x +1
  in
     x+  y;;

(*2.1 Qual valor é produzido pela função f abaixo? Explique comentando o código.*)
(*f = 9*)

let f =
  let x = 1   in
  let z =
     let x =  x + x in
     let x =  x + x in
       x+x    in
    x + z;;

(*3.1Crie uma variável z com valor igual à soma de x e y, onde x e y são variáveis locais inteiras com valores 1 e 2, respectivamente.*)

let z = 
	let x = 1 and
	    y  = 2 in
x+y;;

(*4.1 Crie uma função para identificar se três números inteiros são todos diferentes entre si.*)

let dif_num a b c = 
	if ((a <> b) && (a <> c) && (b <> c)) then true
	else false;;
(* 5.1 Escreva uma função que retorna quantos dos três números inteiros fornecidos como argumentos são iguais. A resposta poderá ser 3 (todos iguais), 2 (dois iguais e o terceiro diferente) ou 0 (todos diferentes).
*)

let qtd_dif_num a b c =
	if ((a = b) && (b = c)) then 3
	else
	if ((a = b) || (b = c) || (c = a)) then 2
	else 0;;

(*6.1 Construa uma função que retorna o máximo de 3 inteiros fornecidos como argumentos.*)

let max3 (a:int) (b:int) (c:int) =
	if ((a > b) && (a > c)) then a
	else
	if ((b > a) && (b > c)) then b
	else c;;

(* 7.1 Construa uma função que recebe três inteiros e retorna o número de ocorrências do maior inteiro dentre eles. Use a função do exercício 6 para encontrar o maior inteiro.*)

let ocorrencia a b c =
	let max = max3 a  b c in
	
if ((a = max) && (b = max) && (c= max)) then 3
else 
if ((a = max) && (b=max)) || ((a=max) && (c=max)) || ((b=max) && (c=max)) then 2
else 1;;

(*1.2 Escreva uma função f equivalente à exibida abaixo, mas sem utilizar a construção if.
       let f x y   z=
           if x >  z then true
           else
             if y  >= x then false
             else  true *)


let f x y z = (x > z) || (y < x);;  

(* 2.2 Defina um tipo registro para representar frações. Esses registros devem armazenar o numerador e o denominador de uma fração em duas variáveis inteiras. Implemente:
(a) funções que realizem as operações de adição, subtração, multiplicação e divisão;
(b) função que converta um objeto fração para um tipo float.
*)
 
type fracao = {num : int; den : int};;

let teste1 = {num = 10 ; den = 3} and teste2 = {num = 5 ; den = 4};;

let soma (v1:fracao) (v2:fracao) = 
	(((v1.num * v2.den) + (v2.num * v1.den)) / (v1.den * v2.den));;

let subtracao (v1:fracao) (v2:fracao) = 
	((v1.num * v2.den) - (v2.num * v1.den)) / (v1.den * v2.den);;

let multiplicacao (v1:fracao) (v2:fracao) = 
	((v1.num) * (v2.num)) / ((v1.den) * (v2.den));;

let divisao (v1:fracao) (v2:fracao) = 
	((v1.num) * (v2.den))/((v1.den) * (v2.num));;

let converte_fracao (a:fracao) = 
	float_of_int (a.num) /. float_of_int(a.den);;

(*
(3.2) Crie um tipo registro que defina um número complexo (x + yi, onde x e y são do tipo
    float e i é a raiz quadrada de -1). Dados dois números complexos:
        z = a + bi
        w = c + di
    temos que:
        z + w = w + z = (a + bi) + (c + di) = (a + c) + (b + d)i
        zw = wz = (a + bi)(c + di) = (ac - bd) + (bc + ad)i
    Defina funções de soma e multiplicação entre números complexos.

*)

type complexo = {a : float; b:float};;

let complexo_soma (x:complexo) (y:complexo) = 
	print_string "( ";
	print_float x.a;
	print_string " + ";
	print_float x.b;
	print_string "i)  +  (";
	print_float y.a;
	print_string " + ";
	print_float y.b;
	print_string "i) = ";
	print_float (x.a +. y.a);
	print_string " + ";
	print_float (x.b +. y.b);
	print_string "i\n";;

open Printf

type complexo = {a: float; b: float};;
let teste3 = {a= 2.0 ; b= 4.1};;
let teste4 = {a= 3.1; b=4.3};;

let complexo_soma (x:complexo) (y:complexo) = 
printf"(%.1f + %.1fi) + (%.1f + %.1fi) = %.1f + %.1fi \n" x.a x.b y.a y.b(x.a+. y.a) (x.b +. y.b)

let complexo_mult (x:complexo) (y:complexo) =
printf"(%.1f + %.1fi) + (%.1f + %.1fi) = %.1f + %.1fi \n"
x.a x.b y.a y.b ((x.a*. y.a) -. (x.b *. y.b)) ((x.b *. y.a) +. (x.a *. y.b));;        


(*4.2 Defina um tipo hora para representar horas com precisão de segundos. Em seguida,
    crie as seguintes funções:
    (a) função que verifica se uma hora é válida.
    (b) função que, dadas duas horas h1 e h2, verifica se h1 é anterior a h2.
    (c) função que, dada uma hora, retorna o número de segundos passados desde a meia-
        noite.
    (d) função que, dadas duas horas, retorna a diferença em segundos.*)

type hora = {hr:int;min:int;s:int};;

let hora (x:hora) =
        let temp = ref true in
        if ((x.hr < 0) || (x.hr > 23)) then temp := false;
        if ((x.min < 0) || (x.min > 59)) then temp := false;
        if ((x.s < 0) || (x.s > 59)) then temp := false;
        if (!temp = false) then false 
        else true;; 

let hora_anterior (x:hora) (y:hora) =
 if ((hora x = false ) || (hora y = false)) then invalid_arg "hora_anterior";
  if (x.hr =  y.hr) then
   if (x.min = y.min) then
    if (x.s = y.s) then printf"%d:%d:%d igual a %d:%d:%d \n" y.hr y.min y.s x.hr x.min x.s
    else
     if (x.s > y.s) then printf"%d:%d:%d anterior a %d:%d:%d \n" y.hr y.min y.s x.hr x.min x.s
     else printf"%d:%d:%d anterior a %d:%d:%d \n" x.hr x.min x.s y.hr y.min y.s
   else
    if (x.min > y.min) then printf"%d:%d:%d anterior a %d:%d:%d \n" y.hr y.min y.s x.hr x.min x.s
    else printf"%d:%d:%d Hora anterior a %d:%d:%d \n" x.hr x.min x.s y.hr y.min y.s
  else
   if (x.hr > y.hr) then printf"%d:%d:%d anterior a %d:%d:%d \n" y.hr y.min y.s x.hr x.min x.s
   else printf"%d:%d:%d Hora anterior a %d:%d:%d \n" x.hr x.min x.s y.hr y.min y.s 

let seg_meianoite (x:hora) =
        if (hora x = false) then invalid_arg "hora_anterior";
        ((x.hr*3600) + (x.min*60) + (x.s));;

let dif_segundo (x:hora) (y:hora)  = 
     seg_meianoite x - seg_meianoite y;;

(*1.3 Defina uma funçao que recebe uma tupla t1 com 5 elementos inteiros e retorna a tupla
    t2 formada pelos elementos de t1 em ordem inversa.*)

let inverte_tupla (a,b,c,d,e) =
        (e,d,c,b,a);;

(*2.3 Defina a funçaoo min3max que deve retornar um par formado pelo minimo e pelo mÃximo valor de 3 inteiros fornecidos.*)

open Printf;;
let min3max (a:int) (b:int) (c:int) =
       let temp = max3 a b c and
           temp2 = ref 0  in
       if (a = temp) then  temp2 := min b c;
       if (b = temp) then  temp2 := min a c;
       if (c = temp) then  temp2 := min b a;
       printf "Minimo e o maximo dessa sequencia %d %d\n"!temp2 temp;;


(*VER ESSA PARTE*)
(*3.3 Geometria planar cartesiana: pontos.
     (a) Defina uma tupla para representar pontos no plano.
     (b) Defina uma variÃ¡vel cujo valor Ã© o ponto origem do plano.
     (c) Defina uma funÃ§Ã£o que calcula a distÃ¢ncia entre dois pontos.*)

type ponto = float * float;; 

(*4.3Geometria planar cartesiana: vetores.
     (a) Defina uma tupla para representar vetores.
     (b) Defina duas variÃ¡veis cujos valores sÃ£o os vetores unidades dos eixos abscissa e
         ordenada.
     (c) Defina uma funÃ§Ã£o que, dada um vetor, calcula a norma do vetor.
     (d) Define uma funÃ§Ã£o que testa se dois vetores sÃ£o colineares.
     (e) Define uma funÃ§Ã£o que retorna a soma de dois vetores.*)

type vetores = float * float;; (*angulo tamanho*)

let abscissa = (0,1) and ordenada = (90,1);;
type ponto = float * float
type vetor = ponto * ponto
let v1 = ((0,0),(1,0)) and
v2 = ((0,0),(0,1))
let norma (v:vetor) = let dx = fst (fst v) -. fst(snd v) and dy = snd(fst v) -. snd(snd v) in
				sqrt (dx*.dx +. dy*.dy);;


(*5.3 Geometria planar cartesiana: segmentos.
     (a) Defina uma tupla segment para representar segmentos.
     (b) Defina uma funÃ§Ã£o que, dada dois pontos p1 e p2, retorne o segmento com
         extremidades p1 e p2;
     (c) Defina uma funÃ§Ã£o que, dada um segmento s, retorne o comprimento de s.*)

type segmento = ponto * ponto;;


(*1.4 Seja uma sequencia s definida como
        s(0) = 1
        s(n) = 2.s(n-1) + 1, quando n>0
   Defina uma funcao recursiva que, dado n, calcula s(n).*)

let rec s (n:int) =
        if n < 0 then invalid_arg "s"
        else
                if n = 0 then 1
                else 2 * s(n-1) + 1;;

(*2.4 Seja uma sequencia u definida como
        u(0) = 1
        u(1) = 2
        u(n) = 2.u(n - 1) - 3.u(n - 2), quando n>1
   Defina uma funcaoo recursiva que, dado n, calcula u(n).*)

let rec u (n:int) =
        match n with
        0 -> 1 |
        1 -> 2 |
        _ -> 2 * u(n-1) - 3 * u(n-2);;

(*3.4 Seja uma sequencia v definida como:
        v(0)  =  1
        v(1)  =  1
        Se n  >  1 e n for par, v(n) = 2.v(n - 1) - v(n - 2)
        Se n  >  1 e n for impar, v(n) = v(n - 1) - 2.v(n - 2)
   Defina uma funÃ§Ã£o recursiva que, dada n, calcula v(n).*)

let rec v (n:int) = 
        match n with
        0 | 1 -> 1
        |_ -> if (n mod 2 = 0) then 2 * v(n - 1) - v(n - 2)
             else v(n-1) - 2 * v(n- 2);;
(*4.4 Construir uma funcao primo que tem como parametro um numero estritamentepositivo n, e retorna true se n for primo, false caso contrario. Observacoes: seja n umnumero estritamente positivo, n for primo se os unicos divisores de n sao n e 1.*)

let primo (n:int) =
        if n < 0 then invalid_arg "primo"
        else
                let rec primo_aux n d =
                        if (d = 1) then true
                        else
                                if (n mod d = 0) then false
                                else primo_aux n (d -1) in
                primo_aux n (n - 1);;

let primo_2 (n:int) =
        let acc = ref 0 in
        for i = n downto 1 do
                if (n mod i = 0) then acc := !acc + 1
        done;
        if (!acc > 2) then false
        else true ;;

(*5.4 Crie uma funcao OCaml que recebe um numero natural n e retorna a quantidade de numeros primos menores ou igual a n. Nomeie esta funcao como nprimos.*)

(*let nprimos (n:int) =
        let rec nprimo_aux (d:int) (acc:int) =
                if (primo d = true) then (acc + 1);
                nprimo_aux (d - 1) acc in
        nprimo_aux d 0;;*)

let rec nprimos (n:int) =
	if (n<0) then invalid_arg "nprimos"
	else
		match n with
		0|1 -> 0
		|_ -> if (primo n) then (1 + nprimos (n-1))
		      else nprimos (n-1);;

let nprimos_2 (n:int) =
        let 
                acc = ref 0 and
                i = ref 1 in
        while (!i <= n) do
                if (primo_2 !i = true) then acc := !acc + 1;
                i := !i + 1
        done;
        !acc;;


(*6.4 Para (n, p) a funcao C(n,p) conhecida como Binomio de Pascal, pode ser calculada usando a definicao recursiva seguinte:
    C(0,n) = 1
    C(n,n) = 1
    C(n,p) = C(n-1,p) + C(n-1,p-1) se 0 < p < n
    Escreva a funcao recursiva OCaml correspondente.*)


        
(*let rec comb =
	function
		(0,n)->1
                (*|(n,n)->1*)
		|(n,p) -> if ((n>p) && (p>0)) then comb(n-1,p)+comb(n-1,p-1);;*)               
                
(*1.5 Em Ciência da Computação, uma lista ligada é uma estrutura de dados fundamental
utilizada na programação de computadores. Ela consiste em uma seqüência de nós,
cada qual contendo um ou mais campos de dados de tipos arbitrários e uma ou duas
referências apontando para os nós anterior e posterior. Portanto, uma lista ligada é um
tipo de dado definido recursivamente, uma vez que sua definição contém uma
referência à outra estrutura de dados de mesmo tipo. Existem diferentes tipos de listas
ligadas: listas ligadas simples, listas duplamente ligadas e listas ligadas circulares.
Abaixo, temos o exemplo de uma lista ligada simples, com três valores inteiros:
O último elemento da lista, graficamente representado como , corresponde a um nó
NULO, indicando o final da lista. Note que um nó desta lista pode apresentar um valor e
uma referência a outro nó ou, simplesmente, ser um nó NULO. Com base nestas
definições, crie código OCaml que implemente as seguintes operações sobre listas
ligadas simples

(a) Criação do tipo que representa uma lista ligada simples com nós que
armazenam um valor de um tipo inteiro e a referência ao próximo nó da lista.
Lembre de representar também o nó NULO, para indicar término da lista.
(b) Verificação de que uma dada lista está vazia.
(c) Inserção de nó no início de uma lista.
(d) Inserção de nó no final de uma lista.
(e) Retirada do primeiro nó de uma lista.
(f) Retirada do último nó de uma lista.
(g) Busca de nó com valor especifico em uma lista.
(h) Impressão dos valores de uma lista.*)


type 'x list = Cons of  'x * 'x list | Empty;;
let teste6 = (Cons(3, Cons(2, Cons(4, Cons(6, Empty)))));;
let teste7 = [1;8;2;4;6;7;10;3];;

let lista_vazia l= 
        if l = [] then true
        else false;;

let inserir_no l n =
        match l with
        [] -> [n]
        |hd::tl -> n :: l

let rec inserir_fim l n =
        match l with 
        [] -> [n]
        |hd::tl ->(hd) :: (inserir_fim tl n);;

let retira_no l  =
        match l with
        [] -> invalid_arg "retira no"
        |hd::tl -> tl;;

let rec retira_fim l =
        match l with
        [] -> invalid_arg "retira_fim"
        |hd::[] -> []
        |hd::tl -> hd :: (retira_fim tl);; 

let rec busca_valor l n =
        match l with
        [] -> false
        |hd::tl -> if n = hd then true 
                   else busca_valor tl n;; 

let rec print_lista l =
        match l with
        [] -> " "
        |hd::tl -> print_string ((string_of_int hd) ^ " ") ; (print_lista tl);;

(*2.5 Em Ciência da Computação, uma árvore de busca binária é uma árvore binária tal que:
(a) Cada vértice v possui um valor rotulo(v) associado;
(b) Seja ve o filho à esquerda do vértice v . ve corresponde à raiz da sub-árvore
formada pelos vértices com valores menores que v ;
(c) Seja vd o filho à direita do vértice v . vd é a raiz da sub-árvore formada pelos
vértices com valores maiores que v .
Os valores são relevantes na árvore de busca binária, cujo objetivo é estruturar os
dados de forma flexível permitindo pesquisa binária. A seguir, descrevemos algumas
operações básicas sobre árvores de busca binária:

Buscas
Para a busca por um valor chave em uma árvore binária, começamos examinando o
vértice raiz v . Se chave for igual a rotulo(v) , o valor foi encontrado e a busca se
encerra. Se valor chave for menor que rotulo(v) , a busca deve continuar na sub-árvore
à esquerda de v ( ve ) e assim recursivamente. Similarmente, se o valor chave for maior que rotulo(v) , então devemos procura-lo na sub-árvore à direita de v ( vd ).
Se a busca alcançar um vértice folha da árvore, concluímos que a árvore não possui o
valor chave .
Inserções
A inserção começa com a busca pelo valor chave a ser inserido. Se o valor chave for
encontrado, a árvore binária não será modificada e o processo de inserção se
encerrará. Se o valor chave não existir na árvore, alcançaremos um vértice folha da
árvore, onde iremos inserir o valor chave . Em outras palavras, examinamos a raiz v e
introduzimos um vértice na sub-árvore à esquerda ( ve ) se o valor chave é menor que
rotulo(v) , ou na sub-árvore à direita ( vd ) se o valor chave for maior que
rotulo(v) .
Considerando que árvores de busca binária ou são vazias ( VAZIA ) ou possuem vértices
v com uma sub-árvore à esquerda ( ve ), um valor inteiro ( rotulo(v) ) e uma sub-árvore
à direita ( vd ), tais que:
type int_arvbin = VAZIA | VERTICE of (int_arvbin * int * int_arvbin);;
Pede-se a criação das seguintes funções:
busca: int -> int_arvbin -> bool , que realiza buscas por uma chave em
uma árvore de busca binária.
insercao: int -> int_arvbin -> int_arvbin , que toma uma árvore de
busca binária e um valor, inserindo-o na árvore.
altura: int_arvbin -> int , que calcula a altura de uma árvore binária, isto é,
o maior número arestas (ligações) conectando a raiz da árvore a uma folha
específica.
naovazios : int_arvbin -> int , que calcula o número de nós não-vazios de
uma árvore.*)


(*1.6 Definir uma funcao que, dada uma lista de inteiros l, retorna oprodutodos elementos de l.*)

let rec produto_lista l =
        match l with
        [] -> invalid_arg "produto_lista"
        |hd::[] -> hd
        |hd::tl -> hd * (produto_lista tl);;

(*2.6 Construir uma funcao que, dada uma lista de inteiros l, retorna a lista composta pelos dobros dos elementos de l, respeitando a ordem.*)

let rec dobro_lista l =
	match l with
		[] -> []
 		| hd :: tl -> (2 * hd) :: (dobro_int tl);;

(*3.6 Construir uma funcao que, dada uma lista de inteiros l, retorne uma lista com os elementos em ordem inversa dos de l.*)

let rec inverte_lista l =
        match l with 
        [] -> []
        |hd::tl -> (inverte_lista tl) @ [hd] 


(*4.6 Construir uma funcao que, dada uma lista de inteiros l, retorne uma lista com os elementos de l em ordem crescente.*)

let rec inserir_num l n =
       match l with
       [] -> [n]
       |hd::tl -> if hd>=n then n::hd::tl
                  else [hd] @ (inserir_num tl n);;
       
let rec ordena_lista l =
        match l with
        [] -> []
        |hd::tl -> inserir_num (ordena_lista tl) hd;;


(*5.6 Construa uma f0uncao elimint que, dada uma lista de inteiros e um numero inteiro, retorne uma lista onde todas as ocorrencias desse numero foram eliminadas. 
Exemplo de uso: elimInt [1,3,4,1,3,2] 1 = [3,4,3,2]*)

let rec elimint l n=
        match l with
        [] -> []
        |hd::tl -> if hd <> n then [hd] @ (elimint tl n)
                   else elimint tl n;;

(*6.6 Construa uma funcao membernum que, dada uma lista de inteiros e um valor inteiro,retorne o numero de ocorrencias desse valor na lista.
Exemplos de uso:
        memberNum [1,3,4,1,3,1] 1 =   3
        memberNum [1,3,4,1,3,1] 2 =   0
*)
let membernum l n=
        let rec aux  l n acc =
        match l with 
        [] -> acc
        |hd::tl -> if (hd = n) then (aux tl n (acc+1))
                   else (aux tl n acc) in (aux l n 0) ;;
(*7.6 Construa a funcao unique que, dada uma lista de inteiros, retorne uma lista contendo
    os valores que ocorrem exatamente uma vez na lista de entrada. Se voce achar
    conveniente, a definicao podera utilizar a funcao membernum da questao anterior.
    Exemplos de uso:
        unique [1,3,4,1,3,1,2]          =   [4,2]
        unique [1,3,1,3,1] =         []*)

let rec unique l =
        match l with
        [] -> []
        |hd::tl -> unique(elimnt tl hd);;

(*8.6 Uma lista é uma sublista de outra se todos os elementos da primeira estão presentes
    na segunda, na mesma ordem. Por exemplo, [1,3] é uma sublista de [1,2,3,4], mas
    não é uma sublista de [4,3,2,1]. Uma lista é uma subseqüência de outra se for uma
    sublista e todos os elementos ocorrerem em um único bloco. Por exemplo, [1,3] é uma
    subseqüência de [1,3,4], mas não é uma subseqüência de [1,2,3,4]. Defina funções
    para testar se uma lista é sublista e subseqüência de outra.*)


(*9.6 Uma lista associativa é uma lista de pares onde o primeiro item corresponde à chave e
    o segundo é o valor de interesse. Por exemplo, tratando-se de pessoas físicas, a chave
    pode ser o CPF e o valor de interesse um registro que guarda informações de interesse
    para um determinado negócio. Pensando nos casos excepcionais, defina:
                                                                                         1
   (a) Os tipos de dados necessários para representar listas associativas.
   (b) Uma função alist_find, que dada uma lista associativa l e uma chave k,
   testa se existe algum registro associado a essa chave.
   (c) Uma função alist_access, que dada uma lista associativa l e uma chave k,
   retorna o registro associado a essa chave.
   (d) Uma função alist_remove, que dada uma lista associativa l e uma chave k,
   retorna a lista associativa com os dados da chave removidos.
   (e) Uma função alist_insert, que dada uma lista associativa l, uma chave k,
   e um registro r, retorna a lista associativa com o par (k,r) inserido. Se já
   existe um registro associado a k, este é removido.*)

(*10.6 Grafos Dirigidos
   Em Matemática e Ciência da Computação, grafo é o objeto básico de estudo da teoria
   dos grafos. Tipicamente, um grafo é representado como um conjunto de pontos
   (vértices) ligados por retas (arestas). Dependendo da aplicação, as arestas podem ser
   direcionadas, e são representadas por "setas".
   Os grafos são muito úteis na representação de problemas da vida real, em vários
   campos profissionais. Por exemplo, pode-se representar um mapa de estradas através
   de grafos e usar algoritmos específicos para determinar o caminho mais curto, ou mais
   econômico, entre dois pontos. Portanto, os grafos podem também possuir rótulos, quer
   nas arestas quer nos vértices, para representar informações adicionais sobre o grafo
   (neste exemplo, os rótulos representariam o custo de deslocamento entre dois pontos).
   Um grafo dirigido com rótulos nas arestas pode ser representado pelo seguinte tipo
   OCaml :
       type ('a,'b) digrafo = ( 'a * 'b * 'a) list
   onde 'a é o tipo dos vértices e 'b é o tipo dos rótulos das arestas. Assim (1, "info", 2)
   significa que uma aresta com a informação "info" sai do vértice 1 para o vértice 2.
   Defina as funções seguintes:
   (a) conexo a b ar, que verifica se há um caminho entre a e b em ar.
   (b) mais_curto a b ar, que devolve o caminho mais curto (em termos de
       nodos percorridos) entre os vértices a e b na árvore ar.*)


type 'a arvbn = VAZIA | Vertice of 'a arvbn * 'a * 'a arvbn;;
let rec busca (n :'a) (a:'a arvbn) =
	match a with
	VAZIA -> false
	|Vertice(ve,v,vd) -> if v = n then true 
					 else
							if n < v then busca n ve (*busca n ve onde estao os valores menores q v*)
							 else busca n vd;;
(*1.7 Definir uma função swapmax que, dada dois valores v1 e v2 referências para um
    mesmo tipo, resulta na atribuição a v1 do maior dos valores referenciados por v1 e por
    v2 e na atribuição a v2 do menor desses dois valores.*)

(*2.7 Definir a função somareg que, dados dois registros r1 e r2, cada qual com dois
    campos mutáveis intval e floatval de tipo inteiro e float, respectivamente, produz um
    registro r3 de mesma estrutura e com campos intval e floatval cujos valores
    correspondem à soma das partes inteiras e flutuantes de r1 e r2, respectivamente.*)

(*3.7 Definir a função OCaml slref : int ref list -> int ref list -> int ref list que toma duas
    lista de referências para valores inteiros, l1 e l2, e produz uma terceira lista de
    referências para valores inteiros onde cada elemento é gerado pela soma entre os
    elementos de posições correspondentes de l1 e l2. Caso l1 e l2 não possuam o mesmo
    número de elementos, os itens da lista com maior número de elementos são copiados
    sem alteração para a terceira lista. Considere os exemplos abaixo:
    # slref [ref 1; ref 2; ref 3; ref 4] [ref 5; ref 6; ref 7; ref 8];;
    - : int ref list = [{contents = 6}; {contents = 8}; {contents = 10}; {contents = 12}]
    # slref [ref 1; ref 2; ref 3; ref 4] [ref 5; ref 6; ref 7];;
    - : int ref list = [{contents = 6}; {contents = 8}; {contents = 10}; {contents = 4}]
    # slref [ref 1; ref 2; ref 3] [ref 5; ref 6; ref 7; ref 8];;
    - : int ref list = [{contents = 6}; {contents = 8}; {contents = 10}; {contents = 8}]
    # slref [] [];;
    - : int ref list = []*)

(*4.7 Definir a função OCaml srlist : int list ref -> int list ref -> int list ref que toma duas
    referências para listas de valores inteiros, l1 e l2, e produz uma terceira referência para
    lista de valores inteiros onde cada elemento é gerado pela soma entre os elementos de
    posições correspondentes de l1 e l2. Caso l1 e l2 não possuam o mesmo número de
    elementos, os itens da lista com maior número de elementos são copiados sem
    alteração para a terceira lista. Considere os exemplos abaixo:
    # srlist (ref [2;4;6]) (ref [1;3;5]);;
    - : int list ref = {contents = [3; 7; 11]}
    # srlist (ref [2;4;6]) (ref [1;3]);;
    - : int list ref = {contents = [3; 7; 6]}
    # srlist (ref [2;4]) (ref [1;3;5]);;
    - : int list ref = {contents = [3; 7; 5]}
    # srlist (ref []) (ref []);;
    - : int list ref = {contents = []}*)



(*1.8 Crie uma função não-recursiva que toma um número inteiro estritamente positivo n e
    imprime na tela a soma dos n primeiros números inteiros. Verifique se o número
    informado é maior que zero. Crie sua implementação usando o laço for.*)

(*2.8 Idem, utilizando o laço while.*)

(*3.8 Crie uma função que imprima na tela apenas os números pares, de 0 a 100. Crie sua
    implementação usando o for.*)

(*4.8 Idem, utilizando o while.*)

(*5.8 Crie uma função não-recursiva que imprima os n primeiros termos da seqüência de
    Fibonacci, utilizando o laço for.*)

(*6.8 Idem, utilizando o laço while.*)

(*7.8 Construir uma função não-recursiva que, dada uma lista de inteiros retorna a lista
    composta pelos dobros dos elementos da lista original, respeitando a ordem.*)


(*1.9 Crie uma função OCaml não-recursiva que imprima os caracteres da tabela ASCII de
    códigos 48 a 57. A função deve imprimir cada caractere e seu código decimal.*)

(*2) O número de combinações de n objetos diferentes, onde r objetos são escolhidos de
    cada vez, é dado pela seguinte fórmula:
                                nCr = n! / (r! * (n-r)!)
    Onde x! representa o fatorial de x. Escreva uma função OCaml não-recursiva que
    calcule o número de combinações de n objetos tomados r de cada vez. Os valores n e r
    devem ser passados à função.
(3) Uma pessoa aplicou seu capital a juros e deseja saber, trimestralmente, a posição de
    seu investimento. Sendo c o capital inicial, t a taxa de juros do trimestre e p o perído
    em trimestres a ser avaliado, crie uma função OCaml não-recursiva que toma c, t e p e
    imprima uma tabela que informe, para cada trimestre considerado, o rendimento
    auferido e o saldo acumulado, supondo que nenhuma retirada tenha sido feita.
(4) Uma companhia de teatro planeja dar uma série de espetáculos. A direção calcula que,
    a R$5,0 o ingresso, serão vendidos 120 ingressos, e as despesas montarão R$200,00.
    A uma diminuição de R$0,50 no preço dos ingressos, espera-se que haja um aumento
    de 26 ingressos vendidos (despesas são fixas). Crie uma função OCaml não-recursiva
    que escreva uma tabela de valores do lucro esperado em função do preço do ingresso,
    fazendo-se variar este preço de R$5,0 a R$1,0, de R$0,5 em R$0,5. Escreva, ainda, o
    lucro máximo esperado, o preço e o número de ingressos correspondentes.

LAB 10

                                    Exercícios de Revisão
(1) Utilizando o laço while, crie uma função OCaml não-recursiva tabuada : int -> unit,
    onde 1 ? n ? 10, que imprime a tabuada de n. Exemplo:
    # tabuada 2;;
    TABUADA DO 2:
    2x1=2
    2x2=4
    2x3=6
    2x4=8
    2 x 5 = 10
    2 x 6 = 12
    2 x 7 = 14
    2 x 8 = 16
    2 x 9 = 18
    2 x 10 = 20
    - : unit = ()
(2) Idem, utilizando o laço for.
(3) Esta função OCaml imprime uma letra I bem grande na tela:
    let main () =
      print_string "\nIIIIIIIII\n";
      let i = ref 0 in
      while (!i < 17) do
          print_string "       III\n";
          i := !i + 1;
      done;
      print_string "IIIIIIIII\n";;
    (a) Modifique a função para que utilize um laço for no lugar do laço while.
    (b) Crie uma função similar que imprima a letra E.
    (c) Responda: neste exemplo, qual dos laços adapta-se melhor? Por que?
(4) Escreva uma função seno : float -> unit que calcula o seno de a, onde a é dado em
    radiano e 0 ? a ? 1,6, usando a série
                               sen a = a ? (a3/3!) + (a5/5!) ? ...
    com erro inferior a 0,0001. Informe, também, o número de termos usados.
    Obs. 1: em séries alternadas, o valor absoluto do erro cometido com a interrupção da
    série é inferior ao valor absoluto do primeiro termo abandonado.
    Obs. 2: a função abs_float : float -> float computa o valor absoluto de um float.
    Exemplo de uso:
    # seno 0.5;;
    Seno(0.5)= 0.479427083333 (3 termos usados)
    - : unit = ()
                                                                                       1
(5) A conversão de graus Farenheit para centígrados é obtida por:
                                   C = (5/9) * (F ? 32)
    Crie uma função OCaml não-recursiva centigrados : unit -> unit que calcule e
    escreva uma tabela de centígrados em função de graus Farenheit que variam de 50 a
    150, de 1 em 1 grau. Abaixo, parcial da saída desta função:
    # centigrados ();;
    Farenheit         Centigrados
    50                10.
    51                10.5555555556
    52                11.1111111111
    53                11.6666666667
    54                12.2222222222
    55                12.7777777778
    56                13.3333333333
    57                13.8888888889
    58                14.4444444444
    59                15.
    .
    .
    .
    - : unit = ()

2 ava

(* QUESTAO 01 *)
let rec inverter l =
 match l with
  [] -> []
 |a::b -> inverter b @ [a];;
let rec rotacao n l =
 match n,l with
   0, _ | _, [] | _, [_] -> l
 | n, l -> let a::b = inverter l in
                rotacao (n-1) (a :: inverter b);;
(* QUESTAO 02 *)
let qperfeito n =
  if n < 0 then invalid_arg "Consideramos apenas inteiros positivos."
  else
    let rec qp_aux n f =
      if n = f * f then true
      else
      if (f * f) > n then false
      else qp_aux n (f + 1)
    in qp_aux n 0;;
(* QUESTAO 03 *)
type 'a arvbin = VAZIA | VERTICE of ('a arvbin * 'a * 'a arvbin);;
let rec insercao n a =
  match a with
    VAZIA -> VERTICE(VAZIA,n,VAZIA)
  | VERTICE(ve,b,vd) -> if n = b then a else
                         if n < b then VERTICE (insercao n ve, b, vd)
                         else VERTICE (ve, b, insercao n vd);;
let rec list2arvbin l =
  match l with
    [] -> VAZIA
  | a::b -> insercao a (list2arvbin b);;*)





