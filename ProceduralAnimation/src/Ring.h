#pragma once

#include <SFML/Graphics.hpp>

// Creates sfml circle objects to form a ring
class Ring {
public:
	sf::CircleShape ringObj;
public:
	Ring(float radius = 10.f, float borderSize = 3.f, sf::Color color = sf::Color::White);
};