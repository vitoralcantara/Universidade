#include <cstdlib>
#include <iostream>

using namespace std;

int fatorial(int a)
{
    int i=1, count;
    for (count=1;count<=a;count++)
    i *=count;
    return i;
}

int main(int argc, char *argv[])
{
    int a;
    cout << "Diga o valor para calcular o fatorial: ";
    cin  >> a;
    cout << "Fatorial eh: " << fatorial(a) << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
