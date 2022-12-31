#include "gtest/gtest.h"
#include "functions.h"
#include "ComplexNumbers.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestSth, TestSin) {
	EXPECT_EQ(Sin(PI), 0);
	EXPECT_EQ(Sin(0), 0);
	EXPECT_EQ(Sin(3* PI /2), -1);
	EXPECT_EQ(Sin(PI /2), 1);
}

TEST(TestTrigonometry, TestCos) {
	EXPECT_EQ(Sin(PI), 0);
	EXPECT_EQ(Sin(0), 0);
	EXPECT_EQ(Sin(3 * PI / 2), -1);
	EXPECT_EQ(Sin(PI / 2), 1);
}

TEST(TestTrigonometry2, TestTan) {
	EXPECT_EQ(tg(PI /4), 1);
	EXPECT_EQ(tg(-PI /4), -1);
	EXPECT_EQ(tg(0, 0);
	EXPECT_EQ(tg(PI, 0);
}

TEST(TestTrigonometry3, TestCtg) {
	EXPECT_EQ(ctg(PI/2), 0);
	EXPECT_EQ(ctg(3*PI/2), 0);
	EXPECT_EQ(ctg(PI/4), 1);
	EXPECT_EQ(ctg(-PI/4), -1);
}

TEST(TestTrigonometry4, TestSinH) {
	EXPECT_EQ(cosh(0), 1);
	EXPECT_EQ(sinh(0), 0);
	EXPECT_EQ(Acos(-1), PI);
	EXPECT_EQ(Acos(1), 0);
	EXPECT_EQ(Asin(0), 0);
	EXPECT_EQ(Asin(1), PI/2);
}

TEST(TestTrigonometry5, TestLnLogLg) {
	EXPECT_EQ(lnX(E), 1);
	EXPECT_EQ(lnX(1), 0);
	EXPECT_EQ(lgX(10), 1);
	EXPECT_EQ(lgX(1000), 3);
	EXPECT_EQ(lgX(1), 0);
	EXPECT_EQ(logX(8, 2), 3);
	EXPECT_EQ(logX(1, 2), 0);
	EXPECT_EQ(logX(16, 4), 2);
}

TEST(TestTrigonometry6, TestBorders) {
	EXPECT_EQ(lwb(123.23), 123);
	EXPECT_EQ(lwb(123.99999), 123);
	EXPECT_EQ(lwb(0.00001), 0);
	EXPECT_EQ(lwb(10), 10);
	EXPECT_EQ(upb(10.001), 11);
	EXPECT_EQ(upb(102.3132), 103);
	EXPECT_EQ(upb(-2.2), -2);
	EXPECT_EQ(lwb(-123.2), -124);
}

TEST(TestTrigonometry7, TestAbs) {
	EXPECT_EQ(Abs(5), 5);
	EXPECT_EQ(Abs(-5), 5);
	EXPECT_EQ(Abs(0), 0);
	EXPECT_EQ(Abs(5567), 5567);
}