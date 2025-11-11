#include <cstdlib>
#include <iostream>

using namespace std;

void ehamigo (int a, int b)
{
     int temp,count;
     if (a>b) 
     {
              temp = a;
              a = b;
              b = temp;
     }
     temp=0;
     for (count=1;count<b;count++)
     {
         if (b % count == 0)temp = temp + count;
     }
     if (a == temp)
     cout << "O numero " << a << " Eh Amigo de " << b << endl;
     else cout << "O numero " << a << " NAO eh Amigo de " << b << endl;
}   

int main(int argc, char *argv[])
{
    int a,b;
    cout << "Insira os dois valores para saber se sao amigos: ";
    cin >> a >> b;
    ehamigo(a,b);
    system("PAUSE");
    return EXIT_SUCCESS;
}
