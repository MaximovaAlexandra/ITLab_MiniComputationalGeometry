#include <iostream>

using namespace std;
class TPoint
{
public:

	double X;
	double Y;

	TPoint( double a=0, double b=0 );
    TPoint( const TPoint & p );

	TPoint operator +(TPoint &);
    TPoint operator =(const TPoint &  );
	TPoint operator -(TPoint &);
	bool operator< (TPoint &);
	bool operator> (TPoint &);
	double operator [] (int);
	
	 bool operator == (const TPoint ) const;
	 bool operator != (const TPoint ) const;

	double CheckPoint(TPoint a, TPoint b, TPoint c); //  ќпредеение положени€ точки b относительно вектора ac
	double length();

	double VectorMult(TPoint  i,  TPoint j,  TPoint k); // ¬екторное произведение
};


