#include "Boundary.h"

Boundary::Boundary(float boundsDistance) : m_bounds(boundsDistance, 1.f, sf::Color::Red) {}

void Boundary::transform(const sf::RenderWindow& window) {
    // Sets anchor and boundary visual to the mouse position
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    m_anchor.ringObj.setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
    m_bounds.ringObj.setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

    // Sets the ring to the constrained position reletive to the anchor
    m_ring.ringObj.setPosition(ConstrainDistance(m_anchor.ringObj.getPosition(), m_ring.ringObj.getPosition(), m_bounds.ringObj.getRadius()));
}

void Boundary::draw(sf::RenderWindow& window) const {
    window.draw(m_anchor.ringObj);
    window.draw(m_bounds.ringObj);
    window.draw(m_ring.ringObj);
}