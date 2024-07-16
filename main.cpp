#include <SFML/Graphics.hpp>
#include "player.h"

float WINDOW_WIDTH = 800.0f;
float WINDOW_HEIGHT = 600.0f;
sf::Vector2f WALL_SIZE(100.0f, 300.0f);

void render(sf::RenderWindow& window, Player& player, sf::RectangleShape& wall, sf::RectangleShape& wall_2, sf::Sprite& background) {
    window.clear();
    window.draw(background);
    window.draw(wall);
    window.draw(wall_2);
    player.draw(window);
    window.display();
}
//wiktor glupoty gada
int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "MyGame!");

    Player player(WINDOW_WIDTH, WINDOW_HEIGHT);

    sf::RectangleShape wall(WALL_SIZE);
    wall.setFillColor(sf::Color::White);
    wall.setPosition(700.0f, 300.0f);

    sf::RectangleShape wall_2(WALL_SIZE);
    wall_2.setFillColor(sf::Color::White);
    wall_2.setPosition(0.0f, 300.0f);

    sf::Texture texture;
    if (!texture.loadFromFile("background.png")) {
        return -1;
    }
    sf::Sprite background(texture);

    sf::Clock clock;

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        player.handleInput(deltaTime);
        player.updatePosition(WINDOW_WIDTH, 700.0f, WALL_SIZE.x);
        render(window, player, wall, wall_2, background);
    }

    return 0;
}