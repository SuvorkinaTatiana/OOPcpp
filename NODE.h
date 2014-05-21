
#include <iostream>

template <class T>
struct Node {

Node ( T const & val) :
data( val) { 
	next = NULL;
	prev = NULL; }
		T data;
		Node * next;
		Node * prev;
	};

			
