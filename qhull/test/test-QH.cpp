#include "../qhull/qh.h"
#include "gtest/gtest.h"


TEST(ConvexHull,can_create_convexhull)
{
	TPoint B(4,6);
	SetPoints s(1);
	s[0] = B;
	ConvexHull h(s);

	EXPECT_EQ(B, h[0]);
	
}

TEST(ConvexHull,find_the_right_point)
{
	TPoint A(2,2);
	TPoint B(4,6);
    TPoint C(3,4);
	TPoint D(1,1);
    TPoint F(7,9);

	SetPoints s(5);

	s[0] = A;
	s[1] = B;
	s[2] = C;
	s[3] = D;
	s[4] = F;

	ConvexHull h(s);

	TPoint temp(0,0);
	temp = h.right();

	EXPECT_EQ (h[4][0],temp[0]);
	EXPECT_EQ (h[4][1],temp[1]);
}
	
TEST(ConvexHull,find_the_left_point)
{
	TPoint A(2,2);
	TPoint B(4,6);
    TPoint C(3,4);
	TPoint D(1,1);
    TPoint F(7,9);

	SetPoints s(5);

	s[0] = A;
	s[1] = B;
	s[2] = C;
	s[3] = D;
	s[4] = F;

	ConvexHull h(s);

	TPoint temp(0,0);
	temp = h.right();

	EXPECT_EQ (h[4][0],temp[0]);
	EXPECT_EQ (h[4][1],temp[1]);
}

TEST(ConvexHull_can_find_remote_point)
{
	TPoint A(2,2);
	TPoint B(4,6);
    TPoint C(3,4);
	TPoint D(1,1);
    TPoint F(7,9);

	TPoint temp(0,0);

	SetPoints s(5);

	s[0] = A;
	s[1] = B;
	s[2] = C;
	s[3] = D;
	s[4] = F;

	ConvexHull h(s);
	temp = h.remote(A,D,h);

	EXPECT_EQ (h[4][0],temp[0]);
	EXPECT_EQ (h[4][1],temp[1]);
}



TEST(ConvexHull,can_split)
{
	TPoint A(2,2);
	TPoint B(4,6);
    TPoint C(3,4);
	TPoint D(1,1);
    TPoint F(7,9);

	TPoint temp(0,0);

	SetPoints s(5);

	s[0] = A;
	s[1] = B;
	s[2] = C;
	s[3] = D;
	s[4] = F;

	ConvexHull h(s);
	
	SetPoints above(5);
	SetPoints bellow(5);

	h.Split (A,B,above,bellow);

	EXPECT_EQ (A.X, above[0][0]);
	EXPECT_EQ (A.Y, above[0][1]);
	EXPECT_EQ (B, above[1]);
	EXPECT_EQ (C, above[2]) ;
	EXPECT_EQ (D,bellow[3]);
	EXPECT_EQ (F, above[4] );
}
