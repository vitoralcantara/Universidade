/*!
 ===========================================================================
 SOURCE FILE : fibonancci.cpp
 ===========================================================================
 DESCRIPTION.: Exemplo 1
 AUTHOR......: Demétrios.
 LOCATION....: DIMAp/UFRN.
 SATARTED ON.: Aug/2008
 TO COMPILE..: g++ -Wall fibonacci.cpp -o fibonacci
 ---------------------------------------------------------------------------
*/

/* includes*/

#include <iostream>
using namespace std;

/*Global Variables*/
int a, aux, l=1, z=0;

/* DECLARATION OF THE MAIN PROGRAM */
int main (){
  cout << "informe um nunero:";
  cin >> a;
  if (a < 0) cout << "informe um numero positivo!!";
  else{ 
	cout << l << " ";
	while (l < a){
   	   aux = z;
    	   z = l;
    	   l = z + aux;
           if (l >= a) break;
   	   cout << l << " ";
    	}
   }
return 0;
}

