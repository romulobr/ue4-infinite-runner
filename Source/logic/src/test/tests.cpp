#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../main/GameState.h"
#include "../main/PlayerCharacter.h"

using namespace testing;

class APlayerCharacter : public Test
{

	
};

TEST_F(APlayerCharacter, StartsWithColorOneAndNoPowerUps)
{	
	PlayerCharacter playerCharacter;
	ASSERT_THAT(playerCharacter.GetActiveColor(), Eq(PlayerCharacter::PRIMARY_COLOR));
	ASSERT_THAT(playerCharacter.GetPrimaryColorPower(), Eq(0));
	ASSERT_THAT(playerCharacter.GetSecondaryColorPower(), Eq(0));
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
	ASSERT_THAT(playerCharacter.GetPrimaryColorPower(), Eq(1));
	ASSERT_THAT(playerCharacter.GetSecondaryColorPower(), Eq(0));
	
	playerCharacter.Boost();
	ASSERT_THAT(playerCharacter.GetPrimaryColorPower(), Eq(2));
	ASSERT_THAT(playerCharacter.GetSecondaryColorPower(), Eq(0));	
}


