(*Aluna : Jaqueline Fereira*)
(*INTERA�O FOR WHILE*)
(*calcular o fatorial de um inteiro positivo.*)
let fatorial (n:int) =
        let fat = ref 1 in
        
        for i = n downto 1 do
                fat := !fat * i
        done;
!fat;;



(*dados dois inteiros positivos n e p, retornar n p (n elevado a p).*)

let potencia (n:int) (p:int) =
       let pot = ref 1 in
        for i = p downto 1 do
                pot := !pot * n
        done;
        !pot;;

(*calcular o maior divisor comum de dois inteiros positivos.*)

let mdc (a:int) (b:int) =
        let
                a_aux = ref a and
                b_aux = ref b in

        while !b_aux <> 0 do
                let 
                        temp = !b_aux in
                
                b_aux := !a_aux mod !b_aux;
                a_aux := temp 
        
        done;
        !a_aux;;

let mmc (a:int) (b:int) = 
       (a * b) / (mdc a b);; 

(*somar os elementos de uma lista de inteiros.*)
let s_lista (l:int list) =
        let 
                entrada = ref l and
                saida = ref 0 in

        for i=1 to (List.length l) do
                saida := !saida + (List.hd !entrada);
                entrada := List.tl !entrada
        done;
        !saida;;
(*retornar o maior elemento de uma lista de inteiros.*)

let max_lista (l:int list) =
        let
                entrada = ref l and
                max = ref 0 in
        
        for i=1 to List.length l do
                if (List.hd !entrada > !max) then (max := List.hd !entrada);
                entrada := List.tl !entrada
        done;
        !max;;

(*inserir um valor em uma lista ordenada crescente de inteiros.*)
let inserir_lista ( l : int list ) ( n : int ) =
        if ((l = []) || (n <= ( List . hd l ))) then n :: l
        else
                let 
                        saida = ref [] and
                        entrada = ref l in
        begin
                while (!entrada <> []) do 
                        
                        saida := !saida @ [ List.hd !entrada ] ; 
                        entrada := List . tl !entrada ;
                        
                        if ((!entrada = []) || (n <= List.hd !entrada)) then
                                
                                begin 
                                        saida := !saida @ n :: !entrada ;
                                        entrada := []
                                end 
               done ;
        !saida
        end;;

(*inverter uma lista.*)
let inverter_lista (l:int list) =
        
        let
                 
                saida = ref [] and  
                entrada = ref l in
        
        begin
                while (!entrada <> []) do
                        saida := List.hd !entrada :: !saida;
                        entrada := List.tl !entrada
                done;
        !saida
        end;;  
              
let inverter_lista (l:int list) =
        
        let
                 
                saida = ref [] and  
                entrada = ref l in
        
        begin
               for i=1 to List.length l do
                        saida := List.hd !entrada :: !saida;
                        entrada := List.tl !entrada
                done;
        !saida
        end;;  

(*somar os elementos de uma lista de inteiros.*)
let soma_lista (l:int list) = 
        let
                entrada = ref l and
                soma = ref 0 in

        for i = 1 to List.length l do
                soma := !soma + List.hd !entrada;
                entrada := List.tl !entrada
        done;
        !soma;;
        
(*construir a lista de todos os valores pares de uma lista de inteiros.*)
let lista_pares (l:int list) =
        let
                entrada = ref l and
                saida = ref [] in

        for i = 1 to List.length l do
                if ((List.hd !entrada) mod 2 = 0) then 
                        
                                saida :=!saida  @ [List.hd !entrada];
                                entrada := List.tl !entrada
               done;
        !saida;;   

let lista_pares (l:int list) =
        let
                entrada = ref l and
                saida = ref [] in

        while (!entrada <> []) do
                if ((List.hd !entrada) mod 2 = 0) then 
                        
                                saida :=!saida  @ [List.hd !entrada];
                                entrada := List.tl !entrada
               done;
        !saida;;

(*dado um inteiro positivo n, testa se n �um nmero primo.*)
let primo (n:int) = 
        let
                acc = ref 0 in
        
        for i = 1 to n do
                if (n mod i = 0) then acc := !acc + 1
        done;
        
        if (!acc > 2) then false
        else true;; 


(*ARRANJOS*)

(*Escrever uma fun�o para somar os elementos de um arranjo de inteiros.*)
let a2 = Array.create 4 27;;

let soma_vetor (v:int array) = 
        let sum = ref 0 in
        
        for i = 0 to (Array.length v)-1 do
              sum := !sum + v.(i)
        done;
        !sum;;       


(*Escrever uma fun�o para encontrar o maior elemento de um arranjo. Essa fun�o n� �definida para arranjos vazios.*)
let max_int (v:int array) = 
        if ((Array.length v) = 0) then invalid_arg "max_int";
        let max = ref 0 in
        
        for i = 0 to (Array.length v) - 1 do
              if (v.(i) > !max) then max:= v.(i)
        done;
!max;;

