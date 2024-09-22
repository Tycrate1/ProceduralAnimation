#pragma once

#include <vector>

#include "Ring.h"
#include "VectorConstraint.h"

class Chain : VectorConstraint {
private:
    int m_chainLength;
    float m_linkSeperation;
    std::vector<Ring> m_chainSegments;
public:
    Chain(int chainLength = 5, float linkDistance = 30.f);

    void transform(const sf::RenderWindow& window);

    void draw(sf::RenderWindow& window) const;
};