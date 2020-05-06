#include <vector>
#include <stdlib.h>
#include "battle.h"
#include "structure.h"


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

    int ATT_WIN = 0;
    int DEF_WIN = 0;
    int DRAW = 0;

    for (Structure s : attacking )
    {
        temp_attacking.push_back(s);
    }

    for (Structure s : defending )
    {
        temp_defending.push_back(s);
    }

    for (int j = 0; j < iterations; j++)
    {
      for (int i = 0; i < MAX_ROUNDS; i++)
      {
          if (!(temp_attacking.size() * temp_defending.size()))
          {
              break;
          }

          for (Structure s : temp_attacking)
          {
              bool can_attack = true;
              while (can_attack)
              {
                  can_attack = s.attack(temp_defending.at(rand() % temp_defending.size()));
              }
          }

          for (Structure s : temp_defending)
          {
              bool can_attack = true;
              while (can_attack)
              {
                  can_attack = s.attack(temp_attacking.at(rand() % temp_attacking.size()));
              }
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
          ATT_WIN++;
          for (Structure s : attacking ){
              left_attacking.push_back(s);
          }
      }
      else if (!temp_defending.size() )
      {
          DEF_WIN++;
          for (Structure s : defending ){
              left_defending.push_back(s);
          }
      }
      else
      {
        DRAW++;
        for (Structure s : attacking ){
            left_attacking.push_back(s);
        }
        for (Structure s : defending ){
            left_defending.push_back(s);
        }
      }
    }

    cout<<"\n\n Attacker wins = "<<ATT_WIN;
    cout<<"\n Defender wins = "<<DEF_WIN;
    cout<<"\n Draws = "<<DRAW;
}
