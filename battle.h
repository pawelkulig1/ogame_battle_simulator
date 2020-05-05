#ifndef __BATTLE__H__
#define __BATTLE__H__
#include <vector>
#include "static_structure.h"
#include "structure.h"

class Battle
{
    std::vector<Structure> attacking;
    std::vector<Structure> defending;
    const int MAX_ROUNDS = 6;

public:
    enum Player 
    {
        DEFENDER = 0,
        ATTACKER = 1
    };
    
    Battle();
    void add_structure(Battle::Player player, Structure structure, int amount);
    void simulate();
};
#endif
