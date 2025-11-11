

(* Questão 01 *)


(*Defina uma função que recebe uma tupla t1 com 5 elementos inteiros e retorna a tupla
t2 formada pelos elementos de t1 em ordem inversa.*)



type cinco = int*int*int*int*int;;


let cinco (c:cinco) =


match c with
(a,b,c,d,e) -> (e,d,c,b,a);;


(* Questão 02 *)


(*Defina a função min3max que deve retornar um par formado pelo mínimo e pelo
máximo valor de 3 inteiros fornecidos.*)


type tres = int*int*int;;

let min3max (t:tres) =


match t with

(a,b,c) -> 

if a>b && a>c && b<c then (b,a) 
else
if b<a && b<c && a<c then (b,c)
 else
if a<b && a<c && c<b then (a,b) 
else
if a<b && a<c && c>b then (a,c)
 else
if c<b && c<a && a>b then (c,a) 
else (a,c);;



(* Questão 03 *)

(*Geometria planar cartesiana: pontos.*)

(*(a) Defina uma tupla para representar pontos no plano.*)

type point = float*float;; 

(*(b) Defina uma variável cujo valor é o ponto origem do plano.*)

let origem (o:point) = (0.,0.);;



(*(c) Defina uma função que calcula a distância entre dois pontos.*)

let distancia (p1:point)(p2:point) = sqrt( (fst p1 *. snd p2) ** 2. +. (fst p2 *. snd p1) ** 2.);;






(* Questão 04 *)

(*Geometria planar cartesiana: vetores.*) 

(*(a) Defina uma tupla para representar vetores.*)

type vetor = float*float;;
 let pi = 3.1415;;


(*(b) Defina duas variáveis cujos valores são os vetores unidades dos eixos abscissa e ordenada.*)

let abscissa a:vetor = (0.,1.);;


let ordenada o:vetor = (pi /. 2.,1.);;


(*(c) Defina uma função que, dada um vetor, calcula a norma do vetor.*)

let norma n:vetor = snd n;;




FALTA FAZER ESSE!!!!

(*(d) Define uma função que testa se dois vetores são colineares.*)

let colinear (c:vetr)=if fst c < (2. *. pi) then fst

 c else (mod_float (fst c) (2. *. pi));;

let colineares (c1:vetor)(c2:vetor) = 

if (fst c1 = fst c2) || float_of_int(abs(int_of_float(fst c1 -. fst c2))) = pi then true else false;;


FALTA FAZER ESSE!!!!






(*(e) Define uma função que retorna a soma de dois vetores.*)

let soma (v1:vetor)(v2:vetor) = 


(* Questão 05 *)

(*Geometria planar cartesiana: segmentos.*)

(*(a) Defina uma tupla segment para representar segmentos.*)

type segment = float*float*float*float;; (*x1 x2 y1 y1*)

(*(b) Defina uma função que, dada dois pontos p1 e p2, retorne o segmento com extremidades p1 e p2;*)

let segmento (p1:point)(p2:point) = (fst p1, fst p2, snd p1, snd p2);;

(*(c) Defina uma função que, dada um segmento s, retorne o comprimento de s.*)

let comprimento (s:segment) =
match s with
(x1,x2,y1,y2) -> sqrt((x1 -. x2) ** 2. +. (y1 -. y2) ** 2.);;


