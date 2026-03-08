#pragma once

#include <random>

class Random{
private:
    std::random_device m_Device;
    std::mt19937 m_Generator;
public:
    Random();

    int GenInt(int min, int max);
    float GenFloat(float min, float max);
};

inline Random gRandom;