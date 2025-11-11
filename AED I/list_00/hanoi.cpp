#include <cstdlib>
#include <iostream>

using namespace std;

int hanoi(int k,int init, int dest, int temp)
{
    if(k==0) printf("");
    else
    {
        hanoi((k-1),init,temp,dest);
        printf("Mover de %d para %d \n",init,dest);
        hanoi((k-1),temp,dest,init);
    }
    return(0);  
}      
int main()
{
    int n;
    printf("digite um numero: ");
    scanf("%d",&n);
    hanoi(n, 1, 3, 2);        
    system("PAUSE");
    return EXIT_SUCCESS;
}
