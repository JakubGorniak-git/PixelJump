#include "player.h"

Player::Player(float windowWidth, float windowHeight) : speed(200.0f) {
    shape.setSize(sf::Vector2f(50.0f, 100.0f));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(windowWidth / 2.0f, windowHeight / 2.0f);
}

void Player::handleInput(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        shape.move(-speed * deltaTime, 0.0f);
        shape.setFillColor(sf::Color::Blue);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        shape.move(speed * deltaTime, 0.0f);
        shape.setFillColor(sf::Color::Red);
    }
}

void Player::updatePosition(float windowWidth, float wallLeftX, float wallWidth) {
    float bottomX = 0.0f;
    float upperX = windowWidth - shape.getSize().x;
    float wallRightX = wallLeftX + wallWidth;

    if (shape.getPosition().x <= bottomX) {
        shape.setPosition(bottomX, shape.getPosition().y);
    }

    if (shape.getPosition().x >= upperX) {
        shape.setPosition(upperX, shape.getPosition().y);
    }

    if (shape.getPosition().x >= wallLeftX - shape.getSize().x) {
        shape.setPosition(wallLeftX - shape.getSize().x, shape.getPosition().y);
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::Vector2f Player::getPosition() const {
    return shape.getPosition();
}

sf::Vector2f Player::getSize() const {
    return shape.getSize();
}