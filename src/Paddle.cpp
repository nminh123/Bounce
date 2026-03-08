#include "../include/Paddle.hpp"

Paddle::Paddle() : m_Shape({120, 20}), speed(750) {
  m_Shape.setFillColor(sf::Color::Green);
  m_Shape.setOrigin(m_Shape.getGeometricCenter());
  m_Shape.setPosition({600 * .50f, 800 * .85f});
}

void Paddle::Draw(sf::RenderWindow &window) const { window.draw(m_Shape); }
sf::FloatRect Paddle::GetGlobalBounds() const {
  return m_Shape.getGlobalBounds();
}

void Paddle::Move(const float &delta_time) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
    m_Shape.move(sf::Vector2f({-1, 0}) * speed * delta_time);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
    m_Shape.move(sf::Vector2f({1, 0}) * speed * delta_time);
  }

  float half_width = m_Shape.getSize().x / 2;
  float x = std::clamp(m_Shape.getPosition().x, half_width, 600 - half_width);
  m_Shape.setPosition({x, m_Shape.getPosition().y});
}