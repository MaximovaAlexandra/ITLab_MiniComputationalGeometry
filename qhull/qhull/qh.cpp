#include "qh.h"
#include "math.h"


ConvexHull :: ConvexHull (SetPoints &a)
{
	HullSize = a.Size;
	for ( int i=0; i < HullSize; i++)
		hull[i] = a[i];
}

ConvexHull :: ConvexHull ( const ConvexHull &h) 
{
	HullSize = h.HullSize;
	hull = h.hull;
}

TPoint ConvexHull :: operator[] (int i)
{
	return hull[i];
}

TPoint ConvexHull:: right () // сама€ права€ точка
{
	TPoint rig(0,0);
	for (int i = 1; i <= HullSize; i++)
		if  ( hull[i-1] > hull[i] )
			rig = hull[i-1];
		else
			rig = hull[i];
     return rig;
}

TPoint ConvexHull:: left () // сама€ лева€ точка
{
	TPoint lef(0,0);
	for (int i = 1; i <= HullSize; i++)
		if  ( hull[i-1] < hull[i] )
			lef = hull[i-1];
		else
			lef = hull[i];
     
	return lef;
}

TPoint ConvexHull ::  remote ( TPoint A, TPoint B, ConvexHull h ) // сама€ удаленена€ точка от пр€мой AB ( формула стр72, M.M.Ўульц)
{   
	TPoint t(0,0); 
	TPoint q(0,0);
	TPoint maxpoint(0,0);
	
	double dist; // отклонение
	double max = 0; //  максимальное отклонение

	for (int i=0; i < h.HullSize;  i++)
	{
    // выбираем точку пространтсва
	t = h[i];

	dist = t.VectorMult(A, B, t);

	if (dist > max ) { max = dist; maxpoint = t;}
	}

	return maxpoint;
}

void ConvexHull :: Split (TPoint A, TPoint B, SetPoints &above, SetPoints &bellow) // –аспределение пространства h на подпростравнтсва abov и bellow
{
	double temp=0;
	int i=0,j=0,k=0;
	for ( ; i < HullSize; i++ )
		{
			temp = A.CheckPoint( A, hull[i], B); // ћестоположение h[i] относительно AB
			if ( temp >= 0 ) above[k++] = hull[i];
			else  bellow[j++] = hull[i]; 
	
	    }
}


ConvexHull ConvexHull :: QiuckHull(SetPoints &h, TPoint leftpoint, TPoint rightpoint)
{
	int i =0;
	SetPoints s(0);
	ConvexHull res(s);


	TPoint lef, rig,rem;
	SetPoints abov(0), bel(0);
	lef = leftpoint;
	rig = rightpoint;
	
	rem = remote(lef,rig,h);
	
	lef = lef;
	rig = rem;
	Split( lef, rem, abov, bel);
	while ( i != bel.Size )
		res[i++] = bel[i];
	QiuckHull (abov, lef, rig );
	
	lef = rem;
	rig = rig;
	Split( lef, rem, abov, bel);
	while ( i != bel.Size )
		res[i++] = bel[i];
	QiuckHull (abov, lef, rig );
	return *this;
}












