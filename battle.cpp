#include "Battle.h"
#include "vector.h"

void Battle::Battle()
{
  std::vector<Structure> attacking;
  std::vector<Structure> defending;
}

void Battle::add_structure(bool side, ID structure, int amount)
{
  if(side)
  {
    for (int i = 0; i < amount; i++)
    {
        attacking.push_back(structure);
    }
  }
  else
  {
    for (int i = 0; i < amount; i++)
    {
        defending.push_back(structure);
    }
  }
}

void Battle::simulate(){
  for (int i = 0; i < 6; i++)
  {
    if(attacking.lenght()*defending.lenght())
    {
      break;
    }
    for (Structure s: attacking)
    {
      bool can_attack = true;
      while(can_attack)
      {
        can_attack = s.attack(rand() % defending.length());
      }
    }
    for (Structure s: defending)
    {
      bool can_attack = true;
      while(can_attack)
      {
        can_attack = s.attack(rand() % attacking.length());
      }
    }
    for (int i = 0; i<attacking.size();i++)
    {
      if(attacking[i].is_exploding())
      {
        attacking.erase(attacking.begin()+i)
      }
    }
    for (int i = 0; i<defenging.size();i++)
    {
      if(defending[i].is_exploding())
      {
        defending.erase(defending.begin()+i)
      }
    }
  }
}
