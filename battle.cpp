#include <vector>
#include <stdlib.h>
#include "battle.h"
#include "structure.h"


Battle::Battle()
{
}

void Battle::add_structure(Battle::Player player, Structure structure, int amount)
{
    for (int i=0; i<amount; ++i)
    {
        if (player) 
        {
            attacking.push_back(structure);
        }
        else 
        {
            defending.push_back(structure);
        }
    }
}

void Battle::simulate()
{
    for (int i = 0; i < MAX_ROUNDS; i++)
    {
        if (attacking.size() * defending.size())
        {
            break;
        }

        for (Structure s : attacking)
        {
            bool can_attack = true;
            while (can_attack)
            {
                can_attack = s.attack(defending.at(rand() % defending.size()));
            }
        }

        for (Structure s : defending)
        {
            bool can_attack = true;
            while (can_attack)
            {
                can_attack = s.attack(attacking.at(rand() % attacking.size()));
            }
        }

        for (int i = 0; i < attacking.size(); i++)
        {
            if (attacking.at(i).is_exploding())
            {
                attacking.erase(attacking.begin() + i);
            }
        }

        for (int i = 0; i < defending.size(); i++)
        {
            if (defending.at(i).is_exploding())
            {
                defending.erase(defending.begin() + i);
            }
        }
    }
}
