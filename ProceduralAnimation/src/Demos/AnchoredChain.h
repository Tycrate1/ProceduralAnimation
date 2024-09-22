#pragma once

#include <vector>

#include "Ring.h"
#include "VectorConstraint.h"

// Demonstraints FABRIK constraining the chain to the start while finding the tails new position(mouse position)
class AnchoredChain : VectorConstraint {
public:
    int m_chainLength;
    float m_linkSeperation;
    std::vector<Ring> m_chainSegments;
private:
    // Pulls the chain toward the new position
    void backwardAction();
    // Pulls the chain back towards the start position
    void forwardAction();
public:
    AnchoredChain(int chainLength = 5, float linkDistance = 30.f);

    void transform(const sf::RenderWindow& window);

    void draw(sf::RenderWindow& window) const;
};