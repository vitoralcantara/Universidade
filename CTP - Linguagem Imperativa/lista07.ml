open Scanf;;

let obi () =
	let n_comp, n_pont = (scanf "%d %d\n" (fun x y -> (x, y))) in
	let resposta = (ref 0) in
	for i = 1 to n_comp do
		let a, b = (scanf "%d %d\n" (fun x y -> (x, y))) in
		let media = (a + b) in
		if (media >= n_pont) then
			 resposta := !resposta + 1;
	done;
print_int (!resposta);
print_newline();;

let _ = obi();;