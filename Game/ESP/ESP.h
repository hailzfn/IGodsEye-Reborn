#pragma once

#include "stdafx.h"
#include "Application.h"
#include "Game\Client\CharacterInfo\characterInfo_t.h"

class ESP
{
public:
	static void update();
private:
	static void draw(characterInfo_t* character, Vector2 position, Vector2 size, float distance);
	static void drawText(Vector2 position, Vector2 size, std::string name, float fontSize, float distance, ImColor colour);
	static void radar(Vector3 difference);
	static Vector2 size(float distance);
	static Vector3 adjustments(Vector3 position, CharacterStance localStance, CharacterStance playerStance);
	static ImColor getColour(float distance);
};