(*Escrever uma fun�o para buscar um elemento em um arranjo. Essa fun�o deve retornar o �dice da primeira posi�o onde o elemento se encontra, caso se encontra, e -1 caso contr�io.*)
let busca_vetor v n =
      if ((Array.length v) = 0) then invalid_arg "busca_vetor";
      let pos = ref ~-1 in
      
      for i = 0 to (Array.length v) - 1 do
              if (n = v.(i)) then  pos := i
      done;
    !pos;;  

(*Escrever uma fun�o que, dado um arranjo a e um valor v do mesmo tipo dos
* elementos do arranjo a, constr� um novo arranjo cujos elementos s� v na
* posi�o 0 e os elementos de a nas posi�o 1 at�Array.length a.*)
let vinserir = [|0;7;8;9;11|];;

let inserir_vetor v1 v=
        let v2 = Array.create 1 v  in
        Array.append v2 v1;;

(*dado um vetor v retorna um v' com o dobro de v*)
let vdobro = [|1;2;3;4;10|];;
let dobro_vetor v =
        let
                saida = (Array.create (Array.length v) 0 )in
    
        for i = 0 to (Array.length v) - 1 do
             saida.(i) <- 2 * v.(i)        
      done;
      saida;;

(*dado um vetor de strings v retorna um vetor de inteiros v' onde cada posi�o
* de v' corresponde ao tamanho da string *)
let vstring = [|"jaque";"ctp";"lctp"|];;

let vstring_vint (v:string array) =
        
        let
               saida = (Array.create (Array.length v) 0 )in
        
        for i = 0 to (Array.length v) - 1 do
                saida.(i) <- String.length v.(i)
        done;
        saida;;

(*dado um vetor de floats v retorna um vetor de inteiros v'*)

let vfloats = [|1.5;8.9;10.1;4.2|];;

let vfloat_vint (v:float array) =
        let 
                saida = (Array.create (Array.length v) 0) in

        for i = 0 to (Array.length v) - 1 do
               saida.(i) <- int_of_float v.(i)
        done;
        saida;;

(*aplica uma funcao f 'a-> 'b aplicada no vetor v retorna v' que �resultado da aplica�o de f em v*)

let vmap = [|1;20;4;60|];; 

let map (f: 'a -> 'b) (v:'a array) =
        if v = [||] then [||] 
        else
                let saida = (Array.create (Array.length v) (f v.(0))) in

                for i = 1 to (Array.length v) - 1 do
                        saida.(i) <- f v.(i)
                done;
                saida;;
(*refa� os exercicios anteriores utlizando a fun�o map*)
let map_dobro v = map (fun v -> 2 * v);;
let map_string_int = map (fun v -> String.length v);;
let map_floats = map (fun v -> int_of_float v);;

(*dado um vetor v de floats retorna o maior dos elementos*)
let vmfloats = [|1.5;8.5;8.4;9.2|];;

let max_float (v:float array) =
       if ((Array.length v) = 0) then invalid_arg "max_float";
      
       let max = ref 0.0 in

       for i = 0 to (Array.length v) - 1 do
               if (v.(i) > !max) then max := v.(i) 
       done;
       !max;;

(*dado um vetor tipo string retorna a concatena�o dos seus elementos na mesma
ordem ex: [|"a";"bb";"ccc"|] abbccc *)

let vcstring = [|"a";"bb";"ccc"|];;

let concatenacao_vetor (v: string array) =
        if ((Array.length v) = 0) then invalid_arg "concatenacao_vetor";
        let palavra = ref "" in
        
        for i = 0 to (Array.length v) - 1 do
              palavra := !palavra ^ v.(i)
        done;
        !palavra;;     

(*# Array.fold_right (fun elem acc -> elem ^ acc) [| "oi"; "gente"; "hello"; "world" |] "" ;;
- : string = "oigentehelloworld"*)

(*dado um vetor tipo string retorna a concatena�o dos seus elementos separados
 "-" na mesma ordem ex: [|"a";"bb";"ccc"|] a-bb-ccc *)

let hifen_vetor (v: string array) =
        if ((Array.length v) = 0) then invalid_arg "concatenacao-vetor";
        let palavra = ref "" in
        
        for i = 0 to (Array.length v) - 1 do
              palavra := !palavra ^ v.(i) ;
              
              if (i < ((Array.length v) -1)) then
                for i = 0 to 0 do
                      palavra := !palavra ^ "-"
                done        
        
        done;
        !palavra;;

(*Seja um vetor v de valores dp tipo 'a, um valor init do tipo 'b, e uma
* fun�o f do tipo 'b -> 'a -> 'b.Seja entao a seq s tal que s(0) = init e
* s(n+1)=f s(n) v.(n),ou seja s(n+1) �o resultado da aplica�o de f a s(n) e
* v.(n), o elemento de v na posi�o..Defina uma fun�o que, dados v,init e
* f,calcule s(m), onde m �o numero de elementos de v resolva as qstoes 4 a 8
* com essa fun�o 

s : v[] n f m -> *)
(*dado dois vetores inteiros de mesmo tamanho retorne um terceiro que seja a soma dos dois*)
let vsoma1 = [|1;2;3;17|] and vsoma2 = [|9;5;6;10|];;

let soma2_vetores (v1:int array) (v2:int array) =
        if ((Array.length v1) <> (Array.length v2)) then invalid_arg
        "soma2_vetores";
        let soma = Array.create (Array.length v1) 0 in
        
        for i = 0 to (Array.length v1) - 1 do
                soma.(i) <- v1.(i) + v2.(i)
        done;
        soma;;

(*dado dois vetores de tipo float de mesmo tamanho retorna um terceiro que contem em cada posi�o o maior elemento entre os dois vetores *)

let vmax1 = [|1.5;7.8;9.1|] and vmax2 = [|5.0;6.2;7.1|];;

let max2_vetores (v1:float array) (v2: float array) =
        if ((Array.length v1) <> (Array.length v2)) then invalid_arg "max2_vetores";
       let max = (Array.create (Array.length v1) 0.0) in

        for i=0 to ((Array.length v1) - 1) do
           if (v1.(i) >= v2.(i)) then max.(i) <- v1.(i) 
           else max.(i) <- v2.(i)
        done;
     max;;   

(*dado dois vetores v v'do mesmo tamanho retorne w que sera composto dos elementos de v elevados aos elementos de v' ex v=[|1;2;3|] v'=[|3;2;1|] w =[|1;2;3|]*)

let vpot1 = [|8;9;10|] and vpot2 = [|2;3;0|];;


let potencia_vetores (v1:int array) (v2:int array) =
         if ((Array.length v1) <> (Array.length v2)) then invalid_arg "potencia_vetores";
         let 
                potencia_aux (a:int) (b:int) =
                        let pot = ref 1 in
        
                        for i=b downto 1 do
                                pot := !pot * a
                        done;
                        !pot and
                pot_vetor = (Array.create (Array.length v1) 0) in
         
         for i=0 to ((Array.length v1) - 1) do
              pot_vetor.(i) <- (potencia_aux v1.(i) v2.(i))
         done; 
         pot_vetor;;

(*13 Seja um vetor v de valores do tipo 'a, um vetor v' de valores do tipo 'b, e
* uma fun�o f do tipo 'a -> 'b -> 'c. Defina uma funcao que retorna o vetor w
* de valores do tipo 'c, de mesmo tamanho que v e 'v, tal que o valor na i-esima
* posi�o de w �igual a aplica�o de f ao valor na i-esima posi�o de v e o
* valor na i-esima posi�o de v'.refa� o exercico 10 a 12*)

let map (f: 'a -> 'b -> 'c) (v1:'a array) (v2:'b array) =
        if ((Array.length v1) <> (Array.length v2)) then invalid_arg "map"
        else
                let saida = (Array.create (Array.length v1) (f v1.(0) v2.(0)) ) in

                for i = 1 to (Array.length v1) - 1 do
                        saida.(i) <- f v2.(i) v1.(i)
                                      done;
                saida;;


(*Escreva uma fun�o que, dada um arranjo, ordena os elementos de forma
* crescente no arranjo. ex: [| alo ; cara ; tudo ; bem |] -> [| alo ;
* bem ; cara ; tudo |]*)

(*BUBBLESORT (V[], n)
1    houveTroca <- verdade                       # uma variável de controle
2    enquanto houveTroca for verdade faça
3         houveTroca <- falso
4         para i de 1 até n-1 faça
5              se V[i] vem depois de V[i + 1]
6                   então troque V[i] e V[i + 1] de lugar e
7                         houveTroca <- verdade*)

(*nau deu certo*)
let ordena_vetor (v:string array) = 
	let troca = ref true in
	
	while (!troca = true) do
		troca := false ;
		for i = 0 to (Array.length v) - 1 do
			let temp = v.(i) in
				if ((i+1) >= (Array.length v)) then troca := false
				else(
				if (v.(i) > v.(i + 1)) then 
					(v.(i) <- v.(i+1);
					v.(i+1) <- temp;
					troca:= true))
		done
		done;
v;;         

(*Escreva uma fun�o que, dada um arranjo de nmeros float, determina qual a maior
soma dos elementos em uma faixa do arranjo.
[| 2.1 ; -3.0 ; 2.2 ; 1.0 ; -0.1 ; 0.2 |] -> 3.3*)

let somamax_floats (v:float array) = 
let soma = ref 0.0 in
	for i = 0 to (Array.length v) - 1 do
			soma := !soma +. v.(i);
			if (!soma < 0.0) then soma := 0.0
	done;
printf"%.2f\n" !soma;;


(*obs. se todos os elementos s� negativos, retornar o valor 0.0.
Escreva uma fun�o que, dada um arranjo de nmeros float, determina qual o tamanho
da maior faixa crescente.
[| 2.1 ; -3.0 ; 2.2 ; 1.0 ; -0.1 ; 0.2 |] -> 2
obs. se os valores est� em ordem decrescente, retornar o valor 0.*)

let check_sudoku (int array) = 
	let
			res = ref true and
			i = ref 0 and
		  j = ref 0 
			
			while ((!res && i) < 9) do
				if (g.(i).(j) > 9) || g.(i).j() < 1



