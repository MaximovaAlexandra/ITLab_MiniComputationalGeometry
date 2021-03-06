#include "TPoint.h"
#pragma once
class ConvexHull
{
public:
	TPoint *hull;   //������ ��� �������� ����� �������� ��������
	int k;   //���������� ����� � �������� ��������
	ConvexHull(TPoint p);
	~ConvexHull(void);
	int FindMaxX();  //������ ����� � ������������ �-�����������
	int FindMinX();  //������ ����� � ����������� �-�����������
	bool IsPointInHull(TPoint p);  //true ���� ����� ����������� �������� ��������
	int FindLeftSupportLine(TPoint p);   //����� ����� ������� ������
	int FindRightSupportLine(TPoint p);   //����� ������ ������� ������
	ConvexHull CreateNewConvexHull(TPoint p);
};

