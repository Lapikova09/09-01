#pragma once
#include <SFML/Graphics.hpp>
#include "Header.h"
bool pointInRect(sf::RectangleShape bat, sf::Vector2f point) {
    return bat.getPosition().x <= point.x &&
        point.x <= bat.getPosition().x + BAT_SIZE.x &&
        bat.getPosition().y <= point.y &&
        point.y <= bat.getPosition().y + BAT_SIZE.y;
}
struct Ball {
    sf::CircleShape shape;
    float speedX;
    float speedY;
};
void ballInit(Ball& ball) {
    ball.shape.setRadius(BALL_RADIUS);
    ball.shape.setFillColor(BALL_COLOR);
    ball.shape.setPosition(BALL_START_POS);
    ball.speedX = 2.f;
    ball.speedY = 3.f;
}

