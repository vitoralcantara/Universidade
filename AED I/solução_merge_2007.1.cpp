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

template <typename T>
class NodeSLL {
    public:
    T valor;
    NodeSLL * prox;
};

template <typename T>
void MergeSort( NodeSLL<T> * & );
template <typename T>
void merge( NodeSLL<T> *, NodeSLL<T> *, NodeSLL<T> * & );

template <typename T>
bool searchSLL( NodeSLL<T> *ptList, T value, NodeSLL<T> * & ptPrev );
template <typename T>
bool insertSLL( NodeSLL<T> * &ptList, T value );
template <typename T>
void printSLL( NodeSLL<T> *ptList );
template <typename T>
int sizeSLL( NodeSLL<T> *ptList );
template <typename T>
void destroySLL( NodeSLL<T> * &ptList );

int main( ) {
    NodeSLL< int > *myList = NULL;
    int vaiValues[] = { 4, 7, 3, 2, 8, 6, 0, 5, 9, 1 };

    for ( int ctV = 0; ctV < 10; ctV++ )
        insertSLL( myList, vaiValues[ ctV ] );

    cout << "List BEFORE merge sort (size " << sizeSLL( myList ) << "): ";
    printSLL ( myList );

    MergeSort( myList );

    cout << "List AFTER  merge sort (size " << sizeSLL( myList ) << "): ";
    printSLL ( myList );

    destroySLL ( myList );

    cout << "\n>>> Normal exiting!\n\n";
    return EXIT_SUCCESS;
}

template <typename T>
void MergeSort( NodeSLL<T> * & ptList ) {
    NodeSLL<T> * ptSL1 = NULL;
    NodeSLL<T> * ptSL2 = NULL;

    if ( sizeSLL( ptList ) > 1 ) {
        divide( ptList, ptSL1, ptSL2 );
        MergeSort( ptSL1 );
        MergeSort( ptSL2 );
        merge( ptSL1, ptSL2, ptList );
    }
}

template <typename T>
void divide( NodeSLL<T> * ptList, NodeSLL<T> * & ptSL1, NodeSLL<T> * & ptSL2 ) {
    int size = sizeSLL( ptList );
    NodeSLL<T> *ptCurrent = NULL;
    int ctN;

    for ( ctN = 0, ptSL1 = ptList, ptCurrent = ptList;
          ctN < ( (size/2) -1 ) ; ctN++ )
        ptCurrent = ptCurrent->prox;
    ptSL2 = ptCurrent->prox; // Initiate SL2.
    ptCurrent->prox = NULL; // Cut SL1 from SL2.
}

template <typename T>
void
merge ( NodeSLL<T> *ptFirst, NodeSLL<T> *ptSecond, NodeSLL<T> * & ptMerged ) {
    NodeSLL<T> * ptCurrent = NULL;

    // First list is null, then the second is the merged result.
    if ( ptFirst == NULL ) {
        ptMerged = ptSecond;
        return;
    } // Second list is null, then the second is the merged result.
    else if ( ptSecond == NULL ) {
        ptMerged = ptFirst;
        return;
    } // Define the head of the list.
    else if ( ptFirst->valor < ptSecond->valor ) {
        ptMerged = ptFirst;
        ptFirst = ptFirst->prox;
    }
    else {
        ptMerged = ptSecond;
        ptSecond = ptSecond->prox;
    }

    // Current node is the head of the list.
    ptCurrent = ptMerged;

    // The merge proceeds while there are elements in both lists.
    while ( ptFirst && ptSecond ) {

        if ( ptFirst->valor < ptSecond->valor ) {
            ptCurrent->prox = ptFirst;
            ptFirst = ptFirst->prox;
        }
        else {
            ptCurrent->prox = ptSecond;
            ptSecond = ptSecond->prox;
        }

        ptCurrent = ptCurrent->prox;
    }

    // Attache the rest of the remaining list.
    if ( ptFirst  == NULL )  ptCurrent->prox = ptSecond;
    if ( ptSecond == NULL )  ptCurrent->prox = ptFirst;
}

template <typename T>
int sizeSLL( NodeSLL<T> *ptList ) {
    int listSize = 0;
    while ( ptList ) {
        ++listSize;
        ptList = ptList->prox;
    }

    return listSize;
}


template <typename T>
bool searchSLL( NodeSLL<T> *ptList, T value, NodeSLL<T> * & ptPrev ) {
    NodeSLL<T> *ptCurrent = ptList;

    // Previous pointer is initially NULL.
    ptPrev = NULL;

    while ( ptCurrent ) {
        // Found it?
        if ( ptCurrent->valor == value )
            return true;
        // Update the pointer to previous node.
        ptPrev = ptCurrent;
        // Move current pointer
        ptCurrent = ptCurrent->prox;
    }

    return false;
}


template <typename T>
bool insertSLL( NodeSLL<T> * &ptList, T value ) {
    NodeSLL<T> *ptNewNode = NULL;
    NodeSLL<T> *ptPrev = NULL;

    // Search for a same value in the list, to avoid repetition
    if ( searchSLL( ptList, value, ptPrev ) ) {
        // Value already in the list (no repetitions allowed)
        return false;
    }
    // At this point ptPrev points to the last node of the list.

    // Allocate a new node, for insertion.
    try {  ptNewNode = new NodeSLL<T>;   }
    catch ( const bad_alloc& e ) {
        cerr << "\n[inserSLL()]: Erro durante alocacao da noh para insercao!\n";
        assert ( false );
    }
    ptNewNode->prox = NULL;
    ptNewNode->valor = value;

    // Basic case: empty list
    if ( ptList == NULL ) {
        ptList = ptNewNode;
    }
    else {
        // Find the last position of the list.
        ptPrev->prox = ptNewNode;
    }

    return true;
}

template <typename T>
void printSLL( NodeSLL<T> *ptList ) {
    cout << ">>> ";
    while ( ptList ) {
        cout << "[" << ptList->valor << "]";
        ptList = ptList->prox;
    }
    cout << endl;
}

template <typename T>
void destroySLL( NodeSLL<T> * &ptList ) {
    NodeSLL<T> *ptAux = ptList;

    while ( ptList ) {
        ptList = ptList->prox;
        delete ptAux;
        ptAux = ptList;
    }

    ptList = NULL;
}

/* =========================[ End of Merge.cpp ] ========================== */
