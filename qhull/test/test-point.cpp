#include "../qhull/tpoint.h"
#include "gtest/gtest.h"

TEST(Point,can_create_point)
{
	TPoint A(1,-2);
	
	EXPECT_EQ(1, A.X);
	EXPECT_EQ(-2, A.Y);

}

	
TEST(TPoint,can_check_point)
{
	TPoint A(1,1);
	TPoint B(-1,-1);
	TPoint C(-3,-3);

	EXPECT_EQ(0, A.CheckPoint(A, B, C) );

	TPoint D(0.7, 0.2);
	TPoint F(0.1, 0.5);

	EXPECT_NE(0, A.CheckPoint(A,D,C));

	EXPECT_NE(0, A.CheckPoint(A,F,C));
}

