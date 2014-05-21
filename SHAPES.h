#include <string>
#include <iostream>
#include "xlist.h"
#include "NAMED.h"


class Point : public Shape , public Printable {

public:

	Point( std::string const & val , double const & x , double const & y ): 
	  Named(val) , 
	  Shape(val) , 
	  Printable(val) ,
	  m_x(x), m_y(y) {}
	virtual ~Point() {}

	virtual void Print( std::ostream & stream ) const { 
		stream << "Point: " << getName() << "\n" << m_x << "," << m_y << std::endl; 
	}

	double GetX() const { return m_x; }
	double GetY() const { return m_y; }

private:
	double m_x;
	double m_y;

};

class Circle : public Shape , public Printable {

public:
	Circle( std::string const & val , Point const & cntr , double rad ) : 
	  Named(val), 
	  Shape(val), 
	  Printable(val), 
	  m_cntr( cntr ) , m_rad( rad ) {
	  m_area = 3.14*m_rad*m_rad;
	  }


	virtual void Print( std::ostream & stream ) const { 
		stream << "Circle: " << getName() <<  "\n" << m_cntr <<  "\n" << "radius: " << m_rad <<"\n"
			<< "Area: " << getArea() << std::endl;
	}

private:
	Point m_cntr;
	double m_rad, m_area;

	double getArea() const { return m_area; }

};

class Rect : public Shape , public Printable {

public:
	Rect( std::string const & val, Point const & point1 , Point const & point2 ): 
	  Named( val ) , 
	 Shape( val ) , 
	 Printable( val) , 
	 m_p1(point1) ,
	 m_p2(point2) 
	 {
	   m_area = fabs((m_p2.GetX() - m_p1.GetX()) * (m_p2.GetY() - m_p1.GetY()));
	  }
	  
     Point const &  GetLeftBottom()const { return m_p1; }
      Point const & GetRightTop()const { return m_p2; }

	virtual void Print( std::ostream & stream ) const { 
		stream << "Rectangle:  " << getName() <<  "\n" <<  GetLeftBottom() <<  "\t" << GetRightTop()<<"\t"
			<<  "Area: " << GetArea() << std::endl;
	}


private:
	Point m_p1;
	Point m_p2;
	double m_area;
	double GetArea() const { return m_area; }
	double GetLeftBottom();

};

class Square : public Rect {

public:
	Square( std::string const & val , Point const & p1 , double p ): 
	  Named(val), 
      Rect(val , p1 , Point( "ptmp" , p1.GetX() + p , p1.GetY() + p ) ) ,
	  m_tmp(p) 
	  {
		  m_area = m_tmp * m_tmp;
	  }
	
	 

	virtual void Print( std::ostream & stream ) const { 
		stream << "Square: " << getName() << "\n" << "Area: " << GetArea() << std::endl;
	}

private:
	double m_area, m_tmp;
	double GetArea() const { return m_area; }
};

class Polyline : public Shape , public Printable {

public:
	Polyline( std::string const & val ):
	  Named(val) , 
	  Shape(val) ,
	  Printable(val) , 
	  m_length( 0.0 )
	  { }
	
	void AddPoint( Point const & point ) {
		if( m_points.Empty() ) {
			m_points.add_back( point );
			m_length += sqrt( point.GetX() * point.GetX() + point.GetY() * point.GetY() );
		}
		else {
			XList< Point >::XListIterator elem = m_points.tail();
			m_points.add_back(point);
			double dx = (*elem).GetX() - point.GetX();
			double dy = (*elem).GetY() - point.GetY();
			m_length += sqrt( dx*dx + dy*dy );
		}
	}

	virtual void Print( std:: ostream & stream ) const { 
		stream << "Polyline:  "<< getName() << "\n"  << "length:  " << m_length << "\n"  << "points:  " << m_points.size();
		if( m_points.Empty() )
			stream << "empty list";
		else
			stream <<  "\n"<< (*m_points.head()) << "\n" << (*m_points.tail());
	}


private:
	double m_length;
	XList< Point > m_points;

};
