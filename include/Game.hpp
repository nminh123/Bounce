#pragma once

#include "GameStats.hpp"

class Game {
private:
  Paddle m_Paddle;
  std::vector<Ball> m_BallVector;
  sf::RenderWindow m_Window;
  GameStats m_Stats;
  sf::Clock m_Clock;
  sf::Clock m_BallSpawnClock;
  float m_DeltaTime;

public:
  Game();
  bool IsRunning() const;

  void ProcessEvent();
  void Update();
  void Render();
  void Restart();

  void HandleEvent(const auto &) {}
  void HandleEvent(const sf::Event::Closed &close);
  void HandleCollisions();
};