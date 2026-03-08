#include "../include/GameStats.hpp"

GameStats::GameStats()
    : m_Font("../../content/Roboto-VariableFont_wdth,wght.ttf"),
      m_ScoreText(m_Font), m_LivesText(m_Font), m_HighScoreText(m_Font) {
  m_ScoreText.setPosition({10, 10});
  m_ScoreText.setFillColor(sf::Color::Cyan);
  SetScore(0);

  m_LivesText.setPosition({10, 60});
  m_LivesText.setFillColor(sf::Color::Red);
  SetLives(10);

  m_HighScoreText.setPosition({10, 110});
  m_HighScoreText.setFillColor(sf::Color::Yellow);
  SetHighScore(0);
  if(std::ifstream file{"../../HighScore.txt"}){
    file >> m_HighScore;
  }
  else {
    std::cout << "Cannot find the file" << std::endl;
    m_HighScore = 0;
  }
  SetHighScore(m_HighScore);
}

void GameStats::Draw(sf::RenderWindow &window) {
  window.draw(m_ScoreText);
  window.draw(m_LivesText);
  window.draw(m_HighScoreText);
}

void GameStats::SetScore(int score) {
  m_Score = score;
  m_ScoreText.setString("Score: " + std::to_string(m_Score));
}

void GameStats::SetLives(int lives) {
  m_Lives = lives;
  m_LivesText.setString("Lives: " + std::to_string(m_Lives));
}

void GameStats::SetHighScore(int high_score) {
  m_HighScore = high_score;
  m_HighScoreText.setString("High Score: " + std::to_string(m_HighScore));
}

int GameStats::GetScore() const { return m_Score; }

int GameStats::GetLives() const { return m_Lives; }

int GameStats::GetHighScore() const { return m_HighScore; }

void GameStats::Reset() {
  if (m_Score > m_HighScore) {
    if(std::ofstream file{"../../HighScore.txt"}){
        file << m_Score;
    }
    SetHighScore(m_Score);
  }
  SetScore(0);
  SetLives(10);
}