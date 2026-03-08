#pragma once

#include "Paddle.hpp"

class Ball {
private:
  sf::CircleShape m_Shape;
  sf::Vector2f m_Direction;
  float m_Speed;

public:
  Ball();

  void Draw(sf::RenderWindow &window) const;
  void Move(const float &delta_time);
  bool IsOutside() const;
  void Bounce();
  sf::FloatRect GetGlobalBounds() const;
  sf::Vector2f GetDirection() const;
};