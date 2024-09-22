#include "VectorConstraint.h"

sf::Vector2f VectorConstraint::NormalizeVector(float x, float y) const {
    // Gets the magnitude of the vector through the pythagorean theorem
    float mag = std::sqrt((x * x) + (y * y));

    if (mag == 0)
        return sf::Vector2f(x, y);

    return sf::Vector2f(x / mag, y / mag);
}

sf::Vector2f VectorConstraint::ConstrainDistance(sf::Vector2f anchor, sf::Vector2f tail, float constraintSeperation) const {
    sf::Vector2f direction = tail - anchor;
    sf::Vector2f normalizedDirection = NormalizeVector(direction.x, direction.y);

    // Scales the normalized vector and shifts it back towards the anchor
    return (normalizedDirection * constraintSeperation) + anchor;
}