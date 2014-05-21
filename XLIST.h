#include <exception>
#include "NODE.h"

template < class T >
class XList {
	public:
	class XListException : public std::exception {
		virtual char const * what() const throw() 
		{ return "empty list"; };
	};


	class XListIterator {

	public:

		 XListIterator() : m_current( NULL ) {}
		
		  XListIterator(  XListIterator const & value ) { m_current = value.m_current; }
		  XListIterator( Node<T> * ptmp ) { m_current = ptmp; }

	 XListIterator & operator = ( XListIterator const & value ) {
			m_current = value.m_current;
			return *this;
		}

		bool operator == (  XListIterator const & value ) { 
			return m_current == value.m_current; }
		
		bool operator != (  XListIterator const & value ) { 
			return m_current != value.m_current; }

		T & operator * () { return m_current->data; }
		 XListIterator & next() { m_current = m_current->next; return *this; }
	     XListIterator & prev() { m_current = m_current->prev; return *this; }

	private:

		Node<T> * m_current;

	};
	


public:

	XList() : m_head( NULL ) , m_tail( NULL ) , m_size( 0 ) {}
	~XList() { clear(); }

	 XListIterator head() const { 
		 return  XListIterator( m_head ); }
	 XListIterator tail() const { 
		 return  XListIterator( m_tail ); }



	 void add_front( T const & val ) {
		Node<T> * tmp = new Node<T>(val);
		if( !Empty() ) {
			tmp->next =  m_head;
			m_head->prev = tmp;
			m_head = tmp;
		}
		else {
		    m_head = tmp;
			m_tail = tmp;
		}
		++m_size;
	}

	void add_back( T const & val) {
		Node<T>* tmp = new Node<T>( val);
		if( !Empty() ) {
			tmp->prev = m_tail;
			m_tail->next = tmp;
			m_tail = tmp;
		}
		else {
			 m_head = tmp;
		     m_tail= tmp;
		}
		++m_size;
	}

	void delete_front() {
		if ( Empty() )
			throw XListException();
		else {
			Node<T>* tmp =  m_head;
			m_first = m_first->next;
			delete tmp;
			--m_size;
		}
	}

	void delete_back() {
		if( Empty() )
			throw XListException();
		else {
			Node<T>* tmp = m_tail;
			m_tail= m_last->prev;
			delete tmp;
			--m_size;
		}
	}

	

	int size() const { return m_size; }

	bool Empty() const { return m_head == NULL; }

	void clear() {
		Node<T>* curr = m_head;
		while( curr!= NULL ) {
			Node<T>* tmp = curr;
			curr = curr->next;
			delete tmp;
		}
		 m_head = NULL;
	     m_tail = NULL;
		 m_size = 0;
	};
	
private:
	Node<T> *  m_head;
	Node<T> * m_tail;
	int m_size;

};
