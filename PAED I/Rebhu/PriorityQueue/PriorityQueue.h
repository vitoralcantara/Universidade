/**
* @file PriorityQueue.h
* @author Giuliano Vilela
*/

#ifndef _PQ_BH
#define _PQ_BH

#include<iostream>
#include <algorithm>
using std::swap;
using std::min;
using std::ostream;

template<typename Obj>
class PriorityQueue;

//! Imprime o conteúdo interno do BinaryHeap.
template<typename Obj>
ostream& operator<< (ostream& out, const PriorityQueue<Obj>& pq) {
	out << '[';
	for (int i = 1; i <= pq.size; ++i) {
		out << pq.binHeap[i];
		if (i != pq.size) out << ", ";
	}
	out << ']';
	return out;
}

/**
* PriorityQueue.
* Representa uma fila de prioridade modelada
* como um min-heap (extração contínua do elemento mínimo).
* Checa o elemento mínimo em O(1) e o extrai em O(logn).
* Inserção de um elemento em O(logn) ou O(1) (quebrando o heap, para consertar depois)
*/
template<typename Obj>
class PriorityQueue {
	public:
		PriorityQueue(const int&);
		PriorityQueue(const Obj*, int);
		PriorityQueue(const PriorityQueue<Obj>&);
		~PriorityQueue();
		const PriorityQueue& operator= (const PriorityQueue<Obj>&);
		void insert(const Obj&);
		void toss(const Obj&);
		const Obj popMin(void);
		const Obj& findMin(void);
		void deleteMin(void);
		bool isEmpty(void) const;
		void makeEmpty(void);
		const int queueSize(void) const;
		void fixHeap(void);
	protected:
		void percolateDown(int);
		void percolateUp(const Obj&);
		void checkSize(void);
		inline int parent(int) const;
		inline int leftChild(int) const;
		inline int rightChild(int) const;
		inline bool isLeaf(int) const;
		inline bool isValid(int) const;
	private:
		Obj* binHeap;
		int capacity;
		int size;
		bool orderOk;
		static int default_capacity;
	friend ostream& operator<< <> (ostream&, const PriorityQueue<Obj>&);
};

template<typename Obj>
int PriorityQueue<Obj>::default_capacity = 10;

//! Cria uma PQ vazia
template<typename Obj>
PriorityQueue<Obj>::PriorityQueue(const int& _size = default_capacity) {
	binHeap = new Obj[_size];
	size = 0;
	capacity = _size;
	orderOk = true;
}

//! Cria uma PQ baseada no conteúdo de vet (deep copy). Não mantêm integridade.
template<typename Obj>
PriorityQueue<Obj>::PriorityQueue(const Obj* vet, int tam) {
	binHeap = new Obj[tam+1];
	for (int i = 1; i < tam+1; ++i)
		binHeap[i] = vet[i];
	size = tam;
	capacity = tam+1;
	orderOk = false;
}

template<typename Obj>
PriorityQueue<Obj>::PriorityQueue(const PriorityQueue<Obj>& cp) {
	binHeap = new Obj[cp.capacity];
	for (int i = 1; i <= cp.size; ++i)
		binHeap[i] = cp.binHeap[i];
	size = cp.size;
	capacity = cp.capacity;
	orderOk = cp.orderOk;
}

template<typename Obj>
PriorityQueue<Obj>::~PriorityQueue() {
	delete[] binHeap;
}

template<typename Obj>
const PriorityQueue<Obj>& PriorityQueue<Obj>::operator=(const PriorityQueue<Obj>& rhs) {
	delete[] binHeap;
	binHeap = new Obj[rhs.capacity];
	for (int i = 1; i <= rhs.size; ++i)
		binHeap[i] = rhs.binHeap[i];
	size = rhs.size;
	capacity = rhs.capacity;
	orderOk = rhs.orderOk;
}

//! Inserção mantendo as propriedades do heap. O(logn)
template<typename Obj>
void PriorityQueue<Obj>::insert(const Obj& x) {
	checkSize();
	binHeap[++size] = x;
	percolateUp(x);
}

