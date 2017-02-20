#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../main/app.cpp"

TEST(MyClassTest, JustFails) {
	MyClass myObject;
	EXPECT_EQ(myObject.aMethod(), 10);
}
