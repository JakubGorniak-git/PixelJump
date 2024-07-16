#include <SFML/Graphics.hpp>
using namespace sf;

float PLAYER_SPEED = 200.0f;
Vector2f PLAYER_SIZE(50.0f, 100.0f);
Vector2f WALL_SIZE(100.0f, 300.0f);
float WINDOW_WIDTH = 800.0f;
float WINDOW_HEIGHT = 600.0f;

void handleInput(RectangleShape& player, float deltaTime) {
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        player.move(-PLAYER_SPEED * deltaTime, 0.0f);
        player.setFillColor(Color::Blue);
    } else if (Keyboard::isKeyPressed(Keyboard::Right)) {
        player.move(PLAYER_SPEED * deltaTime, 0.0f);
        player.setFillColor(Color::Red);
    }
}

void jumpPlayer(RectangleShape& player, float deltaTime){
    bool jump = false;
    float gravity = 200.0f;
    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        jump = true;
        player.setFillColor(Color::Blue);
    }
    if (jump){
        float current_Y = player.getPosition().y;
        player.move(0.0f, -500.0f * deltaTime);
        while (player.getPosition().y != current_Y){
            player.move(0.0f, 100.0f);
        }


    }
}
void updatePlayerPosition(RectangleShape& player) {
    float BOTTOM_X = 0.0f;
    float UPPER_X = WINDOW_WIDTH - PLAYER_SIZE.x;
    float WALL_LEFT_X = 700.0f;
    float WALL_RIGHT_X = 700.0f + WALL_SIZE.x;

    if (player.getPosition().x <= BOTTOM_X) {
        player.setPosition(BOTTOM_X, player.getPosition().y);
    }

    if (player.getPosition().x >= UPPER_X) {
        player.setPosition(UPPER_X, player.getPosition().y);
    }

    if (player.getPosition().x >= WALL_LEFT_X - PLAYER_SIZE.x) {
        player.setPosition(WALL_LEFT_X - PLAYER_SIZE.x, player.getPosition().y);
    }
}

void render(RenderWindow& window, RectangleShape& player, RectangleShape& wall, RectangleShape& wall_2, Sprite& background) {
    window.clear();
    window.draw(background); // Draw the background first
    window.draw(wall);
    window.draw(wall_2);
    window.draw(player);
    window.display();
}

int main() {
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "MyGame!");

    RectangleShape player(PLAYER_SIZE);
    player.setFillColor(Color::Green);
    player.setPosition(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f);

    RectangleShape wall(WALL_SIZE);
    wall.setFillColor(Color::White);
    wall.setPosition(700.0f, 300.0f);

    RectangleShape wall_2(WALL_SIZE);
    wall_2.setFillColor(Color::White);
    wall_2.setPosition(0.0f, 300.0f);

    // Load background texture
    Texture texture;
    if (!texture.loadFromFile("background.png")) {
        return -1; // Failed to load texture
    }
    Sprite background(texture);

    Clock clock;

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }

        handleInput(player, deltaTime);
        updatePlayerPosition(player);
        jumpPlayer(player, deltaTime);
        render(window, player, wall, wall_2, background);
    }

    return 0;
}