#include "PlayerCharacter.h"

int PlayerCharacter::GetActiveColor()
{
	return activeColor;
}

int PlayerCharacter::GetPrimaryColorPower()
{
	return power[PRIMARY_COLOR];
}

int PlayerCharacter::GetSecondaryColorPower()
{
	return power[SECUNDARY_COLOR];
}

void PlayerCharacter::Boost()
{
	power[activeColor]++;
}

void PlayerCharacter::ChangeActiveColor()
{
	activeColor = !activeColor;	
}
