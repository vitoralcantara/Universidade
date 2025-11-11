/**
* @file BinarySearchTree.h
* @author Giuliano Vilela
*/

#ifndef _BST_H
#define _BST_H

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <exception>
using std::stack;
using std::string;
using std::ostringstream;
using std::ostream;
using std::exception;

/**
* BST Namespace
* Guarda a classe BinarySearchTree, os seus iteradores e as exceções.
*/
namespace BST {

// Foward declaration dos Iteradores
template <typename Cmp>
class Iterator;
template <typename Cmp>
class PreOrderIterator;
template <typename Cmp>
class NavigateIterator;

/**
* BinarySearchTree
* Representa uma árvore binária de busca, com 
* boas estimativas assimptóticas de busca, inserção e remoção.
* Pode ser utilizada para representar conjuntos, hash tables, huffman trees etc...
*/
template <typename Cmp>
class BinarySearchTree {
	public:
		BinarySearchTree();
		BinarySearchTree(const BinarySearchTree<Cmp>&);
		BinarySearchTree(const BinarySearchTree<Cmp>&, const BinarySearchTree<Cmp>&, const Cmp& x);
		~BinarySearchTree();
		const BinarySearchTree& operator= (const BinarySearchTree<Cmp>&);
		PreOrderIterator<Cmp> beginPreOrder(void) const;
		NavigateIterator<Cmp> beginNavigate(void) const;
		const Cmp& findMin(void) const;
		const Cmp& findMax(void) const;
		bool contains(const Cmp&) const;
		bool isEmpty(void) const;
		void makeEmpty(void);
		void insert(const Cmp&);
		void remove(const Cmp&);
		const int& size(void) const;
		const string toString(void) const;
	protected:
		struct BNode {
			Cmp data;
			BNode *left, *right;
			BNode(const Cmp& x = Cmp(), BNode* lt = NULL, BNode* rt = NULL)
				: data(x), left(lt), right(rt) { }
		};
		int find (const Cmp&, BNode* t, BNode*&) const;
		void remove(const Cmp& x, BNode** t);
		void deleteTree (BNode*& t);
		const string toString(BNode*,const int&) const;
		BNode* root;
	private:
		int _size;
		BNode* clone(const BNode* t) const;
		BNode* findMin(BNode*) const;
		BNode* findMax(BNode*) const;
	friend class Iterator<Cmp>;
	friend class PreOrderIterator<Cmp>;
	friend class NavigateIterator<Cmp>;
};

/**
* Iterator
* Classe abstrata com os métodos comuns à
* todos os iteradores
*/
template<typename Cmp>
class Iterator {
	public:
		Iterator();
		Iterator(const Iterator<Cmp>&);
		virtual ~Iterator() { }
		const Cmp& operator*() const;
		bool operator==(const Iterator<Cmp>&) const;
		bool operator!=(const Iterator<Cmp>&) const;
		virtual bool done(void) const = 0;
		virtual bool isValid(void) const = 0;
		bool isLeaf(void) const;
		typename BinarySearchTree<Cmp>::BNode* getPt(void);
	protected:
		typename BinarySearchTree<Cmp>::BNode* pt;
};

/**
* PreOrderIterator
* Navega pela árvore em um processo de pré-ordem
*/
template<typename Cmp>
class PreOrderIterator: public Iterator<Cmp> {
	public:
		PreOrderIterator();
		PreOrderIterator(const PreOrderIterator&);
		PreOrderIterator(typename BinarySearchTree<Cmp>::BNode*);
		virtual ~PreOrderIterator() { }
		const PreOrderIterator& operator++();
		const PreOrderIterator operator++(int);
		bool done(void) const;
		bool isValid(void) const;
	private:
		stack<typename BinarySearchTree<Cmp>::BNode*> path;
};

/**
* NavigateIterator
* Apresenta métodos que permitem ao usuário navegar em qualquer direção
* válida da árvore (até acima), começando pelo nó raiz.
*/
template<typename Cmp>
class NavigateIterator : public Iterator<Cmp> {
	public:
		NavigateIterator();
		NavigateIterator(const NavigateIterator<Cmp>&);
		NavigateIterator(typename BinarySearchTree<Cmp>::BNode*);
		virtual ~NavigateIterator() { }
		const NavigateIterator& goLeft(void);
		const NavigateIterator& goRight(void);
		const NavigateIterator& goUp(void);
		bool done(void) const;
		bool isValid(void) const;
	protected:
		stack<typename BinarySearchTree<Cmp>::BNode*> path;
};

/**
* EmptyTree
* Exceção jogada quando uma operação inválida
* é feita em uma árvore vazia
*/
class EmptyTree : public exception {
	public:
		EmptyTree(const char* m = "Invalid Operation: Empty Tree") 
			: exception() { msg = m; }
		~EmptyTree() throw() { }
		const char* what() const throw() {
			return msg.c_str();
		}
	private:
		string msg;
};

/**
* BadIterator
* Exceção jogada quando uma operação inválida
* é feita em um iterador inválido (possivelmente nulo).
*/
class BadIterator : public exception {
	public:
		BadIterator(const char* m = "Invalid Operation: This Iterator is invalid") 
			: exception() { msg = m; }
		~BadIterator() throw() { }
		const char* what() const throw() {
			return msg.c_str();
		}
	private:
		string msg;
};


// Implementações

//! Cria uma árvore vazia
template<typename Cmp>
BinarySearchTree<Cmp>::BinarySearchTree() {
	root = NULL;
	_size = 0;
}

//! Deep copy de uma outra árvore. O(n).
template<typename Cmp>
BinarySearchTree<Cmp>::BinarySearchTree(const BinarySearchTree<Cmp>& cp) {
	root = clone(cp.root);
	_size = cp._size;
}

//! Deep copy de duas árvores simultaneamente, criando uma nova árvore com as duas sub-árvores. O(n1 + n2).
template<typename Cmp>
BinarySearchTree<Cmp>::BinarySearchTree(const BinarySearchTree<Cmp>& bst1, const BinarySearchTree<Cmp>& bst2, const Cmp& x = Cmp()) {
	BNode* left = clone(bst1.root);
	BNode* right = clone(bst2.root);
	root = new BNode(x,left,right);
	_size = bst1._size + bst2._size + 1;
}

//! Libera memória ocupada pelos nós. O(n).
template<typename Cmp>
BinarySearchTree<Cmp>::~BinarySearchTree() {
	deleteTree(root);
}

//! Libera memória e faz um deep copy da outra árvore. O(n)
template<typename Cmp>
const BinarySearchTree<Cmp>& BinarySearchTree<Cmp>::operator= (const BinarySearchTree<Cmp>& rhs) {
	deleteTree(root);
	root = clone(rhs.root);
	_size = rhs._size;
	return *this;
}

//! Retorna um PreOrderIterator da árvore.
template<typename Cmp>
PreOrderIterator<Cmp> BinarySearchTree<Cmp>::beginPreOrder(void) const {
	if (!root) throw EmptyTree("Invalid Operation: New PreOrderIterator on Empty Tree");
	return PreOrderIterator<Cmp>(root);
}

//! Retorna um NavigateIterator da árvore.
template<typename Cmp>
NavigateIterator<Cmp> BinarySearchTree<Cmp>::beginNavigate(void) const {
	if (!root) throw EmptyTree("Invalid Operation: New NavigateIterator on Empty Tree");
	return NavigateIterator<Cmp>(root);
}

//! Encontra o menor elemento da árvore. O(logn)
template<typename Cmp>
const Cmp& BinarySearchTree<Cmp>::findMin(void) const {
	return findMin(root)->data;
}

//! Encontra o maior elemento da árvore. O(logn)
template<typename Cmp>
const Cmp& BinarySearchTree<Cmp>::findMax(void) const {
	return findMax(root)->data;
}

//! Verifica se x pertence à arvore. O(logn)
template<typename Cmp>
bool BinarySearchTree<Cmp>::contains(const Cmp& x) const {
	return (find(x,root) == 1);
}

//! Determina se a árvore está vazia
template<typename Cmp>
bool BinarySearchTree<Cmp>::isEmpty(void) const {
	return (_size == 0); // (!root)
}

//! Libera a memória utilizada pela árvore. O(n)
template<typename Cmp>
void BinarySearchTree<Cmp>::makeEmpty(void) {
	deleteTree(root);
	_size = 0;
}

//! Inserção de um elemento na árvore em O(logn)
template<typename Cmp>
void BinarySearchTree<Cmp>::insert(const Cmp& x) {
	BNode* father;
	int f = find(x,root,father);
	if (f == 0)
		root = new BNode(x);
	else if (f == 2)
		father->left = new BNode(x);
	else if (f == 3)
		father->right = new BNode(x);
	if (f != 1)
		++_size;
}

//! Remoção de um elemento na árvore em O(logn)
template<typename Cmp>
void BinarySearchTree<Cmp>::remove(const Cmp& x) {
	remove(x,&root);
}

//! Tamanho da árvore em O(1).
template<typename Cmp>
const int& BinarySearchTree<Cmp>::size(void) const {
	return _size;
}

//! Clona uma árvore e retorna o novo nó em O(n).
template<typename Cmp>
typename BinarySearchTree<Cmp>::BNode* BinarySearchTree<Cmp>::clone(const BNode* t) const {
	if (t == NULL) 
		return (BNode*)NULL;
	else
		return new BNode(t->data,clone(t->left),clone(t->right));
}

//! Determina a existência de x na subárvore t em O(n).
template<typename Cmp>
int BinarySearchTree<Cmp>::find(const Cmp& x, BNode* t, BNode*& el = NULL) const {
	BNode* pt = t;
	while (pt) {
		el = pt;
		if (x == pt->data) return 1;
		if (x < pt->data) {
			if (pt->left == NULL) return 2;
			pt = pt->left;
		}
		else {
			if (pt->right == NULL) return 3;
			pt = pt->right;
		}
	}
	return 0;
}

//! Determina o menor elemento da subárvore t em O(n).
template<typename Cmp>
typename BinarySearchTree<Cmp>::BNode* BinarySearchTree<Cmp>::findMin(BNode* t) const {
	BNode* pt = t;
	if (t == NULL) throw EmptyTree("Invalid Operation: findMin on Empty Tree");
	while (pt->left)
		pt = pt->left;
	return pt;
}

//! Determina o maior elemento da subárvore t em O(n).
template<typename Cmp>
typename BinarySearchTree<Cmp>::BNode* BinarySearchTree<Cmp>::findMax(BNode* t) const {
	BNode* pt = t;
	if (t == NULL) return EmptyTree("Invalid Operation: findMax on Empty Tree");
	while (pt->right)
		pt = pt->right;
	return pt;
}

//! Remove x da subárvore t em O(n).
template<typename Cmp>
void BinarySearchTree<Cmp>::remove(const Cmp& x, BNode** t) {
	BNode* tmp;
	if (!t or !(*t)) throw EmptyTree("Invalid Operation: Remove on Empty Tree");
	if (x < (*t)->data) return remove(x,&((*t)->left));
	if (x > (*t)->data) return remove(x,&((*t)->right));

	if (!(*t)->left) {
		tmp = *t;
		*t = (*t)->right;
		delete tmp;
	}
	else if (!(*t)->right) {
		tmp = *t;
		*t = (*t)->left;
		delete tmp;
	}
	else {
		BNode** pt = &((*t)->left);
		while ((*pt)->right)
			pt = &((*pt)->right);
		(*t)->data = (*pt)->data;
		remove((*pt)->data,pt);
	}
	--_size;
}

//! Deleta uma árvore t em O(n).
template<typename Cmp>
void BinarySearchTree<Cmp>::deleteTree(BNode*& t) {
	BNode* pt;
	stack<BNode*> st;
	st.push(t);
	while (!st.empty()) {
		pt = st.top();
		st.pop();
		if (pt) {
			st.push(pt->left);
			st.push(pt->right);
			delete pt;
		}
	}
	t = NULL;
}

//! Representação em barras da sub-árvore com raiz t
template<typename Cmp>
const string BinarySearchTree<Cmp>::toString(BNode* t,const int& n) const {
	ostringstream buff;
	if (t == NULL) return string("");
	for (int i = 0; i < n; ++i)
		buff << "--";
	buff << ' ' << t->data << std::endl;
	buff << toString(t->left,n+1) << toString(t->right,n+1);
	return buff.str();
}

//! Representação em barras da Árvore Binária
template<typename Cmp>
const string BinarySearchTree<Cmp>::toString(void) const {
	return toString(root,0);
}

template<typename Cmp>
ostream& operator<< (ostream& out, const BinarySearchTree<Cmp>& bst) {
	out << bst.toString();
	return out;
}

// Iterador gen�rico

template<typename Cmp>
Iterator<Cmp>::Iterator() : pt(NULL) { }

template<typename Cmp>
Iterator<Cmp>::Iterator(const Iterator<Cmp>& it) : pt(it.pt) { }

template<typename Cmp>
const Cmp& Iterator<Cmp>::operator*() const {
	if (!pt) throw BadIterator("Invalid Operation: Retrieve on null pointer");
	return pt->data;
}

template<typename Cmp>
bool Iterator<Cmp>::operator==(const Iterator<Cmp>& it) const {
	return (pt == it.pt);
}

template<typename Cmp>
bool Iterator<Cmp>::operator!=(const Iterator<Cmp>& it) const {
	return (pt != it.pt);
}

//! Determina se o iterador está em uma folha da árvore
template<typename Cmp>
bool Iterator<Cmp>::isLeaf(void) const {
	if (!pt) throw BadIterator("Invalid Operation: Leaf checking on null pointer");
	return (!(pt->left) && !(pt->right));
}

template<typename Cmp>
typename BinarySearchTree<Cmp>::BNode* Iterator<Cmp>::getPt(void) {
	return pt;
}

// Iterador Pr�-Ordem

template<typename Cmp>
PreOrderIterator<Cmp>::PreOrderIterator() : Iterator<Cmp>() { }

template<typename Cmp>
PreOrderIterator<Cmp>::PreOrderIterator(const PreOrderIterator& it) {
	this->pt = it.pt;
	path = it.path;
}

template<typename Cmp>
PreOrderIterator<Cmp>::PreOrderIterator(typename BinarySearchTree<Cmp>::BNode* n) { 
	this->pt = n;
	if (!this->pt) throw BadIterator("Invalid Operation: New Iterator on null pointer");
	if (this->pt->right) path.push(this->pt->right);
	if (this->pt->left) path.push(this->pt->left);
}

//! Avança o iterador em um percurso pré-ordem
template<typename Cmp>
const PreOrderIterator<Cmp>& PreOrderIterator<Cmp>::operator++() {
	if (path.empty()) {
		if (!(this->pt)) throw BadIterator("Invalid Operation: Done traversing list");
		this->pt = NULL;
	}
	else {
		this->pt = path.top(); path.pop();
		if (this->pt->right) path.push(this->pt->right);
		if (this->pt->left) path.push(this->pt->left);
	}
	return *this;
}

template<typename Cmp>
const PreOrderIterator<Cmp> PreOrderIterator<Cmp>::operator++(int posfix) {
	PreOrderIterator<Cmp> old(*this);
	++(*this);
	return old;
}

//! Determina se o iterador já percorreu a árvore inteira
template<typename Cmp>
bool PreOrderIterator<Cmp>::done(void) const {
	return !(this->pt);
}

//! Determina se ainda há algum caminho possível para o iterador pré-ordem
template<typename Cmp>
bool PreOrderIterator<Cmp>::isValid(void) const {
	return this->pt;
}

// Iterador Navegador

template<typename Cmp>
NavigateIterator<Cmp>::NavigateIterator() : Iterator<Cmp>() { }

template<typename Cmp>
NavigateIterator<Cmp>::NavigateIterator(const NavigateIterator<Cmp>& it) : Iterator<Cmp>() {
	this->pt = it.pt;
	path = it.path;
}

template<typename Cmp>
NavigateIterator<Cmp>::NavigateIterator(typename BinarySearchTree<Cmp>::BNode* n) { 
	this->pt = n;
	if (!this->pt) throw BadIterator("Invalid Operation: New Iterator on null pointer");
}

//! Desce o iterador para a subárvore esquerda do nó atual
template<typename Cmp>
const NavigateIterator<Cmp>& NavigateIterator<Cmp>::goLeft(void) {
	if (!(this->pt->left)) throw BadIterator("Invalid Operation: Left node is null");
	path.push(this->pt);
	this->pt = this->pt->left;
	return *this;
}

//! Desce o iterador para a subárvore direita do nó atual
template<typename Cmp>
const NavigateIterator<Cmp>& NavigateIterator<Cmp>::goRight(void) {
	if (!(this->pt->right)) throw BadIterator("Invalid Operation: Right node is null");
	path.push(this->pt);
	this->pt = this->pt->right;
	return *this;
}

//! Sobe o iterador para o pai do nó atual.
template<typename Cmp>
const NavigateIterator<Cmp>& NavigateIterator<Cmp>::goUp(void) {
	if (path.empty()) throw BadIterator("Invalid Operation: Going up on root node");
	this->pt = path.top();
	path.pop();
	return *this;
}

//! Verifica se não pode mais descer na árvore.
template<typename Cmp>
bool NavigateIterator<Cmp>::done(void) const {
	return (!(this->pt->left) && !(this->pt->right));
}

//! Verifica se ainda pode descer na árvore
template<typename Cmp>
bool NavigateIterator<Cmp>::isValid(void) const {
	return (this->pt->left || this->pt->right);
}

}
#endif
