#include <cstdlib>
#include <iostream>

using namespace std;

void EhPar(int a)
{
    if (a % 2 == 0)
    cout << "O numero EH par" << endl;
    else cout << "O numero NAO eh Par" << endl;

} 
int main(int argc, char *argv[])
{
    int valor;
    cout << "Diga o valor para saber se eh par ";
    cin >> valor;
    EhPar(valor);
    system("PAUSE");
    return EXIT_SUCCESS;
}
