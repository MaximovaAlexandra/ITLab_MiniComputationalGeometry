#include "tpoint.h"

TPoint :: TPoint (double x, double y)
{
	X=x;
	Y=y;
}

 TPoint :: TPoint( const TPoint & p )
 {
	 X = p.X;
	 Y = p.Y;
 }

TPoint TPoint :: operator+( TPoint &m)
{
	X+= m.X;
	Y+= m.Y;
	return (*this);
}

TPoint TPoint :: operator-( TPoint &m)
{
	X-= m.X;
	Y-= m.Y;
	return (*this);
}

bool TPoint :: operator >( TPoint &m)
{ 
	if ( (X > m.X) || ((X == m.X) && (Y > m.Y)) ) return true;
	else return false;
}


bool TPoint :: operator < ( TPoint &m)
{ 
	if ( (X < m.X) || ((X == m.X) && (Y < m.Y)) ) return true;
	else return false;
}

double TPoint :: length()
{
	return sqrt ( X*X + Y*Y );
}


double TPoint :: CheckPoint(TPoint a, TPoint b, TPoint c)   // ������������ ��������� 0 - ����� b ����� �� ������, >0 - ����, <0 - ����
 {
	 /// ��� �������: ��������, ���� � ���������� ����� 0.7, �� ��� ���������� � int ��� ������ 0
	 /// ����� ������ ����� ����
	 return (b.X-a.X)*(b.Y-c.Y)-(b.Y-a.Y)*(b.X-c.X);
}


 double TPoint ::operator [] (int i)
{
	if ( i == 0 )  return X;
	else  
		if ( i==1 ) return Y;
		else throw i;
}

 TPoint TPoint:: operator= ( const TPoint  &p )
 {
	 X = p.X;
	 Y = p.Y;
	 return ( *this);
 }


bool TPoint :: operator == ( const TPoint m) const
{
	if ( (X==m.X) && (Y==m.Y) ) return true;
	else return false;
}

 bool TPoint ::operator != ( const TPoint m) const
{
	if ( (X!=m.X) || (Y!=m.Y) ) return true;
	else return false;
}

double TPoint  :: VectorMult (TPoint  i,  TPoint j, TPoint k ) // ��������� ������������ [i,j,k]
{ 
	// ������� ������������ [i, j, k]  
	return ( i[0] * j[1] + k[0] * i[1] + j[0] * k[1] - k[0] * j[1] - i[0] * k[1] - j[0] * i[1] ); 
}