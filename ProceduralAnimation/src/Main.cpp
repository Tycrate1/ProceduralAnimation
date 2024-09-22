#include <SFML/Window.hpp>

#include "Demos/Chain.h"
#include "Demos/Boundary.h"
#include "Demos/AnchoredChain.h"

int main()
{
    // Creates sfml window
    sf::RenderWindow window(sf::VideoMode(500, 500), "Constraints");
    window.setVerticalSyncEnabled(true);

    // One of the demo objects
    AnchoredChain obj;

    // Window loop updating graphics continuously
    while (window.isOpen())
    {
        // Sfml events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Demo objects transformation ability
        obj.transform(window);

        // Clear and draw to the window
        window.clear(sf::Color::Black);
        obj.draw(window);
        window.display();
    }

    return 0;
}