//! Inserção em O(1) sem necessariamente manter as propriedades do heap.
template<typename Obj>
void PriorityQueue<Obj>::toss(const Obj& x) {
	checkSize();
	binHeap[++size] = x;
	if (parent(size) != 0 && x < binHeap[parent(size)])
		orderOk = false;
}

//! Extrai e retorna o menor elemento do heap. O(logn)
template<typename Obj>
const Obj PriorityQueue<Obj>::popMin(void) {
	Obj x = findMin();
	deleteMin();
	return x;
}

//! Retorna o menor elemento em O(1). Caso o heap esteja quebrado, leva O(nlogn) para consertá-lo primeiro.
template<typename Obj>
const Obj& PriorityQueue<Obj>::findMin(void) {
	if (!orderOk) fixHeap();
	return binHeap[1];
}

//! Deleta o menor elemento em O(logn). Ou O(nlogn) caso precise consertar o heap.
template<typename Obj>
void PriorityQueue<Obj>::deleteMin(void) {
	if (!orderOk) fixHeap();
	binHeap[1] = binHeap[size];
	--size;
	percolateDown(1);
}

template<typename Obj>
bool PriorityQueue<Obj>::isEmpty(void) const {
	return (size == 0);
}

template<typename Obj>
const int PriorityQueue<Obj>::queueSize(void) const {
	return size;
}

//! Esvazia em tempo constante
template<typename Obj>
void PriorityQueue<Obj>::makeEmpty(void) {
	delete[] binHeap;
	binHeap = new Obj[default_capacity];
	size = 0;
	capacity = default_capacity;
	orderOk = true;
}

//! Procedimento nlogn para consertar as propriedades do heap.
template<typename Obj>
void PriorityQueue<Obj>::fixHeap(void) {
	if (orderOk) return;
	for (int i = parent(size); i > 0; --i)
		percolateDown(i);
	orderOk = true;
}

//! Realoca o elemento em binHeap[hole] para o seu lugar, mantendo a ordem do heap.
template<typename Obj>
void PriorityQueue<Obj>::percolateDown(int hole) {
	int left, right, next;
	while (true) {
		if (isLeaf(hole)) break;
		left = leftChild(hole);
		right = rightChild(hole);
		if (left <= size && binHeap[left] < binHeap[hole])
			next = left;
		else
			next = hole;
		if (right <= size && binHeap[right] < binHeap[next])
			next = right;
		if (next == hole) break;
		swap(binHeap[hole],binHeap[next]);
		hole = next;
	}
}

//! Coloca um elemento recém inserido em seu lugar, mantendo a ordem do heap.
template<typename Obj>
void PriorityQueue<Obj>::percolateUp(const Obj& x) {
	Obj c(x);
	int pos = size;
	while (!(parent(pos) == 0) && binHeap[parent(pos)] > binHeap[pos]) {
		swap(binHeap[parent(pos)],binHeap[pos]);
		pos = parent(pos);
	}
}

//! Checa se já chegou no limite, e gerencia a memória interna do heap se preciso.
template<typename Obj>
void PriorityQueue<Obj>::checkSize(void) {
	if (size < capacity-1) return;
	Obj* tmp = new Obj[capacity*2];
	for (int i = 1; i <= size; ++i)
		tmp[i] = binHeap[i];
	delete[] binHeap;
	binHeap = tmp;
	capacity *= 2;
}

//! Retorna o pai do nó p.
template<typename Obj>
inline int PriorityQueue<Obj>::parent(int p) const {
	return p/2;
}

//! Retorna a posição do filho esquerdo de p.
template<typename Obj>
inline int PriorityQueue<Obj>::leftChild(int p) const {
	return 2*p;
}

//! Retorna a posição do filho direito de p.
template<typename Obj>
inline int PriorityQueue<Obj>::rightChild(int p) const {
	return 2*p+1;
}

//! Checa se p é uma folha (retorna verdadeiro também se p for uma posição inválida)
template<typename Obj>
inline bool PriorityQueue<Obj>::isLeaf(int p) const {
	return (2*p > size);
}

//! Checa se p é uma posição válida.
template<typename Obj>
inline bool PriorityQueue<Obj>::isValid(int p) const {
	return (p <= size);
}

#endif
