#include <iostream>

using namespace std;

void Shell_Sort( int V[], int n) {

int temp; int inner, d =1;

//Descobre o elemento da sequencia "ótima".
// do
// d = 3*d -1;
while (d <= n)
d = 3*d -1;
cout << "Numerozinho: " << d << endl;

//Percorre os numeros do intervalo
int h = d/3;
while (h >=1){
cout << "Agora numerozinho eh: " << h << endl;

//Percorre a lista do elemento I até o final. (Outter)
for ( int outer = h; outer < n; outer++) {
temp = V[outer];

//Inner e Inner-h
int inner = outer;
while (inner >= h) {
	if ( V[(inner-h)] >= temp) {
		V[inner] = V[inner-h];
	}
	else break;
	inner -= h;
}
V[inner] = temp;
for (int r = 0; r < 40; r++) {
cout << V[r] << " ";
}
cout << endl;
}
h = h/3;
}
}

int main(int argc, char *argv[]) {
int v[40];
for (int i = 0; i < 40; i++) {
v[i] = 40-i;
}
for (int i = 0; i < 40; i++) {
cout << v[i];
}
cout << endl;
Shell_Sort (v, 40);
for (int r = 0; r < 40; r++) {
cout << v[r];
}
cout << endl;
system("PAUSE");
return EXIT_SUCCESS;
}
