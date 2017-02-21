#include "MyProject.h"
#include "PlayerCharacter.h"

int PlayerCharacter::GetActiveColor()
{
	return activeColor;
}

int PlayerCharacter::GetPower()
{
	return power;
}

void PlayerCharacter::Boost()
{
	power++;
}

void PlayerCharacter::ChangeActiveColor()
{
	activeColor = !activeColor;	
}
