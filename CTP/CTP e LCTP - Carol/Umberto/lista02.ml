(* ##############################################################
################ Laboratório de LCTP - Turma 01 #################
#################################################################
########### Giuliano Vilela #### Alexsandro Norberto ############
################################################################# *)



(* QUESTÃO 01 ---------------------------------------------------------------------*)

let f x y z =
	(x>z) && (y<x);;
(* a função é booleano, ou seja, se a condição for verdadeira retorna true, se não, retorna false *)

(* Resultado -> <fun>:bool *)


(* QUESTÃO 02 ---------------------------------------------------------------------*)

type fracao_t = {num : int ; den : int};;

(*A*)
(*SOMA*)

let fracao_soma (f1:fracao_t)(f2:fracao_t) = 
{num = f1.num*f2.den + f1.den*f2.num; den = f1.den*f2.den};;


(*SUBTRAÇÃO*)

let fracao_sub (f1:fracao_t)(f2:fracao_t) = 
{num = f1.num*f2.den - f1.den*f2.num; den = f1.den*f2.den};;

(*MULTIPLICAÇÃO*)

let fracao_mult (f1:fracao_t)(f2:fracao_t) = 
{num = f1.num*f2.num; den = f1.den*f2.den};;

(*DIVISÃO*)

let fracao_div (f1:fracao_t)(f2:fracao_t) = 
{num = f1.num*f2.den; den = f1.den*f2.num};;

(*B*)

type fracao_t = {num : float ; den : float};;

let fracao_float (f1:fracao_t) = (f1.num)/.(f1.den);;



(* QUESTÃO 03 ---------------------------------------------------------------------*)
type complex = { a: float; b: float };;

(* soma *)
let soma_complex = fun (a:complex)(b:complex) ->
	{a = a.a +. b.a ; b = a.b +. b.b};;

(* multiplicaçao *)
let soma_multiply = fun (a:complex)(b:complex) ->
	{a = (a.a *. b.a) -. (a.b *. b.b);
	 b = (a.b *. b.a) +. (a.a *. b.b)};;

(* QUESTÃO 04  ------------------------------------ *)
type hour_t = { hh:int; mm:int; ss:int };;

let validate_hour = fun (time:hour_t) ->
	if ((time.hh <= 23 && time.hh >= 0) && (time.mm <= 59 && time.mm >= 0) &&
	    (time.ss <= 59 && time.ss >= 0)) then true else false;;

let min_hour = fun (time1:hour_t)(time2:hour_t) ->
	if (time1.hh > time2.hh) then false else
	if (time1.hh < time2.hh) then true else
	if (time1.mm > time2.mm) then false else
	if (time1.mm < time2.mm) then true else
	if (time1.ss > time2.ss) then false else
	if (time1.ss < time2.ss) then true else false;;

(* c *)
let seconds_from_midnight = fun (time:hour_t) ->
(time.ss + (time.mm * 60) + (time.hh * 3600));;

(* d *)
let time_difference = fun (time1:hour_t)(time2:hour_t) ->
let um = (seconds_from_midnight time1) and dois = (seconds_from_midnight time2) in
if ( um > dois ) then (um - dois) else (dois - um);;