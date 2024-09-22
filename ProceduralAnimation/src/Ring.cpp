#include "Ring.h"

Ring::Ring(float radius, float borderSize, sf::Color color) {
    ringObj.setRadius(radius);
    ringObj.setFillColor(sf::Color::Transparent);

    ringObj.setOutlineThickness(-borderSize);
    ringObj.setOutlineColor(color);

    // Sets the origin to the center of the object(default: top left)
    ringObj.setOrigin(radius - borderSize / 2, radius - borderSize / 2);
    // FIX, for now sets the position to 250, 250, which is the center of the screen on creation
    ringObj.setPosition(250, 250);
}