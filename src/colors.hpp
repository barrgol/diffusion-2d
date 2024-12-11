#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

namespace Gradient
{
	sf::Color RED_BLUE(float val) {
		return {
			(sf::Uint8)(-(val - 1) / 2.0f * 255),
			0,
			(sf::Uint8)((val + 1) / 2.0f * 255)
		};
	}

	sf::Color GREEN_BLUE(float val) {
		return {
			0,
			(sf::Uint8)(-(val - 1) / 2.0f * 255),
			(sf::Uint8)((val + 1) / 2.0f * 255)
		};
	}

	sf::Color BLACK_WHITE(float val) {
		return {
			(sf::Uint8)((val + 1) / 2.0f * 255),
			(sf::Uint8)((val + 1) / 2.0f * 255),
			(sf::Uint8)((val + 1) / 2.0f * 255)
		};
	}

	std::function<sf::Color(float)> CUSTOM(sf::Color min, sf::Color max, float vmin, float vmax) {
		return [min, max, vmin, vmax](float val) {
			// Normalize the input between 0 and 1
			double t = (val - vmin) / (vmax - vmin);

			// Clamp t to the range [0, 1]
			t = std::max(0.0, std::min(1.0, t));

			// Linearly interpolate each channel
			sf::Uint8 r = static_cast<sf::Uint8>(min.r + t * (max.r - min.r));
			sf::Uint8 g = static_cast<sf::Uint8>(min.g + t * (max.g - min.g));
			sf::Uint8 b = static_cast<sf::Uint8>(min.b + t * (max.b - min.b));
			sf::Uint8 a = static_cast<sf::Uint8>(min.a + t * (max.a - min.a));

			return sf::Color(r,g,b,a);
		};
	}
}