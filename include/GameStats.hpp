#pragma once

#include "Ball.hpp"

class GameStats {
private:
  sf::Font m_Font;

  sf::Text m_ScoreText;
  sf::Text m_LivesText;
  sf::Text m_HighScoreText;

  int m_Score, m_Lives, m_HighScore;

public:
  GameStats();
  void Draw(sf::RenderWindow &window);
  void SetScore(int score);
  void SetLives(int lives);
  void SetHighScore(int high_score);

  int GetScore() const;
  int GetLives() const;
  int GetHighScore() const;

  void Reset();
};