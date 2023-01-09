#include <SFML/Graphics.hpp>
#include "Header.h"
#include "functions.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
    WINDOW_TITLE,
    Style::Titlebar|Style::Close);
    window.setFramerateLimit(FPS);

    RectangleShape Bat;
    Bat.setSize(BAT_SIZE);
    Bat.setFillColor(BAT_COLOR);
    Bat.setPosition(BAT_OFFSET_X, BAT_OFFSET_Y);

    Ball ball;
    ballInit(ball);

    Font font;
    font.loadFromFile("DS-DIGIB.ttf");
    int Score = 0;
    Text text;
    text.setString(std::to_string(Score));
    text.setFont(font);
    text.setCharacterSize(FONT_SIZE);
    text.setPosition(TEXT_POS);
    Text finish;
    finish.setString(end);
    finish.setFont(font);
    finish.setCharacterSize(FONT_SIZE);
    finish.setPosition(END_TEXT_POS);


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        ball.shape.move(ball.speedX, ball.speedY);
        if (ball.shape.getPosition().x <= 0)
        {
            ball.speedX = -ball.speedX;
        }
        if (ball.shape.getPosition().x + 2 * BALL_RADIUS >= WINDOW_WIDTH) {
            ball.speedX = -ball.speedX;
        }
        if (
            ball.shape.getPosition().y + 2 * BALL_RADIUS >= WINDOW_HEIGHT)
        {
            ball.speedY = -ball.speedY;
            Score++;
            text.setString(std::to_string(Score));
        }
        if (ball.shape.getPosition().y <= 0) {
            ball.speedY = -ball.speedY;
        }
      
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            Bat.move(-BAT_DY,0.f);
        }
        else if (Keyboard::isKeyPressed(Keyboard::D)) {
            Bat.move(BAT_DY,0.f);
        }
        if (Bat.getPosition().x < 0) {
            Bat.setPosition(Vector2f( 0.f, BAT_OFFSET_Y));
        }
        if (Bat.getPosition().x > WINDOW_WIDTH - BAT_WIDTH) {
            Bat.setPosition(Vector2f(WINDOW_WIDTH - BAT_WIDTH, BAT_OFFSET_Y));
        }

        if (Score == 5) {
            ball.speedX = 0.f;
            ball.speedY = 0.f;
            ball.shape.setPosition(BALL_END_POS);
            window.clear();
            window.draw(finish);
            window.display();
        }
        Vector2f left{ ball.shape.getPosition().x + 2 * BALL_RADIUS,ball.shape.getPosition().y};
        Vector2f mid{ ball.shape.getPosition().x + BALL_RADIUS,ball.shape.getPosition().y};//?
        Vector2f right{ ball.shape.getPosition().x,ball.shape.getPosition().y +2*BALL_RADIUS};
        Vector2f midleft{ ball.shape.getPosition().x + 2 * BALL_RADIUS,ball.shape.getPosition().y + BALL_RADIUS };
        Vector2f midright{ ball.shape.getPosition().x,ball.shape.getPosition().y + BALL_RADIUS };
        Vector2f bottomleft{ ball.shape.getPosition().x + 2 * BALL_RADIUS,ball.shape.getPosition().y + 2 * BALL_RADIUS };
        Vector2f bottomright{ ball.shape.getPosition().x,ball.shape.getPosition().y + 2 * BALL_RADIUS };

        if (pointInRect(Bat, mid) && pointInRect(Bat, left) ||
            pointInRect(Bat, mid) && pointInRect(Bat, right)) {
            ball.speedY = -ball.speedY;
            ball.speedX = -ball.speedX;
        }
        if (pointInRect(Bat, right) && pointInRect(Bat, midright) ||
            pointInRect(Bat, bottomright) && pointInRect(Bat, midright)) {
            ball.speedX = -ball.speedX;
        }
        if (pointInRect(Bat, midleft) && pointInRect(Bat, left) ||
            pointInRect(Bat, midleft) && pointInRect(Bat, bottomleft)) {
            ball.speedX = -ball.speedX;
        }
        if(pointInRect(Bat, left) || pointInRect(Bat, right)) {
            ball.speedY = -ball.speedY;
        }

        window.clear();
        window.draw(Bat);
        window.draw(ball.shape);
        window.draw(text);
        window.display();
    }
    return 0;
}