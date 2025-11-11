(* (1)Crie   o   programa  OCaml  tabuada,   que   recebe   um  número  n  como   argumento   e 
imprime a tabuada de n. Exemplo:
$ ./tabuada 2
TABUADA DO 2:
2 x 1 = 2
2 x 2 = 4
2 x 3 = 6
2 x 4 = 8
2 x 5 = 10
2 x 6 = 12
2 x 7 = 14
2 x 8 = 16
2 x 9 = 18
2 x 10 = 20 *)

ocamlopt C:/Vítor/UFRN/PCTP/lab10.ml -o tabuada  

	let tabuada n =
	Printf.printf "TABUADA DO %d \n" n;
	for i = 1 to 10 do
	Printf.printf "%d x %d = %d \n" n i (n*i);
	done;
	
(* (2)Crie o programa  OCaml  wlist,   responsável  por   ler  uma  série de números   inteiros 
informados pelo teclado e armazená-los temporariamente em uma lista l. O processo 
de leitura e inserção na lista deve continuar até o usuário digitar 9999, que indica o 
final da série e não deve ser inserido em l. Após isso, a série de inteiros armazenada 
em l deve ser gravada em um arquivo texto chamado numeros.txt, seguindo a ordem 
em que eles foram inseridos na lista e separados por vírgulas. Considere usar a função 
read_int : unit -> int, que lê um inteiro do teclado e o retorna. *)

read_int ()


let wlist (n:int) =
let file = (open_out "C:/Documents and Settings/Administrador/Desktop/numeros.txt")
in let saida = (output_string(file) (string_of_int n))
in let leitura = ref n in
while (!leitura <> 9999) do
leitura := input_line();
saida;
flush (file);
done;




let adivinhacao n = 
   let i = ref 0 and found = ref false in
      while not !found do
         print_string "entre um numero:  ";   
         i := read_int ();  
         if !i = n then 
            found := true
         else if !i < n then
            print_endline "Maior"
         else
            print_endline "Menor";
         done;
         print_endline "Achou!"
