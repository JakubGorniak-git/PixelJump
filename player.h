#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(float windowWidth, float windowHeight);
    void handleInput(float deltaTime);
    void updatePosition(float windowWidth, float wallLeftX, float wallWidth, float deltaTime);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;

private:
    sf::RectangleShape shape;
    float speed;
    float jumpVelocity;
    float gravity;
    bool isJumping;
    bool isOnGround;
};

#endif // PLAYER_H