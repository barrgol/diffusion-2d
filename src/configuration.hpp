#pragma once

namespace conf
{
	// Window configuration
	sf::Vector2u const WINDOW_SIZE = { 1200u, 1200u };
	sf::Vector2f const WINDOW_SIZE_F = static_cast<sf::Vector2f>(WINDOW_SIZE);
	uint32_t const MAX_FRAMERATE = 60;
	float const DT = 1.0f / static_cast<float>(MAX_FRAMERATE);
	const int SIZE = 200;
	const float OMEGA = 1.0f;
	const float EPSILON = 1.0e-5;
}