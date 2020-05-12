#include <vector>
#include <stdlib.h>
#include "battle.h"
#include "structure.h"
#include <iostream>
#include "random_number_generator.h"


Battle::Battle()
{
    for (int i = 0; i <25; i++){
        att_count_left[i] = 0;
        def_count_left[i] = 0;
    }
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

void Battle::count(std::vector<Structure> fleet, int* fleet_count)
{
    for (Structure s: fleet)
    {
        fleet_count[s.get_id()]++;
    }
}
void Battle::distance_calc(int galaxy, int system, int planet)
{
    if (galaxy)
    {
        distance = 20000 * galaxy;
    }

    else if (system)
    {
        distance = 2700 + 95 * system;
    }

    else
    {
        distance = 1000 + 5 * planet;
    }
}

resources Battle::profit(int* left_attacking, int* left_defending){
    resources fuel;
    resources debris_field;
    resources pillage;
    resources loses;

    int attacking_fleet[25];
    int defending_fleet[25];
    int attacking_loss[25];
    int defending_loss[25];
    int attacking_left[25];
    int defending_left[25];

    for ( int i = 0; i < 25; i++)
    {
        attacking_fleet[i] = 0;
        defending_fleet[i] = 0;
        attacking_loss[i] = 0;
        defending_loss[i] = 0;
        attacking_left[i] = left_attacking[i];
        defending_left[i] = left_defending[i];
    }

    count(attacking,attacking_fleet);
    count(defending,defending_fleet);

    for ( int i = 0; i < 25; i++)
    {
        defending_loss[i] = defending_fleet[i] - defending_left[i];
    }

    int att_cargo = 0;

    for ( int i = 0; i < 17 ; i++)
    {
        attacking_loss[i] = attacking_fleet[i] - attacking_left[i];
        //att_cargo += attacking_left[i] * cargo id(i)
        //loses += attacking_loss[i] * cost id(i)
        //debris_field += 0.3 * ( attacking_loss[i] + defenfing_loss[i]) * cost id(i);
    }

    //pillage = 0.5 * def_res * max( 1 , def_res / att_cargo);

    debris_field.deuter = 0;

    for (Structure s : attacking)
    {
        fuel.deuter += 1 + s.get_fuel_cons() * distance / 35000 * 4;//4 = (speed/100+1)^2
    }

    return debris_field + pillage - loses - fuel;
}

void Battle::simulate( int iterations)
{
    RandomNumberGenerator* generator = RandomNumberGenerator::get_instance();
    std::vector<Structure> left_attacking;
    std::vector<Structure> left_defending;

    int att_win = 0;
    int def_win = 0;
    int draw = 0;

    for (int game = 0; game < iterations; game++)
    {
    	std::vector<Structure> temp_attacking(attacking.begin(), attacking.end());
    	std::vector<Structure> temp_defending(defending.begin(), defending.end());
        //std::cout << "game: " << game << "\n";

        for (int round = 0; round < MAX_ROUNDS; round++)
        {
            //std::cout << "round: " << round << "\n";

            if (!(temp_attacking.size() * temp_defending.size()))
            {
                break;
            }

            for (Structure s : temp_attacking)
            {
                bool can_attack = true;
                while (can_attack)
                {
                    can_attack = s.attack(temp_defending.at(generator->get_rand_int(0, temp_defending.size())));
                }
            }

            for (Structure s : temp_defending)
            {
                bool can_attack = true;
                while (can_attack)
                {
                    can_attack = s.attack(temp_attacking.at(generator->get_rand_int(0, temp_attacking.size())));
                }
            }

            for (int i = temp_attacking.size()-1; i > -1 ; i--)
            {
                if (temp_attacking.at(i).prepare_for_new_round())
                {
                    temp_attacking.erase(temp_attacking.begin() + i);
                }
            }

            for (int i = temp_attacking.size()-1; i > -1; i--)
            {
                if (temp_defending.at(i).prepare_for_new_round())
                {
                    temp_defending.erase(temp_defending.begin() + i);
                }
            }
        }

        if ((!temp_attacking.size())&&(!temp_defending.size()))
        {
            draw++;
            for (Structure s : temp_attacking ){
                left_attacking.push_back(s);
            }
            for (Structure s : temp_defending ){
                left_defending.push_back(s);
            }
        }
        else if (!temp_defending.size())
        {
            att_win++;
            for (Structure s : temp_attacking ){
                left_attacking.push_back(s);
            }
        }
        else
        {
            def_win++;
            for (Structure s : temp_defending ){
                left_defending.push_back(s);
            }
        }
    }

    std::cout<<"\n Attacker wins = "<<att_win;
    std::cout<<"\n Defender wins = "<<def_win;
    std::cout<<"\n draws = "<<draw;
    std::cout<<"\n\n";

    int attacker[25];
    int defender[25];

    for( int i = 0; i < 25; i++)
    {
        attacker[i] = 0;
        defender[i] = 0;
    }

    count(attacking, attacker);
    count(defending, defender);
    std::cout<<" Initial count:\n Structure | Attacker | Defender\n";

    for( int i = 0; i < 25; i++ )
    {
        if (attacker[i]||defender[i])
        {
            std::cout<<"      "<<i<<"   |   "<<attacker[i]<<"   |   "<<defender[i]<<'\n';
        }
    }

    for( int i = 0; i < 25; i++)
    {
        attacker[i] = 0;
        defender[i] = 0;
    }

    count(left_attacking, attacker);
    count(left_defending, defender);

    std::cout<<"\n Afterwards count:\n Structure | Attacker | Defender\n";

    for( int i = 0; i < 25; i++ )
    {
        if (attacker[i] || defender[i])
        {
            std::cout<<"      "<<i<<"   |   "<<double(attacker[i])/iterations<<"   |   "<<double(defender[i])/iterations<<'\n';
        }
    }
    std::cout<<'\n';

}
