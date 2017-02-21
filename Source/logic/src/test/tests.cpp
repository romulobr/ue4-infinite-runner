#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../../../MyProject/logic/PlayerCharacter.h"

using namespace testing;

class APlayerCharacter : public Test
{

	
};

TEST_F(APlayerCharacter, StartsWithColorOneAndNoPowerUps)
{	
	PlayerCharacter playerCharacter;
	ASSERT_THAT(playerCharacter.GetActiveColor(), Eq(PlayerCharacter::PRIMARY_COLOR));
	ASSERT_THAT(playerCharacter.GetPower(), Eq(0));
}

TEST_F(APlayerCharacter, ChangesActiveColor)
{
	PlayerCharacter playerCharacter;
	
	playerCharacter.ChangeActiveColor();
	ASSERT_THAT(playerCharacter.GetActiveColor(), Eq(PlayerCharacter::SECUNDARY_COLOR));
	
	playerCharacter.ChangeActiveColor();
	ASSERT_THAT(playerCharacter.GetActiveColor(), Eq(PlayerCharacter::PRIMARY_COLOR));
}

TEST_F(APlayerCharacter, BoostsActiveColorPower)
{
	PlayerCharacter playerCharacter;

	playerCharacter.Boost();	
	ASSERT_THAT(playerCharacter.GetPower(), Eq(1));

	playerCharacter.Boost();
	ASSERT_THAT(playerCharacter.GetPower(), Eq(2));

}


