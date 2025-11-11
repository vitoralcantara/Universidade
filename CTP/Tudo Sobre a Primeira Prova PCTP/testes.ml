(* QUESTAO 01 - TESTES REALIZADOS *)

idh 25.0 0.000 0.00 100.;;   (* 0. *)
idh 85.0 1.000 1.00 40000.;; (* 0.99999999888908031 *)
idh 67.8 0.873 0.95 7360.;;  (* 0.776487159447706632 *)
idh 75.0 0.900 0.98 9999.;;  (* 0.842868364344684928 *)
idh 50.0 0.500 0.40 500.;;   (* 0.383985039759440816 *)

(* QUESTAO 02 - TESTES REALIZADOS *)

ocorrencias ((1,1,1,1), 2);; (* 0 *)
ocorrencias ((1,3,1,2), 3);; (* 1 *)
ocorrencias ((2,1,2,1), 1);; (* 2 *)
ocorrencias ((3,3,2,3), 3);; (* 3 *)
ocorrencias ((1,1,1,1), 1);; (* 4 *)

(* QUESTAO 03 - TESTES REALIZADOS 01 *)

periodo {dia = 01; mes = 01; ano = 2000;} {dia = 01; mes = 01; ano = 2000};; (* 0 *)
periodo {dia = 15; mes = 04; ano = 2005;} {dia = 23; mes = 04; ano = 2005};; (* 8 *)
periodo {dia = 11; mes = 03; ano = 2000;} {dia = 01; mes = 02; ano = 2001};; (* 320 *)
periodo {dia = 25; mes = 09; ano = 1999;} {dia = 20; mes = 11; ano = 2007};; (* 2935 *)
periodo {dia = 25; mes = 09; ano = 1999;} {dia = 25; mes = 12; ano = 2007};; (* 2970 *)

(* QUESTAO 03 - TESTES REALIZADOS 02 *)

valor {dia = 01; mes = 01; ano = 2000} {dia = 01; mes = 01; ano = 2000} 15. 1. 0.5;;  (*  15.  *)
valor {dia = 01; mes = 01; ano = 2000} {dia = 30; mes = 12; ano = 1999} 15. 1. 0.5;;  (*  15.  *)
valor {dia = 01; mes = 01; ano = 2000} {dia = 30; mes = 01; ano = 2000} 15. 1. 0.5;;  (*  30.5 *)
valor {dia = 11; mes = 03; ano = 2000;} {dia = 01; mes = 02; ano = 2001} 15. 0. 0.6;; (* 207.  *)
valor {dia = 11; mes = 03; ano = 2000;} {dia = 01; mes = 02; ano = 2001} 15. 5. 0.;;  (*  20.  *)
