#include <string>
#include <iostream>

class Named {

public:
	Named( std::string const & val ) : m_name( val )
	{}
	virtual ~Named()
	{}
	std::string const & getName() const { return m_name; }

private:
	std::string m_name;
};

class Printable : public virtual Named {

public:
	Printable( std::string const & val ) :
	  Named(val) 
	  {}
	virtual void Print( std::ostream & stream ) const = 0;
	virtual ~Printable() {}

};



class Shape : public virtual Named {

public:
	Shape( std::string const & val):
	  Named( val ) 
	{ ++sm_count;}
	Shape( Shape const & val ) :
	Named( val.getName() ) 
	{ ++sm_count; }
	virtual ~Shape() 
	{ --sm_count; }

	static int GetCount() 
	{ return sm_count; }

private:
	static int sm_count;

};

int Shape::sm_count = 0;

std::ostream & operator << ( std::ostream & stream , Printable const & object ) {
	object.Print( stream );
	return stream;}
