#include <cstdlib>
#include <iostream>

using namespace std;

void swap (int *i, int *j)
{
     int t = *i;
     *i = *j;
     *j = t;
}

int main(int argc, char *argv[])
{
    int *a,*b;
    a = new int;
    b = new int;
    cout << "Insira 2 valores ";
    cin  >> *a >> *b;
    swap(a, b);
    cout << "Os valores sao: " << *a << " e " << *b << endl;      
    system("PAUSE");
    return EXIT_SUCCESS;
}
