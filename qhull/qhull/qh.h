#include "set_points.h"


class ConvexHull  
{
	SetPoints hull; // ��������, ��������� �� ������ �����
	int HullSize;
public:

	ConvexHull (SetPoints &a); 
	ConvexHull ( const ConvexHull &h);
	TPoint operator[] (int i);
	TPoint left (); // ���������� ����� ����� �����
	TPoint right(); // ���������� ����� ������ �����
	TPoint remote ( TPoint , TPoint , ConvexHull h); // �������� ��������� ����� �� ������ l

	void Split (TPoint A, TPoint B, SetPoints &above, SetPoints &bellow);

	ConvexHull QiuckHull(SetPoints &h, TPoint leftpoint, TPoint rightpoint  ); 

};


