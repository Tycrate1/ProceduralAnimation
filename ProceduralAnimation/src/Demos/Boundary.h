#pragma once

#include "Ring.h"
#include "VectorConstraint.h"

class Boundary : VectorConstraint {
private:
    Ring m_anchor;
    Ring m_bounds;
    Ring m_ring;
public:
    Boundary(float boundsDistance = 50.f);

    void transform(const sf::RenderWindow& window);

    void draw(sf::RenderWindow& window) const;
};