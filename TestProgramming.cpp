#include "gtest/gtest.h"
#include "programming_operations.h"

TEST(TestCaseName, TestHex) {
  EXPECT_EQ(hex(100), "64");
  EXPECT_EQ(hex(23), "17");
  EXPECT_EQ(hex(1), "1");
  EXPECT_EQ(hex(2), "2");
  EXPECT_EQ(hex(3), "3");
  EXPECT_EQ(hex(2333), "91D");
  EXPECT_EQ(hex(12), "C");
  EXPECT_EQ(hex(123123), "1E0F3");
  EXPECT_EQ(hex(6341), "18C5");
  EXPECT_EQ(hex(23), "17");

}

TEST(TestCaseName, TestName) {
	EXPECT_EQ(bin(23), "10111");
	EXPECT_EQ(bin(10), "1010");
	EXPECT_EQ(bin(2), "10");
	EXPECT_EQ(bin(3), "11");
	EXPECT_EQ(bin(1233), "10011010001");
	EXPECT_EQ(bin(166), "10100110");
	EXPECT_EQ(bin(666), "1010011010");
}

TEST(TestCaseName, TestName) {
	EXPECT_EQ(oct(100), "144");
	EXPECT_EQ(oct(123123), "360363");
	EXPECT_EQ(oct(34), "42");
	EXPECT_EQ(oct(1), "1");
	EXPECT_EQ(oct(2), "2");
	EXPECT_EQ(oct(3), "3");
	EXPECT_EQ(oct(341234), "1232362");
	EXPECT_EQ(oct(0), "0");
	EXPECT_EQ(oct(9), "11");
}
