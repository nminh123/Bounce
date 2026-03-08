#include "../include/Random.hpp"
#include <random>

Random::Random() : m_Generator(m_Device()) {}

int Random::GenInt(int min, int max){
    return std::uniform_int_distribution(min, max)(m_Generator);
}

float Random::GenFloat(float min, float max){
    return std::uniform_real_distribution(min, max)(m_Generator);
}