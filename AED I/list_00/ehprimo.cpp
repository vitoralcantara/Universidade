#include <cstdlib>
#include <iostream>

using namespace std;

int EhPrimo(int a)
{
    int count;
    int n=0;
    for (count=2;count<a;count++)
    if (a % count == 0) n++;
    if (n>0) return 1;
    else return 0;
}
int main(int argc, char *argv[])
{
    int valor;
    cout << "Digite o valor para saber se eh primo ";
    cin  >> valor; 
    if (EhPrimo(valor))
    cout << "O numero NAO eh primo" << endl;
    else cout << "O numero eh primo" << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
 
