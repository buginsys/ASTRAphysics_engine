#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Physics Engine");

    float posY = 50.f;
    float velocityY = 0.f;
    float gravity = 500.f;
    float radius = 50.f;
    float groundY = 600.f - (radius * 2); // ground level accounting for circle size

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        velocityY += gravity * deltaTime;
        posY += velocityY * deltaTime;

        // Collision with ground
        if (posY > groundY) {
            posY = groundY;
            velocityY = 0.f;
        }

        window.clear();
        sf::CircleShape circle(radius);
        circle.setPosition(375, posY);
        circle.setFillColor(sf::Color::Green);
        window.draw(circle);
        window.display();
    }

    return 0;
}