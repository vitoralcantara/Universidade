let printest z = 
let saida = (open_out "C:/Documents and Settings/Administrador/Desktop/liso.txt")
and res = ref z in
output_string (saida) (!res);
flush (saida)
 

let leitura (z:string) =
let file = (open_in "C:/Documents and Settings/Administrador/Desktop/liso.txt")
in let sentrada = (input_line(file)) in
(sentrada^z)  


(* Esse último é só teste mesmo *)
let teste n = 
let file = stdin and i = ref 0 
in let sentrada = (input_line(file)) in
let valor = ref n in
while (!valor <> 100) do
valor := int_of_string(sentrada);
i := !i +1;
done;
!i 