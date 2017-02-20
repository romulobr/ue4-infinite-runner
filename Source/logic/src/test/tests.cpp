#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../main/GameState.h"

TEST(MyClassTest, JustFails) {
	GameState myObject;
	EXPECT_EQ(myObject.aMethod(), 10);
}
