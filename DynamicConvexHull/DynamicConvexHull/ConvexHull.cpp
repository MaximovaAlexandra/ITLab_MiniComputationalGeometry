#include "StdAfx.h"
#include "ConvexHull.h"


ConvexHull::ConvexHull(TPoint p)
{
	k=1;
	hull=new TPoint[k];
	hull[0]=p;
}

ConvexHull::~ConvexHull(void)
{
	delete[] hull;
}

int ConvexHull:: FindMaxX(ConvexHull a) //������ ����� � ������������ �-�����������
{
	int n=0;
	int xn=hull[0][0];
	for(int i=1; i<a.k; i++)
		if (hull[i][0]>xn)
		{
			xn=hull[i][0];
			n=i;
		};
	return n;
}

int ConvexHull:: FindMinX(ConvexHull a)  //������ ����� � ����������� �-�����������
{
	int m=0;
	int xm=hull[0][0];
	for(int i=1; i<a.k; i++)
		if (hull[i][0]<xm)
		{
			xm=hull[i][0];
			m=i;
		};
	return m;
}

bool ConvexHull:: IsPointInHull(TPoint p)  //true ���� ����� ����������� �������� ��������
{
	int m=FindMinX(*this);   //������ ����� � ����������� �-�����������
	int n=FindMaxX(*this);  //������ ����� � ������������ �-�����������
	//������� ��� ������� - ������� � ������, ������� ��������� ������ MN
	int ku;  //������ �������� �������
	int kd;   //������ ������� �������
	TPoint *u;  //������� ������
	TPoint *d;    //������ ������
	if (m<n)
	{
		ku=k-(n-m-1);
		u=new TPoint[ku];
		kd=n-m+1;
		d=new TPoint[kd];
		int i=0;
		for (int j=m; j>=0; i++,j--)
			u[i]=hull[j];
		i++; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		for (int j=k-1; j<=n; j++,i++)
			u[i]=hull[j];
		i=0;
		for (int j=m; j<=n; j++,i++)
			d[i]=hull[j];
	}
	else //if m>n !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!m=n
	{
		ku=n-m+1;
		u=new TPoint[ku];
		kd=k-(n-m-1);
		d=new TPoint[kd];
		int i=0;
		for (int j=m; j<=k; i++,j++)
			d[i]=hull[j];
		i++; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		for (int j=0; j<=n; j++,i++)
			d[i]=hull[j];
		i=0;
		for (int j=m; j<=n; j++,i++)
			u[i]=hull[j];
	}
	bool fl=true;
	int i=0;
	while ((fl)&&(i<ku-1))
	{
		if (p[1]*(u[i][0]-u[i+1][0])-p[0]*(u[i][1]-u[i+1][1])+u[i][1]*u[i+1][0]-u[i+1][1]*u[i][0]>0)
			fl=false;
		i++;
	}
	i=0;
	while ((fl)&&(i<kd-1))
	{
		if (p[1]*(d[i][0]-d[i+1][0])-p[0]*(d[i][1]-d[i+1][1])+d[i][1]*d[i+1][0]-d[i+1][1]*d[i][0]<0)
			fl=false;
		i++;
	}
	return fl;
}

int ConvexHull:: FindLeftSupportLine(TPoint p)   //����� ����� ������� ������
{
	int l=-1;
	for (int i=0;i<k; i++)
	{
		bool fl=true;
		int j=0;
		while ((fl)&&(j<k))
		{
			if (hull[j][1]*(p[0]-hull[i][0])-hull[j][0]*(p[1]-hull[i][1])+p[1]*hull[i][0]-hull[i][1]*p[0]>0)
				fl=false;
		j++;
		}
	if (fl) 
		if (l=-1)
			l=i;
		else
			if (p.distance(hull[l])<p.distance(hull[i]))
				l=i;
	i++;
	}
	return l;
}
int ConvexHull:: FindRightSupportLine(TPoint p)   //����� ������ ������� ������
{
	int r=-1;
	for (int i=0;i<k; i++)
	{
		bool fl=true;
		int j=0;
		while ((fl)&&(j<k))
		{
			if (hull[j][1]*(p[0]-hull[i][0])-hull[j][0]*(p[1]-hull[i][1])+p[1]*hull[i][0]-hull[i][1]*p[0]<0)
				fl=false;
		j++;
		}
	if (fl) 
		if (r=-1)
			r=i;
		else
			if (p.distance(hull[r])<p.distance(hull[i]))
				r=i;
	i++;
	}
	return r;
}

ConvexHull ConvexHull:: CreateNewConvexHull(TPoint p)
{
	if (IsPointInHull(p))
		return *this;
	else
	{
		int l=FindLeftSupportLine(p);
		int r=FindRightSupportLine(p);
		int knew; //������ ������ �������
		if (r<l) 
			knew=k-(r-l-1)+1;
		else knew=-(r-l-1)+1;
		TPoint *b;
		b=new TPoint[knew];
		if (r>l)
		{
			int i=0;
			for (i;i<=l; i++)
				b[i]=hull[i];
			b[i+1]=p;  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			for (int j=i+2, t=r; j<knew; j++,t++)
				b[j]=hull[t];
		}
		else //if (r<l) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		{
			int j=0;
			for (int i=r; i<=l; i++,j++)
				b[j]=hull[i];
			b[j+1]=p;  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		}
		delete[] hull;
		k=knew;
		new TPoint[k];
		for (int i=0; i<k; i++)
			hull[i]=b[i];
		delete[] b;
	}
	return *this; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!������� ����� �������� ��������. �����������
}