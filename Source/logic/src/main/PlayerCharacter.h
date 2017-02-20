#pragma once

class PlayerCharacter
{
private:
	int power[2] = {0,0};
	int activeColor = 0;
public:
	static const int PRIMARY_COLOR = 0;
	static const int SECUNDARY_COLOR = 1;
	int GetActiveColor();
	int GetPrimaryColorPower();
	int GetSecondaryColorPower();
	void Boost();
	void ChangeActiveColor();
};
