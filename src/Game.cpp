#include "../include/Game.hpp"

Game::Game() : m_Window(sf::VideoMode({600, 800}), "Bounce Game") {
  m_Window.setFramerateLimit(60);
}

bool Game::IsRunning() const { return m_Window.isOpen(); }

void Game::ProcessEvent() {
  while (const auto event = m_Window.pollEvent()) {
    event->visit([&](const auto &event) { this->HandleEvent(event); });
  }
}

void Game::Update() {
  if (m_BallSpawnClock.getElapsedTime().asSeconds() > 2) {
    m_BallVector.emplace_back();
    m_BallSpawnClock.restart();
  }
  m_DeltaTime = m_Clock.restart().asSeconds();
  m_Paddle.Move(m_DeltaTime);
  for (auto &ball : m_BallVector) {
    ball.Move(m_DeltaTime);
  }
  if (m_Stats.GetLives() <= 0) {
    Restart();
  }
  HandleCollisions();
}

void Game::Render() {
  m_Window.clear();
  m_Paddle.Draw(m_Window);
  m_Stats.Draw(m_Window);
  for (auto &ball : m_BallVector) {
    ball.Draw(m_Window);
  }
  m_Window.display();
}

void Game::Restart() {
  m_BallVector.clear();
  m_BallSpawnClock.restart();
  m_Stats.Reset();
}

void Game::HandleEvent(const sf::Event::Closed &close) {
  m_Window.close();
  std::cout << "Game Closed" << std::endl;
}

void Game::HandleCollisions() {
  sf::FloatRect paddle_bounds = m_Paddle.GetGlobalBounds();

  for (auto &ball : m_BallVector) {
    sf::FloatRect ball_bounds = ball.GetGlobalBounds();
    bool is_colliding = ball_bounds.findIntersection(paddle_bounds).has_value();
    if (is_colliding && ball.GetDirection().y > 0) {
      ball.Bounce();
      m_Stats.SetScore(m_Stats.GetScore() + 1);
    }
  }
  int ball_missed = (int)std::erase_if(
      m_BallVector, [](const Ball &ball) { return ball.IsOutside(); });
  if (ball_missed > 0) {
    m_Stats.SetLives(m_Stats.GetLives() - ball_missed);
  }
}