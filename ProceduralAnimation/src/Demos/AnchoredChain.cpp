#include "AnchoredChain.h"

AnchoredChain::AnchoredChain(int chainLength, float linkDistance) : m_chainLength(chainLength), m_linkSeperation(linkDistance) {
    for (int i = 0; i < chainLength; i++) {
        m_chainSegments.push_back(Ring());
    }
}

void AnchoredChain::backwardAction() {
    // Starts on the second link because the first is the anchor(mouse position)
    for (int i = 1; i < m_chainLength; i++) {
        // Sets the segment to the constrained position reletive to the anchor
        m_chainSegments[i].ringObj.setPosition(ConstrainDistance(m_chainSegments[i - 1].ringObj.getPosition(), m_chainSegments[i].ringObj.getPosition(), m_linkSeperation));
    }
}

void AnchoredChain::forwardAction() {
    // Starts on the second to last link because the last is the start
    for (int i = m_chainLength - 2; i > -1; i--) {
        // Sets the segments to the constrained position reletive to the anchor
        m_chainSegments[i].ringObj.setPosition(ConstrainDistance(m_chainSegments[i + 1].ringObj.getPosition(), m_chainSegments[i].ringObj.getPosition(), m_linkSeperation));
    }
}

void AnchoredChain::transform(const sf::RenderWindow& window) {
    if (m_chainLength < 1) return;

    // Pulls the first link to the mouse pointer
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    m_chainSegments[0].ringObj.setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

    if (m_chainLength < 2) return;

    // Saves the start position
    sf::Vector2f start = m_chainSegments[m_chainLength - 1].ringObj.getPosition();

    // Moves the rest of the chain to the new position
    backwardAction();
    // Pulls the last link to the start position
    m_chainSegments[m_chainLength - 1].ringObj.setPosition(start);
    // Moves the rest of the chain back toward the start position
    forwardAction();
}

void AnchoredChain::draw(sf::RenderWindow& window) const {
    for (int i = 0; i < m_chainLength; i++) {
        window.draw(m_chainSegments[i].ringObj);
    }
}