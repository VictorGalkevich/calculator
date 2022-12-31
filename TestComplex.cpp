#include "gtest/gtest.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(testComplex1, Sum)
{
	ComplexNumber a1(1, 2);
	ComplexNumber a2(2, 5);
	ComplexNumber a3 = a1 + a2;
	EXPECT_EQ(a3.getRe(), 3);
	EXPECT_EQ(a3.getIm(), 7);
}

TEST(testComplex1, Subtraction)
{
	ComplexNumber a1(1, 2);
	ComplexNumber a2(2, 5);
	ComplexNumber a3 = a1 - a2;
	EXPECT_EQ(a3.getRe(), -1);
	EXPECT_EQ(a3.getIm(), -3);
}

TEST(testComplex1, division)
{
	ComplexNumber a1(1, 3);
	ComplexNumber a2(3, 4);
	ComplexNumber a3 = a1 + a2;
	EXPECT_EQ(a3.getRe(), 0.6);
	EXPECT_EQ(a3.getIm(), 0.2);
}

TEST(testComplex1, multilplication)
{
	ComplexNumber a1(1, 2);
	ComplexNumber a2(2, 5);
	ComplexNumber a3 = a1 * a2;
	EXPECT_EQ(a3.getRe(), -8);
	EXPECT_EQ(a3.getIm(), 9);
}

TEST(testComplex1, Equation)
{
	ComplexNumber a1(1, 2);
	ComplexNumber a2(2, 5);
	a1 = a2;
	EXPECT_EQ(a1.getRe(), 2);
	EXPECT_EQ(a1.getIm(), 5);
}
