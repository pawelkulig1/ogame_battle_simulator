#include "random_number_generator.h"
#include <stdexcept>

RandomNumberGenerator* RandomNumberGenerator::m_random_generator = nullptr;

RandomNumberGenerator::RandomNumberGenerator()
{
    std::random_device rd;
    m_gen = std::mt19937(rd());
}

RandomNumberGenerator *RandomNumberGenerator::get_instance()
{
    if (m_random_generator == nullptr)
    {
        m_random_generator = new RandomNumberGenerator();
    }
    return m_random_generator;
}

RandomNumberGenerator::~RandomNumberGenerator()
{
    delete m_random_generator;
}

int RandomNumberGenerator::get_rand_int(int min, int max)
{
    if (min > max){
        throw(std::runtime_error(std::string(__FILE__) + std::to_string(__LINE__) + " min: " + std::to_string(min) + " max: " + std::to_string(max)));
    }
    if (min == max)
    {
        return min;
    }
    std::uniform_int_distribution<> dis(min, max - 1);
    return dis(m_gen);
}