#include "structure.h"
#include <algorithm>
#include "static_structure.h"

Structure::Structure(StaticStructure *ststructure)
{
    m_ststructure_ptr = ststructure;
    m_hull = ststructure->get_hull();
    m_shield = ststructure->get_shield();

    m_exploded = false;
}

bool Structure::check_if_explodes()
{
    const int threshold = static_cast<double>(0.7 * m_ststructure_ptr->get_hull());
    
    if (m_hull < threshold)
    {
        if ((rand() % m_ststructure_ptr->get_hull() + 1) > m_hull)
        {
            m_exploded = true;
        }
    }
    return m_exploded;
}

bool Structure::prepare_for_new_round()
{
    check_if_explodes();

    if (m_exploded)
    {
        return true;
    }
    else
    {
        m_shield = m_ststructure_ptr->get_shield();
    }
}

int Structure::get_rapid_fire(Structure &another)
{
    return m_ststructure_ptr->get_rapid_fire(another.m_ststructure_ptr->get_id());
}

bool Structure::attack(Structure &another)
{
    const Structure::default_type another_default_hull = another.m_ststructure_ptr->get_hull();
    const Structure::default_type another_default_shield = another.m_ststructure_ptr->get_shield();
    int attack = m_ststructure_ptr->get_attack();
    bool will_shot_again = false;
    int rapid_fire = get_rapid_fire(another);
    int random_number = rand();

    if (rapid_fire && rapid_fire > (random_number % rapid_fire + 1))
    {
        will_shot_again = true;
    }

    if (attack <= 0.01 * static_cast<double>(another_default_shield))
    {
        return will_shot_again;
    }

    if (another.m_shield <= attack)
    {
        attack -= another.m_shield;
        another.m_shield = 0;
    }
    else
    {
        another.m_shield -= attack;
        return will_shot_again;
    }

    another.m_hull = std::max(another.m_hull - attack, 0);
    another.check_if_explodes();

    return will_shot_again;
}

