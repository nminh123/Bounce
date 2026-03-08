#include "../include/Ball.hpp"

Ball::Ball() : m_Shape(10), m_Speed(250) {
  m_Shape.setFillColor(sf::Color::Cyan);
  m_Shape.setOrigin(m_Shape.getGeometricCenter());
  m_Shape.setPosition({600 * 0.50f, 800 * 0.25f});

  m_Direction = {1, sf::degrees(gRandom.GenFloat(0, 360))};
}

//===============================================================================================
void Ball::Draw(sf::RenderWindow &window) const { window.draw(m_Shape); }
//===============================================================================================
void Ball::Bounce() { m_Direction.y *= -1; }
//===============================================================================================
sf::Vector2f Ball::GetDirection() const { return m_Direction; }
//===============================================================================================
sf::FloatRect Ball::GetGlobalBounds() const {
  return m_Shape.getGlobalBounds();
}
//===============================================================================================
bool Ball::IsOutside() const {
  return m_Shape.getPosition().y - m_Shape.getRadius() > 800;
}

void Ball::Move(const float &delta_time) {
  sf::Vector2f last_position = m_Shape.getPosition();
  m_Shape.move(m_Direction * m_Speed * delta_time);
  if (m_Shape.getPosition().x < m_Shape.getRadius() ||
      m_Shape.getPosition().x >= 600 - m_Shape.getRadius()) {
    m_Shape.setPosition(last_position);
    m_Direction.x *= -1;
  }
  if (m_Shape.getPosition().y < m_Shape.getRadius()) {
    m_Shape.setPosition(last_position);
    m_Direction.y *= -1;
  }
}