#include <cstdlib>
#include <iostream>

using namespace std;

void swap (int *i, int *j)
{
     int t = *i;
     *i = *j;
     *j = t;
}
void ordena3(int& a, int& b, int& c, char escolha)
{
     
     if (a < b && b > c) swap(b,c); 
     if (a > b && b < c) { swap(a,b); swap(b,c); }
     if (a < b && b > c) { swap(b,c); swap(a,b); }
     if (a > b && b < c) { swap(a,b); swap(b,c); }
     if (a > b && b > c) swap(a,c);
     if (escolha == 'f') swap(a,c);
     
}
                             
int main(int argc, char *argv[])
{
    int a,b,c;
    char sf;
    cout << "Digite 3 numeros e depois <V> para ordem crescente e <F> para decrescente: ";
    cin >> a >> b >> c >> sf;
    ordena3(a,b,c,sf);
    cout << " Os valores sao " << a << ", " << b << ", " << c << endl; 
    system("PAUSE");
    return EXIT_SUCCESS;
}
