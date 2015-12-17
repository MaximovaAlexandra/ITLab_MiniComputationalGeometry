#include "set_points.h"


class ConvexHull  
{
	SetPoints hull; // оболочка, состоящая из набора точек
	int HullSize;
public:

	ConvexHull (SetPoints &a); 
	ConvexHull ( const ConvexHull &h);
	TPoint operator[] (int i);
	TPoint left (); // нахождение самой левой точки
	TPoint right(); // нахождение самой правой точки
	TPoint remote ( TPoint , TPoint , ConvexHull h); // наиболее удаленная точка от прямой l

	void Split (TPoint A, TPoint B, SetPoints &above, SetPoints &bellow);

	ConvexHull QiuckHull(SetPoints &h, TPoint leftpoint, TPoint rightpoint  ); 

};


