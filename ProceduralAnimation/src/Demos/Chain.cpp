#include "Chain.h"

Chain::Chain(int chainLength, float linkDistance) : m_chainLength(chainLength), m_linkSeperation(linkDistance) {
    for (int i = 0; i < chainLength; i++) {
        m_chainSegments.push_back(Ring());
    }
}

void Chain::transform(const sf::RenderWindow& window) {
    if (m_chainLength < 1) return;

    // Sets the first link to the mouse position
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    m_chainSegments[0].ringObj.setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

    if (m_chainLength < 2) return;

    // Starts on the second link because the first is the anchor(mouse position)
    for (int i = 1; i < m_chainLength; i++) {
        // Sets the segment to the constrained position reletive to the anchor
        m_chainSegments[i].ringObj.setPosition(ConstrainDistance(m_chainSegments[i - 1].ringObj.getPosition(), m_chainSegments[i].ringObj.getPosition(), m_linkSeperation));
    }
}

void Chain::draw(sf::RenderWindow& window) const {
    for (int i = 0; i < m_chainLength; i++) {
        window.draw(m_chainSegments[i].ringObj);
    }
}