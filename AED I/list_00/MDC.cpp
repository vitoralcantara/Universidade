#include <cstdlib>
#include <iostream>

using namespace std;

int  mdc (int a,int b, int c)
{
     int count, fator=1, menor;
     if      (a < b && a < c) menor=a;
     else if (b < a && b < c) menor=b;
     else menor=c;
     for (count=2;count<menor;count++)
     if ((a % count == 0) && (b % count == 0) && (c % count == 0)) fator=count;
     return count;
}
      
int main(int argc, char *argv[])
{
    int a,b,c;
    cout << "Diga os 3 valores para se achar o MDC ";
    cin  >> a >> b >> c;
    cout << "O MDC entre " << a << ", " << b << " e " << c << " eh " << mdc(a,b,c) << endl;  
    system("PAUSE");
    return EXIT_SUCCESS;
}
