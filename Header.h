#pragma once 
#include <string> 
const float WINDOW_WIDTH{ 800.f };
const float WINDOW_HEIGHT{ 600.f };
const std::string WINDOW_TITLE{ "SFML Mini Arcanoid" };
const unsigned int FPS{ 60 };
const float BAT_WIDTH{ 100.f };
const float BAT_HEIGHT{ 30.f };
const sf::Vector2f BAT_SIZE{ 100.f, 30.f };
const float BAT_OFFSET_X{ 350.f };
const float BAT_OFFSET_Y{ 550.f };
const sf::Color BAT_COLOR{ 18, 218, 12 };
const float BAT_DY = 5.f;
const float BALL_RADIUS = 15.f;
const sf::Color BALL_COLOR{ 250, 208, 0 };
const unsigned int FONT_SIZE = 64;
const sf::Vector2f TEXT_POS{ 390.f,10.f };
const sf::Vector2f END_TEXT_POS{ 300.f, 100.f };
const std::string end{ "GAME OVER" };
const sf::Vector2f BALL_START_POS{ (WINDOW_WIDTH - 2 * BALL_RADIUS) / 2,(WINDOW_HEIGHT - 2 * BALL_RADIUS) / 2 };
const sf::Vector2f BALL_END_POS{ 10.f,10.f };