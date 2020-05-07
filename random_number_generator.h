#pragma once
#include <random>

class RandomNumberGenerator 
{
    static RandomNumberGenerator* m_random_generator;
    RandomNumberGenerator();
    std::mt19937 m_gen;
public:
    static RandomNumberGenerator* get_instance();
    int get_rand_int(int min, int max);
    ~RandomNumberGenerator();
};