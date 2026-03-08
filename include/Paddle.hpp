#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numbers>
#include <string>
#include <vector>
#include <fstream>

#include "../include/Random.hpp"

class Paddle {
private:
  sf::RectangleShape m_Shape;
  float speed;

public:
  Paddle();
  void Draw(sf::RenderWindow &window) const;
  void Move(const float &delta_time);
  sf::FloatRect GetGlobalBounds() const;
};