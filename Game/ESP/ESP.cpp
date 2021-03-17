//ESP.cpp
#include "ESP.h"

void ESP::update()
{
	Graphics::beginScene();

	characterInfo_t* me = Application::game->client->getLocalCharacterInfo();

	// Entities
	//for (int i = 0; i < 0x800; i++)
	//{
	//	centity_s* entity = centity_s::get(i);

	//	if (!entity->isValid())
	//		continue;

	//	Vector3 origin = entity->getOrigin();
	//	if (origin.isZero())
	//		continue;

	//	Vector2 position = Math::worldToScreen(
	//		origin,
	//		me->pXAnimTree->origin,
	//		Application::game->refdef->displayViewport.width,
	//		Application::game->refdef->displayViewport.height,
	//		Application::game->refdef->view.tanHalfFov,
	//		Application::game->refdef->view.axis
	//	);

	//	Graphics::rectangle(position, Vector2(20, 20));
	//}

	// Players
	for (int i = 0; i < 155; i++)
	{
		characterInfo_t* character = Application::game->client->getCharacterInfo(i);

		// Skip invalid characters
		if (!character->isValid())
			continue;

		// Skip invalid entities
		// std::cout << "Player " << i << " Valid: " << character->getEntity()->infoValid << " Type: " << character->getEntity()->type << " Dead: " << character->getEntity()->isDead() << std::endl;
		// if (!character->getEntity()->isValid())
			// continue;

		// Skip dead entities
		// if (!character->getEntity()->isDead())
			// continue;

		// Skip me
		if (me->entityNum == character->entityNum)
			continue;

		// Draw on radar
		ESP::radar(character->pXAnimTree->origin - me->pXAnimTree->origin);

		// Get the distance from the character
		float distance = me->pXAnimTree->origin.distance(character->pXAnimTree->origin);

		// Ignore anyone over 20000.0f away
		if (distance > 20000.0f)
			continue;

		//// Ignore my team
		//// if (me.team == character.team)
		//	// continue;

        // Get the players adjusted location
		Vector3 location = ESP::adjustments(
			character->pXAnimTree->origin,
			me->stance,
			character->stance
		);

		// Get the screen position from world origin
		Vector2 position = Math::worldToScreen(
			location,
			me->pXAnimTree->origin,
			Application::game->refdef->displayViewport.width,
			Application::game->refdef->displayViewport.height,
			Application::game->refdef->view.tanHalfFov,
			Application::game->refdef->view.axis
		);

		// Get the screen rectangle size
		Vector2 size = ESP::size(distance);

		// Move position by half size to center
		position.x -= (size.x / 2);
		position.y -= (size.y / 2);

		// Draw
		ESP::draw(character, position, size, distance);
	}
	
	Graphics::endScene();
}

void ESP::draw(characterInfo_t* character, Vector2 position, Vector2 size, float distance)
{
	// Ignore if off screen
	if (position.x < 0 || position.y < 0 || (position.x + size.x > Application::game->refdef->displayViewport.width) || (position.y + size.y > Application::game->refdef->displayViewport.height))
		return;

	// Draw background
	Graphics::rectangleFilled(position, size, { 0, 0, 0, 100 });

	// Get the colour based off the distance
	ImColor colour = ESP::getColour(distance);

	// Corner Size
	float cornerSize = size.x / 4;

	// Draw name
	if (distance < 2000.0f)
		ESP::drawText(position, size, character->getName(), cornerSize, distance, colour);

	// Draw corners
	
	// Top Left
	Graphics::line(position, Vector2(position.x + cornerSize, position.y), colour);
	Graphics::line(position, Vector2(position.x, position.y + cornerSize), colour);

	// Top Right
	Graphics::line(Vector2(position.x + size.x - cornerSize, position.y), Vector2(position.x + size.x, position.y), colour);
	Graphics::line(Vector2(position.x + size.x, position.y), Vector2(position.x + size.x, position.y + cornerSize), colour);

	// Bottom Left
	Graphics::line(Vector2(position.x, position.y + size.y), Vector2(position.x + cornerSize, position.y + size.y), colour);
	Graphics::line(Vector2(position.x, position.y + size.y - cornerSize), Vector2(position.x, position.y + size.y), colour);

	// Bottom Right
	Graphics::line(Vector2(position.x + size.x - cornerSize, position.y + size.y), Vector2(position.x + size.x, position.y + size.y), colour);
	Graphics::line(Vector2(position.x + size.x, position.y + size.y - cornerSize), Vector2(position.x + size.x, position.y + size.y), colour);
}

