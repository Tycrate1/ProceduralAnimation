#pragma once

#include <SFML/Graphics.hpp>

// Math operations to manipulate and constrain vectors
class VectorConstraint {
public:
	// Gets the direction of the vector
	sf::Vector2f NormalizeVector(float x, float y) const;
	// Pulls the tail to the anchor through vector constraint
	sf::Vector2f ConstrainDistance(sf::Vector2f anchor, sf::Vector2f tail, float constraintSeperation) const;
};