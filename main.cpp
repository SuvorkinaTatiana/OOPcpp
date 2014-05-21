#include <iostream>
#include "StdAfx.h"
#include "shapes.h"


int main() {
	XList< Printable * > shapes;
	shapes.add_back( new Point( "new Point" , 0.0 , 1.0 ) );
	shapes.add_back( new Circle( "new Circle" , Point( "Circle center" , 0.0 , 0.0 ) , 2.0 ) );
	shapes.add_back( new Rect( "new Rectangle" , Point("Rectangle top left corner" , 3.0 , 2.0 ) , Point( "Rectangle top right corner" , 4.0 , 5.0 ) ) );
	shapes.add_back( new Square( "new Square" , Point( " Square top left bottom " , 1.0 , 1.0 ) , 2.0) );
	shapes.add_front( new Point( "new Point2" , 1.0 , 0.0 ) );
	shapes.add_front( new Circle( "new Circle2" , Point( "Circle center" , 1.0 , 1.0 ) , 3.0 ) );
	shapes.add_front( new Rect( "new Rectangle2" , Point( "Rectangle top left corner" , 4.0 , 3.0 ) , Point( "Rectangle top right corner" , 6.0 , 7.0 ) ) );
	shapes.add_front( new Square( "new Square2" , Point( " Square top left bottom " , 2.0 , 2.0 ) , 3.0) );
	Polyline * newPolyline = new Polyline( "new polyline" );
	newPolyline->AddPoint( Point( "Polyline p.1" , 0.2 , -0.2 ) );
    newPolyline->AddPoint( Point( "Polyline p.2" , 0.1, 0.0 ) );
	newPolyline->AddPoint( Point( "Polyline p.3" , 0.5 , 0.5 ) );
	newPolyline->AddPoint( Point( "Polyline p.4" , 3.0, -3.0 ) );
	shapes.add_front( newPolyline );

	std::cout << "Number of Shapes: " << Shape::GetCount() << std::endl;
	
	XList< Printable * >::XListIterator iEnd = shapes.tail().next();
	for( XList< Printable * >::XListIterator i = shapes.head(); i != iEnd; i.next() )
		std::cout << *(*i) << std::endl;

	std::cout << "Delete all" << std::endl;
		for( XList< Printable * >::XListIterator i = shapes.head(); i!= iEnd; i.next() )
		delete (*i);
	shapes.clear();

	std::cout << "Number of Shapes:" << Shape::GetCount() <<  std::endl;
	system ("PAUSE");

}