void ESP::drawText(Vector2 position, Vector2 size, std::string name, float fontSize, float distance, ImColor colour)
{
	// Limit size
	if (fontSize > 32.0f)
		fontSize = 32.0f;

	std::string message = name + "[" + std::to_string((int)distance) + "]";

	Vector2 textSize = Graphics::measureText(message, fontSize);
	position.x += (size.x / 2.0f) - (textSize.x / 2.0f);
	position.y -= textSize.y;

	Graphics::text(position, message, colour, fontSize);
}

void ESP::radar(Vector3 difference)
{
	//float center = 209.0f;
	//float scale = 0.035714f;
	//float size = 360;

	//float yaw = -atan2(refdef.vViewAxis[1].x, refdef.vViewAxis[0].x) - M_PI / 2;
	//float x = center + (difference.length() * scale) * cos(yaw - atan2(difference.y, difference.x));
	//float y = center + (difference.length() * scale) * sin(yaw - atan2(difference.y, difference.x));

	//if (x > center - size / 2 && x < center + size / 2 &&
	//	y > center - size / 2 && y < center + size / 2) {

	//	// Print triangle that points where the enemy is aiming (relative to local)
	//	/*auto enemy_pointing = RAD2DEG(-ents[i].rotation.y) - yaw;
	//	DrawTriangle(
	//		enemy_x + 10 * cos(enemy_pointing), enemy_y + 10 * sin(enemy_pointing),
	//		enemy_x + 10 * cos(enemy_pointing - DEG2RAD(150)), enemy_y + 10 * sin(enemy_pointing - DEG2RAD(150)),
	//		enemy_x + 10 * cos(enemy_pointing + DEG2RAD(150)), enemy_y + 10 * sin(enemy_pointing + DEG2RAD(150)),
	//		0xFFFF0000, 0xFFFF0000, 0xFFFF0000);*/
	//	Graphics::circle(x, y, );
	//	DrawFilledCircle(enemy_x, enemy_y, 6, 36, 0xFFFF0000);
	//}
}

Vector2 ESP::size(float distance)
{
	// As the distance increases, the size of width and height decreases
	// This is "Inverse proportion"
	// C = k / D
	// C = Width or Height
	// D = Distance
	// k = C * D

	// At a distance of 272, width is 140 and height is 280
	float pDistance = 272.0f;
	float pWidth = 140.0f;
	float pHeight = 280.0f;

	float kWidth = pDistance * pWidth; // 272 * 140
	float kHeight = pDistance * pHeight; // 272 * 280

	return Vector2(kWidth / distance, kHeight / distance);
}

Vector3 ESP::adjustments(Vector3 position, CharacterStance localStance, CharacterStance playerStance)
{
	position.z -= 25.0f;

	switch (playerStance)
	{
	case CharacterStance::Crouching:
		position.z -= 9.0f;
		break;
	case CharacterStance::Crawling:
	case CharacterStance::Downed:
		position.z -= 22.0f;
		break;
	}

	switch (localStance)
	{
	case CharacterStance::Crouching:
		position.z += 17.5f;
		break;
	case CharacterStance::Crawling:
	case CharacterStance::Downed:
		position.z += 45.0f;
		break;
	}

	return position;
}

ImColor ESP::getColour(float distance)
{
	// Apply limits
	float max = 5000.0f;
	float min = 600.0f;
	if (distance > max)
		distance = max;
	else if (distance < min)
		distance = min;

	distance -= min;

	int green = (int)(distance * (255 / (max - min)));
	return { 255, green, 0, 255 };
}
