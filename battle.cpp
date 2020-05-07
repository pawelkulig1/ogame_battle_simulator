#include <vector>
#include <stdlib.h>
#include "battle.h"
#include "structure.h"
#include <iostream>


Battle::Battle()
{
}

void Battle::add_structure(Battle::Player player, Structure structure, int amount)
{
    for (int i=0; i<amount; ++i) //would it be more efficient to do checking player before for loop?
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

void Battle::simulate( int iterations)
{
    std::vector<Structure> temp_attacking;
    std::vector<Structure> temp_defending;

    std::vector<Structure> left_attacking;
    std::vector<Structure> left_defending;

    int att_win = 0;
    int def_win = 0;
    int draw = 0;

    for (int j = 0; j < iterations; j++)
    {
        temp_attacking.clear();
        temp_defending.clear();

        for (Structure s : attacking )
        {
            temp_attacking.push_back(s);
        }

        for (Structure s : defending )
        {
            temp_defending.push_back(s);
        }

        for (int i = 0; i < MAX_ROUNDS; i++)
        {
          if (!(temp_attacking.size() * temp_defending.size()))
          {
              break;
          }

          for (Structure s : temp_attacking)
          {
              bool can_attack = true;
              /*
              while (can_attack)
              {
                  can_attack = s.attack(temp_defending.at(rand() % temp_defending.size()));
              }
              */
          }

          for (Structure s : temp_defending)
          {
              bool can_attack = true;
              /*
              while (can_attack)
              {
                  can_attack = s.attack(temp_attacking.at(rand() % temp_attacking.size()));
              }
              */
          }

          for (int i = 0; i < temp_attacking.size(); i++)
          {
              if (temp_attacking.at(i).is_exploding())
              {
                  temp_attacking.erase(temp_attacking.begin() + i);
              }
          }

          for (int i = 0; i < temp_defending.size(); i++)
          {
              if (temp_defending.at(i).is_exploding())
              {
                  temp_defending.erase(temp_defending.begin() + i);
              }
          }
      }
      if (!temp_attacking.size() )
      {
          att_win++;
          for (Structure s : attacking ){
              left_attacking.push_back(s);
          }
      }
      else if (!temp_defending.size() )
      {
          def_win++;
          for (Structure s : defending ){
              left_defending.push_back(s);
          }
      }
      else
      {
        draw++;
        for (Structure s : attacking ){
            left_attacking.push_back(s);
        }
        for (Structure s : defending ){
            left_defending.push_back(s);
        }
      }
    }

    std::cout<<"\n\n Attacker wins = "<<att_win;
    std::cout<<"\n Defender wins = "<<def_win;
    std::cout<<"\n draws = "<<draw;
}
