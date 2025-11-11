// General includes
#include <new>
using std::bad_alloc;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <vector>
using std::vector;

#include <cassert>

typedef struct _NodeAB {
    int valor;
    struct _NodeAB * Esq;
    struct _NodeAB * Dir;
} NodeAB;

bool ehSemEspelhada( const NodeAB * const ptRaiz1, const NodeAB * const ptRaiz2 ) {
    bool answer = false;

    if ( ptRaiz1 == NULL && ptRaiz2 == NULL )
        answer = true;
    else if ( ptRaiz1 != NULL && ptRaiz2 != NULL ) {
        if ( ptRaiz1->valor == ptRaiz2->valor &&
             ehSemEspelhada( ptRaiz1->Esq, ptRaiz2->Dir ) &&
             ehSemEspelhada( ptRaiz1->Dir, ptRaiz2->Esq ) )
           answer = true;
    }

    return answer;
}


int main( ) {
    NodeAB * ptN1, * ptN2, *ptN3, *ptN4, *ptN5;

    ptN1 = new NodeAB;
    ptN2 = new NodeAB;
    ptN3 = new NodeAB;
    ptN4 = new NodeAB;
    ptN5 = new NodeAB;

    ptN1->Esq   = ptN2;
    ptN1->Dir   = ptN3;
    ptN1->valor = 1;
    ptN2->Esq   = ptN4;
    ptN2->Dir   = ptN5;
    ptN2->valor = 2;
    ptN3->Esq   = NULL;
    ptN3->Dir   = NULL;
    ptN3->valor = 3;
    ptN4->Esq   = NULL;
    ptN4->Dir   = NULL;
    ptN4->valor = 4;
    ptN5->Esq   = NULL;
    ptN5->Dir   = NULL;
    ptN5->valor = 5;

//          1           1
//       2     3  =  3     2
//     4   5             5   4

    NodeAB * ptM1, * ptM2, *ptM3, *ptM4, *ptM5;

    ptM1 = new NodeAB;
    ptM2 = new NodeAB;
    ptM3 = new NodeAB;
    ptM4 = new NodeAB;
    ptM5 = new NodeAB;

    ptM1->Esq   = ptM3;
    ptM1->Dir   = ptM2;
    ptM1->valor = 1;
    ptM2->Esq   = ptM5;
    ptM2->Dir   = ptM4;
    ptM2->valor = 2;
    ptM3->Esq   = NULL;
    ptM3->Dir   = NULL;
    ptM3->valor = 3;
    ptM4->Esq   = NULL;
    ptM4->Dir   = NULL;
    ptM4->valor = 4;
    ptM5->Esq   = NULL;
    ptM5->Dir   = NULL;
    ptM5->valor = 5;

    cout << "Eh Semelhante? " << ehSemEspelhada ( ptN1, ptM1 ) << endl;

    cout << "\n>>> Normal exiting!\n\n";
    return EXIT_SUCCESS;
}

/* =========================[ End of sem_espelhada.cpp ] ========================== */
