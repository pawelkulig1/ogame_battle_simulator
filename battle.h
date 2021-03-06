#ifndef __BATTLE__H__
#define __BATTLE__H__
#include <vector>
#include "static_structure.h"
#include "structure.h"

class Battle
{
    std::vector<Structure> attacking;
    std::vector<Structure> defending;

    int att_count_left[25];
    int def_count_left[25];
    int distance;

    const int MAX_ROUNDS = 6;

public:
    enum Player
    {
        DEFENDER = 0,
        ATTACKER = 1
    };

    Battle();
    void add_structure(Battle::Player player, Structure structure, int amount);
    void simulate( int iterations);
    void count(std::vector<Structure> fleet, int fleet_count[25]);
    void distance_calc(int galaxy, int system, int planet);
    resources profit(int* left_attacking, int* left_defending);
};
#endif
